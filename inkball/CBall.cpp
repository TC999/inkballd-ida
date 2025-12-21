// C++重写 CBall 构造函数
#include "CBall.h"
#include "BallPoints.h"
#include "CGameBoard.h"
#include "Helpers.h"
#include <memory>
#include <stdexcept>

CBall::CBall(void* rect, int color, int addToList, int unused, int radius)
    : CMovingObject(), color_(color), radius_(radius) {
    Helpers::CLogBlock log("CBall::CBall");
    try {
        points_ = std::make_unique<BallPoints>(radius);
    } catch (const std::bad_alloc&) {
        // 日志略，实际可调用WPP_SF_等
        throw;
    }
    this->someField1 = -1;
    this->someField2 = 0;
    this->someField3 = 32;
    this->someField4 = 0;
    this->rect_ = rect;
    this->radius_ = radius;
    // 其它成员初始化
    for (int i = 0; i < 64; ++i) this->array_[i] = 0;
    if (addToList) {
        Helpers::CLogBlock logAdd("AddBallToUpdateList");
        if (g_pCGameBoard && g_pCGameBoard->ballCount < 64) {
            g_pCGameBoard->balls[g_pCGameBoard->ballCount++] = this;
        }
    }
}
