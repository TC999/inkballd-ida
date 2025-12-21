// C++重写 BallPoints 构造函数
#include "BallPoints.h"
#include "Helpers.h"
#include <cmath>
#include <memory>
#include <stdexcept>

// 假设cosd和sind为角度制三角函数
inline double cosd(double deg) { return std::cos(deg * M_PI / 180.0); }
inline double sind(double deg) { return std::sin(deg * M_PI / 180.0); }

BallPoints::BallPoints(int radius) {
    Helpers::CLogBlock log("BallPoints::BallPoints");
    double r = radius * 0.5;
    try {
        points_.resize(32); // 32个点
    } catch (const std::bad_alloc&) {
        // 日志略，实际可调用WPP_SF_等
        throw;
    }
    // 计算圆周上的点
    for (int i = 0; i < 16; ++i) {
        double angle = 11.25 * i;
        points_[i].x = static_cast<int>(-cosd(angle) * r);
        points_[i].y = static_cast<int>(-sind(angle) * r);
    }
    // 其余16个点为对称点
    for (int i = 0; i < 16; ++i) {
        points_[i + 16].x = -points_[i].x;
        points_[i + 16].y = -points_[i].y;
    }
    // 其它属性可根据需要补充
}
