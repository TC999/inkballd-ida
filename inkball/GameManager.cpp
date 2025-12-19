// C++重写 CGameManager 构造函数
#include "CGameManager.h"
#include "CGameBoard.h"
#include "Helpers.h"
#include <memory>
#include <stdexcept>
#include <mmsystem.h>

extern CGameBoard* g_pCGameBoard;

CGameManager::CGameManager(HWND hwnd)
    : gameBoard_(nullptr), startTime_(timeGetTime()), state1_(0), state2_(0), state3_(0), state4_(0)
{
    Helpers::CLogBlock log("CGameManager::CGameManager");
    g_pCGameBoard = nullptr;
    try {
        gameBoard_ = std::make_unique<CGameBoard>(hwnd);
        g_pCGameBoard = gameBoard_.get();
    } catch (const std::bad_alloc&) {
        if (g_pCGameBoard) {
            delete g_pCGameBoard;
            g_pCGameBoard = nullptr;
        }
        throw;
    }
}
