// C++重写 CGameBoard 析构函数
#include "CGameBoard.h"
#include "CBallManager.h"
#include "CScoreManager.h"
#include "CRegistryManager.h"
#include "Helpers.h"
#include "CSurface.h"
#include "CDisplay.h"
#include "CInk.h"
#include <memory>

// 假设全局变量和其它依赖已在头文件声明
extern CSurface* g_pGamePiecesSurface;
extern CSurface* g_pTimeManagerSurface;
extern CSurface* g_pBallManagerSurface;
extern CSurface* g_pTileManagerSurface;
extern CSurface* g_pScoreManagerSurface;
extern CDisplay* g_pDisplay;
extern CRegistryManager g_CRegistryManager;

CGameBoard::~CGameBoard() {
    Helpers::CLogBlock log("CGameBoard::~CGameBoard");
    // BallManager
    if (ballManager_) {
        Helpers::CLogBlock logBall("CBallManager::~CBallManager");
        for (auto& ball : ballManager_->balls) {
            if (ball) {
                ball->Release();
                ball = nullptr;
            }
        }
        // ballManager_为unique_ptr自动释放
    }
    // ScoreManager
    if (scoreManager_) {
        Helpers::CLogBlock logScore("CScoreManager::~CScoreManager");
        CRegistryManager::WriteHiScore(&g_CRegistryManager, scoreManager_->GetHiScore());
        // scoreManager_为unique_ptr自动释放
    }
    // 其它成员资源
    // 直接用unique_ptr或shared_ptr管理即可自动释放
    // 全局Surface资源
    if (g_pGamePiecesSurface) {
        g_pGamePiecesSurface->~CSurface();
        delete g_pGamePiecesSurface;
        g_pGamePiecesSurface = nullptr;
    }
    Helpers::CLogBlock logFreeDD("CGameBoard::FreeDirectDraw");
    if (g_pTimeManagerSurface) {
        g_pTimeManagerSurface->~CSurface();
        delete g_pTimeManagerSurface;
        g_pTimeManagerSurface = nullptr;
    }
    if (g_pBallManagerSurface) {
        g_pBallManagerSurface->~CSurface();
        delete g_pBallManagerSurface;
        g_pBallManagerSurface = nullptr;
    }
    if (g_pTileManagerSurface) {
        g_pTileManagerSurface->~CSurface();
        delete g_pTileManagerSurface;
        g_pTileManagerSurface = nullptr;
    }
    if (g_pScoreManagerSurface) {
        g_pScoreManagerSurface->~CSurface();
        delete g_pScoreManagerSurface;
        g_pScoreManagerSurface = nullptr;
    }
    // Display
    if (g_pDisplay) {
        Helpers::CLogBlock logDisplay("CDisplay::~CDisplay");
        g_pDisplay->DestroyObjects();
        delete g_pDisplay;
        g_pDisplay = nullptr;
    }
    // Ink
    if (ink_) {
        delete ink_;
        ink_ = nullptr;
    }
}
