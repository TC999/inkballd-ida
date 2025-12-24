// C++重写并合并 UpdateObject 相关函数
#include "CBall.h"
#include "CBallManager.h"
#include "CBoardTileRLColored.h"
#include "CBoardTileRLGray.h"
#include "CTimeManager.h"
#include "Helpers.h"
#include <algorithm>

// CBall::UpdateObject
void CBall::UpdateObject(int deltaMs) {
    Helpers::CLogBlock log("CBall::UpdateObject");
    if (this->active) {
        double dt = static_cast<double>(deltaMs) / 1000.0;
        this->lastPosX = this->posX;
        this->lastPosY = this->posY;
        this->posX += dt * this->velX;
        this->posY += dt * this->velY;
        if (!this->CheckBoardBounds()) {
            {
                Helpers::CLogBlock log2("CBall::AddRef");
                ++this->refCount;
            }
            CheckForBallCollisionWithNonDeflectingTile(this);
            if (static_cast<int>(this->posX) != static_cast<int>(this->lastPosX) || static_cast<int>(this->posY) != static_cast<int>(this->lastPosY)) {
                {
                    Helpers::CLogBlock log2("CheckForBallCollisionWithBall");
                    auto* board = g_pCGameBoard;
                    for (int i = 0; i < board->NumBallsOnBoard(); ++i) {
                        if (i != this->id) {
                            CBall* other = board->GetBall(i);
                            if (other->active)
                                this->Collide(other);
                        }
                    }
                }
                CheckForBallCollisionWithInk(this);
                CheckForBallCollisionWithTile(this);
            }
            this->Release();
        }
    }
}

// CBallManager::UpdateObject
void CBallManager::UpdateObject(int deltaMs) {
    Helpers::CLogBlock log("CBallManager::UpdateObject");
    if (this->needInit) {
        this->UpdateBallList();
        {
            Helpers::CLogBlock log2("CBallManager::InitBallPositions");
            // 伪代码：初始化球位置
            // ...
        }
        this->needInit = false;
    }
    if (this->pendingLaunches <= 0) {
        Helpers::CLogBlock log2("StartTimer");
        g_pCGameBoard->timerActive = true;
    } else {
        this->UpdateBallPositions(deltaMs);
        this->launchTimer -= deltaMs;
        if (this->launchTimer <= 800) {
            this->launchAnimTime += deltaMs;
            if (this->launchAnimTime >= 100) {
                this->launchAnimFlag = !this->launchAnimFlag;
                this->launchAnimTime = 0;
            }
        }
        if (this->launchTimer <= 0 && this->numLaunchers > 0) {
            Helpers::CLogBlock log2("CBallManager::GetRandomBallLauncher");
            auto* launcher = this->GetRandomBallLauncher();
            if (BallOnTile(launcher)) {
                this->launchTimer = 0;
            } else {
                int idx = this->nextBallIdx++;
                Helpers::CLogBlock log3("GetBall");
                CBall* ball = g_pCGameBoard->GetBall(idx);
                Helpers::CLogBlock log4("CBallManager::SetBallOnLauncher");
                if (this->numLaunchers) {
                    POINT pt = launcher->GetCenterPoint();
                    int r = ball->radius / 2;
                    ball->posX = static_cast<double>(pt.x - r);
                    ball->posY = static_cast<double>(pt.y - r);
                }
                this->SetBallSpeed(ball, -1.0);
                ball->flag44 = 1;
                ball->active = 1;
                --this->pendingLaunches;
                this->launchTimer = this->launchInterval;
                this->launchAnimFlag = 0;
                this->UpdateBallList();
                if (!this->hasStarted) {
                    this->hasStarted = true;
                    Helpers::CLogBlock log5("StartTimer");
                    g_pCGameBoard->timerActive = true;
                }
            }
        }
    }
    this->OnUpdate();
}

// CBoardTileRLColored::UpdateObject
void CBoardTileRLColored::UpdateObject(int deltaMs) {
    Helpers::CLogBlock log("CBoardTileRLColored::UpdateObject");
    int oldState = this->state;
    this->timer += deltaMs;
    if (this->mode) {
        if (this->mode == 1) {
            if (!BallOnTile(this)) {
                this->mode = 2;
                this->timer = 0;
            }
        } else if (oldState < 4 && this->timer > 50) {
            this->state = oldState + 1;
            this->timer = 0;
        }
    } else if (oldState > 0 && this->timer > 50) {
        this->state = oldState - 1;
        this->timer = 0;
    }
    if (this->state != oldState) {
        this->bitmap = GetBitmapRect(5 * this->state + this->color + 77);
        UpdateBoardTile(this);
        ShadowizeTile(this);
    }
}

// CBoardTileRLGray::UpdateObject
void CBoardTileRLGray::UpdateObject(int deltaMs) {
    Helpers::CLogBlock log("CBoardTileRLGray::UpdateObject");
    int oldState = this->state;
    this->timer += deltaMs;
    this->timer2 += deltaMs;
    if (this->mode) {
        if (this->mode == 1) {
            if (this->timer <= this->limit1) {
                if (!BallOnTile(this)) {
                    this->mode = 2;
                    this->timer = 0;
                    this->timer2 = 0;
                }
            } else {
                this->mode = 0;
                this->timer = 0;
            }
        } else if (this->timer >= this->limit1) {
            this->mode = 0;
            this->timer = 0;
            this->timer2 = 0;
        } else if (oldState < 4 && this->timer2 > 50) {
            this->state = oldState + 1;
            this->timer2 = 0;
        }
    } else if (this->timer >= this->limit2) {
        this->mode = 1;
        this->timer = 0;
    } else if (oldState > 0 && this->timer2 > 50) {
        this->state = oldState - 1;
        this->timer2 = 0;
    }
    if (this->state != oldState) {
        this->bitmap = GetBitmapRect(5 * this->state + 77);
        UpdateBoardTile(this);
        ShadowizeTile(this);
    }
}

// CTimeManager::UpdateObject
void CTimeManager::UpdateObject(unsigned int deltaMs) {
    Helpers::CLogBlock log("CTimeManager::UpdateObject");
    int flag = 0;
    if (this->active) {
        if (this->timeoutFlag) {
            KillPlayer(0);
        } else {
            if (this->timeLeft != -1) {
                if (this->timeLeft > deltaMs) {
                    this->timeLeft -= deltaMs;
                    if (this->timeLeft < 0x2AF8) {
                        this->timer1 += deltaMs;
                        this->timer2 += deltaMs;
                        if (this->timer1 >= 333) {
                            this->timer1 = 0;
                            flag = 1;
                            this->toggleFlag = !this->toggleFlag;
                        }
                        if (this->timer2 >= 1000)
                            this->timer2 = 0;
                    }
                } else {
                    this->timeLeft = 0;
                    this->toggleFlag = 1;
                }
            }
        }
        if (this->timeLeft >= 1000 || this->timeoutFlag) {
            this->timeoutFlag = 0;
            if (flag != 1 && this->timeLeft / 1000 == dword_464ADC / 1000)
                goto skip;
        } else {
            this->toggleFlag = 1;
            this->timeoutFlag = 1;
        }
        this->OnUpdate();
    skip:
        dword_464ADC = this->timeLeft;
    }
}
