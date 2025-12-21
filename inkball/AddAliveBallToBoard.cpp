// C++重写并合并 AddAliveBallToBoard 及异常catch逻辑
#include "CGameBoard.h"
#include "CBall.h"
#include "CBallManager.h"
#include "CBoardTile.h"
#include "Helpers.h"
#include <memory>
#include <stdexcept>

// 异常catch辅助（原catch_0逻辑）
namespace AddAliveBallToBoardHelpers {
    void HandleBadAlloc(CBall* ball) {
        if (ball) {
            ball->errorCode = -2147024882; // E_OUTOFMEMORY
        }
        // 可扩展日志等
    }
}

// 主函数
int AddAliveBallToBoard(int color, CBoardTile* tile, double speed) {
    Helpers::CLogBlock log("AddAliveBallToBoard");
    auto* board = g_pCGameBoard;
    if (!board) return 2147942414; // ERROR_INVALID_HANDLE
    if (board->NumBallsOnBoard() >= 64) {
        DisplayBoardLoadMsg();
    }
    POINT center = tile->GetCenterPoint();
    std::unique_ptr<CBall> ball;
    try {
        auto rect = board->GetBitmapRect(color + 2);
        ball = std::make_unique<CBall>(rect, color, true, board->tileSize);
    } catch (const std::bad_alloc&) {
        AddAliveBallToBoardHelpers::HandleBadAlloc(ball.get());
        return 2147942414; // ERROR_OUTOFMEMORY
    }
    if (ball) {
        ball->AddRef();
        ball->field24 = board->tileSize;
        ball->field28 = board->tileSize;
        ball->posX = static_cast<double>(center.x) - board->tileSize * 0.5;
        ball->posY = static_cast<double>(center.y) - board->tileSize * 0.5;
        board->ballManager->SetBallSpeed(ball.get(), speed);
        ball->field172 = 1;
        ball->field176 = 1;
        board->AddBall(ball.get());
        return 0;
    } else {
        AddAliveBallToBoardHelpers::HandleBadAlloc(ball.get());
        return 2147942414;
    }
}
