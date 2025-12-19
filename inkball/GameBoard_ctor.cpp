// C++重写 CGameBoard 构造函数
#include "CGameBoard.h"
#include "CBallManager.h"
#include "CScoreManager.h"
#include "CTileManager.h"
#include "CTimeManager.h"
#include "CInk.h"
#include "CDisplay.h"
#include "CSurface.h"
#include "Helpers.h"
#include "CRegistryManager.h"
#include <memory>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

extern CSurface* g_pGamePiecesSurface;
extern CDisplay* g_pDisplay;
extern CRegistryManager g_CRegistryManager;
extern RECT g_rcClient;
extern HWND g_hWnd;
extern int dword_4B8E90, dword_4B8E94, dword_4B8EA0, dword_4B8EA4, dword_4B8E9C;
extern double dSizeFactor;

CGameBoard::CGameBoard(HWND hwnd)
    : hwnd_(hwnd),
      ballManager_(nullptr),
      scoreManager_(nullptr),
      tileManager_(nullptr),
      timeManager_(nullptr),
      ink_(nullptr)
{
    Helpers::CLogBlock log("CGameBoard::CGameBoard");
    dSizeFactor = 1.0;
    // 初始化成员变量和内存块（略，实际应按成员变量定义初始化）
    // ...
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    if (InitDirectDraw() < 0) {
        throw std::bad_alloc();
    }
    if (CDisplay::CreateSurfaceFromBitmap(g_pDisplay, &g_pGamePiecesSurface, reinterpret_cast<const unsigned short*>(0x1F5), 0x17D, 0x190) < 0) {
        throw std::bad_alloc();
    }
    CSurface::SetColorKey(g_pGamePiecesSurface, 0xFF00FFu);
    try {
        ink_ = std::make_unique<CInk>();
        Helpers::GetClientRect(hwnd, &g_rcClient, 0, nullptr);
        dword_4B8E90 = 10 * (dword_4B8EA0 - g_rcClient.left); // 假设unused为left
        dword_4B8E94 = 10 * (dword_4B8EA4 - dword_4B8E9C);
        g_hWnd = hwnd;
        ballManager_ = std::make_unique<CBallManager>();
        scoreManager_ = std::make_unique<CScoreManager>();
        tileManager_ = std::make_unique<CTileManager>();
        timeManager_ = std::make_unique<CTimeManager>();
    } catch (const std::bad_alloc&) {
        ink_.reset();
        ballManager_.reset();
        scoreManager_.reset();
        tileManager_.reset();
        timeManager_.reset();
        throw;
    }
}
