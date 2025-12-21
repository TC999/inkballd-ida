// C++重写 AddBallToBoard 及异常catch处理
#include "CBall.h"
#include "CGameBoard.h"
#include "Helpers.h"
#include <memory>
#include <stdexcept>

// 异常catch处理
void* AddBallToBoardCatch(int errorCode, void* context) {
    if (WPP_GLOBAL_Control != reinterpret_cast<void*>(&WPP_GLOBAL_Control) && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0) {
        LogHelper::WPP_SF_(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control)[2], static_cast<uint16_t>(11), qword_401918);
    }
    *reinterpret_cast<int*>(reinterpret_cast<char*>(context) + 120) = -2147024882;
    return reinterpret_cast<void*>(&loc_40D03C); // 占位
}

// AddBallToBoard主逻辑
int AddBallToBoard(int color) {
    Helpers::CLogBlock log("AddBallToBoard");
    try {
        auto bitmapRect = CGameBoard::GetBitmapRect(g_pCGameBoard, color + 2);
        auto ball = std::make_unique<CBall>(bitmapRect, color, 1, 0, g_pCGameBoard->ballRadius);
        if (ball) {
            Helpers::CLogBlock logAddRef("CBall::AddRef");
            ball->AddRef();
            ball->field6 = g_pCGameBoard->ballRadius;
            ball->field7 = g_pCGameBoard->ballRadius;
            ball->field43 = 0;
            ball->field44 = 0;
            g_pCGameBoard->AddBall(ball.get());
            return 0;
        } else {
            return 2147942414;
        }
    } catch (const std::bad_alloc&) {
        AddBallToBoardCatch(11, &log); // 传递日志对象指针作为context
        return 2147942414;
    }
}
