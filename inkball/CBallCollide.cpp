// C++重写并合并 CBall::Collide 两种重载
#include "CBall.h"
#include "Helpers.h"
#include <cmath>

// 球与球碰撞
unsigned int CBall::Collide(CBall* other) {
    Helpers::CLogBlock log("CBall::Collide");
    // 判断是否相交
    double r1 = this->radius * 0.5;
    double r2 = other->radius * 0.5;
    double dx = this->posX - other->posX;
    double dy = this->posY - other->posY;
    bool intersect = (r1 + r2 > std::sqrt(dx * dx + dy * dy));
    if (intersect) {
        // 判断是否运动方向相向
        double towards = (other->posY - this->posY) * this->velY + (other->posX - this->posX) * this->velX;
        if (towards > 0.0) {
            double v1 = r1 + this->posY - (r2 + other->posY);
            double v2 = r1 + this->posX - (r2 + other->posX);
            double dist = std::sqrt(v2 * v2 + v1 * v1);
            double normX = v2 / dist;
            double normY = v1 / dist;
            double totalMass = this->mass + other->mass;
            double impulse = (this->velX * normX + this->velY * normY - (normY * other->velY + normX * other->velX)) * 2.0 / totalMass;
            this->velX -= other->mass * impulse * normX;
            this->velY -= impulse * other->mass * normY;
            other->velX += this->mass * impulse * normX;
            other->velY += impulse * this->mass * normY;
            this->collisionFlags[other->id] = 1;
            other->collisionFlags[this->id] = 1;
            return 1;
        }
    }
    this->collisionFlags[other->id] = 0;
    other->collisionFlags[this->id] = 0;
    return 0;
}

// 球与区域碰撞（如墨迹检测）
unsigned int CBall::Collide(int (*hitTest)(const RECT&)) {
    Helpers::CLogBlock log("CBall::Collide");
    this->InitBallPoints();
    int prevIdx = -1, lastIdx = -1, hit = 0;
    POINT center = this->GetCenterPoint();
    BallPoint* pt = this->GetNextPoint();
    if (!pt) return 0;
    do {
        RECT rect;
        rect.left = rect.right = center.x + pt->x;
        rect.top = rect.bottom = center.y + pt->y;
        if (hitTest(rect)) {
            if (prevIdx == -1) {
                prevIdx = this->GetPrevBallPoint();
                lastIdx = prevIdx;
            } else {
                lastIdx = this->GetPrevBallPoint();
            }
            hit = 1;
        }
        pt = this->GetNextPoint();
    } while (pt);
    if (hit) {
        int mid = (lastIdx + prevIdx) / 2;
        if (lastIdx < prevIdx) mid = (mid + 16) % 32;
        int* deflectPt = this->GetPoint(mid);
        this->Deflect(static_cast<double>(deflectPt[0]), static_cast<double>(deflectPt[1]));
        return 1;
    }
    return 0;
}
