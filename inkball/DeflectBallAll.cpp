// 合并并重写 DeflectBall 及 CBall::Deflect 为 C++ 风格
#include "CBoardTile.h"
#include "CBoardTileWall.h"
#include "CBoardTileBreakWall.h"
#include "CBoardTileBumper.h"
#include "CBoardTileChevron.h"
#include "CBoardTileDrain.h"
#include "CBoardTileOWF.h"
#include "CBoardTileRLColored.h"
#include "CBoardTileRLGray.h"
#include "CBall.h"
#include "CScoreManager.h"
#include "CGameBoard.h"
#include "Helpers.h"
#include <cmath>

// CBall::Deflect
void CBall::Deflect(double a2, double a3) {
    Helpers::CLogBlock log("CBall::Deflect");
    double vx = this->vx; // 假设vx, vy为成员
    double vy = this->vy;
    double v = (vy * a3 + vx * a2) * 2.0 / (a2 * a2 + a3 * a3);
    this->vy = vy - v * a3;
    this->vx = vx - v * a2;
}

// CBoardTile::DeflectBall
void CBoardTile::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTile::DeflectBall");
    ball->SetTallness(0);
}

// CBoardTileWall::DeflectBall
void CBoardTileWall::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileWall::DeflectBall");
    int color = this->color; // 假设color为成员
    if (color) {
        Helpers::CLogBlock log2("SetBallColor");
        ball->color = color;
        ball->bitmapRect = CGameBoard::GetBitmapRect(g_pCGameBoard, color + 2);
    }
    PerformStandardWallDeflection(this, ball);
}

// CBoardTileBreakWall::DeflectBall
void CBoardTileBreakWall::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileBreakWall::DeflectBall");
    PerformStandardWallDeflection(this, ball);
    int color = this->color;
    if (!color || color == ball->color) {
        ConvertTileToFloor(this);
        {
            Helpers::CLogBlock logScore("ScoreBreak");
            Helpers::CLogBlock logPoints("CBall::GetBreakWallPoints");
            int points = BreakPoints[ball->color];
            CScoreManager::IncrementScore(g_pCGameBoard->scoreManager, points);
        }
    }
}

// CBoardTileBumper::DeflectBall
void CBoardTileBumper::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileBumper::DeflectBall");
    PerformStandardWallDeflection(this, ball);
}

// CBoardTileChevron::DeflectBall
void CBoardTileChevron::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileChevron::DeflectBall");
    int dir = this->direction; // 假设direction为成员
    switch (dir) {
        case 0:
            ball->vy -= 3.0;
            break;
        case 1:
            ball->vy += 3.0;
            break;
        case 2:
            ball->vx -= 3.0;
            break;
        case 3:
            ball->vx += 3.0;
            break;
    }
    // 限制速度
    if (std::abs(ball->vx) > 400.0) ball->vx = (ball->vx > 0 ? 1 : -1) * 400.0;
    if (std::abs(ball->vy) > 400.0) ball->vy = (ball->vy > 0 ? 1 : -1) * 400.0;
}

// CBoardTileDrain::DeflectBall
void CBoardTileDrain::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileDrain::DeflectBall");
    RECT rect;
    this->GetBoundingRect(&rect);
    int type = this->type; // 假设type为成员
    int right = (type == 2 || type == 4) ? rect.right : rect.left;
    int bottom = (type == 2 || type == 3) ? rect.bottom : rect.top;
    POINT center;
    ball->GetCenterPoint(&center);
    int dx = center.x - right;
    int dy = center.y - bottom;
    double dist = std::sqrt(dx * dx + dy * dy);
    int v10 = (dist > 42.0) ? ball->color + 2 : ball->color + 7;
    ball->bitmapRect = &g_CBitmapRects[4 * v10];
    if (ball->radius * 0.5 + dist > 12.0) {
        if (dist <= 32.0) {
            double inv = 1.0 / (dist * dist);
            ball->vx = ball->vx * 0.993 - dx * inv * 25.0;
            ball->vy = ball->vy * 0.993 - dy * inv * 25.0;
            int tall = Round(-3.0 / dist * 8.0);
            ball->SetTallness(tall);
        }
    } else {
        int color = this->color;
        if (color != ball->color && color && ball->color) {
            KillPlayer(1);
        } else {
            ScoreBall(ball);
            ball->someFlag = 0;
            if (color && ball->color) ToggleRLWalls(color);
        }
    }
}

// CBoardTileOWF::DeflectBall
void CBoardTileOWF::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileOWF::DeflectBall");
    PerformStandardWallDeflection(this, ball);
}

// CBoardTileRLColored::DeflectBall
void CBoardTileRLColored::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileRLColored::DeflectBall");
    PerformStandardWallDeflection(this, ball);
}

// CBoardTileRLGray::DeflectBall
void CBoardTileRLGray::DeflectBall(CBall* ball) {
    Helpers::CLogBlock log("CBoardTileRLGray::DeflectBall");
    PerformStandardWallDeflection(this, ball);
}
