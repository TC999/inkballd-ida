// C++重写并合并 CareAboutCollisions 相关函数
#include "CBoardTile.h"
#include "CBoardTileBumper.h"
#include "CBoardTileOWF.h"
#include "CBoardTileRLColored.h"
#include "CBoardTileRLGray.h"
#include "CBall.h"
#include "Helpers.h"

// CBoardTile::CareAboutCollisions
bool CBoardTile::CareAboutCollisions(const CBall* ball) {
    Helpers::CLogBlock log("CBoardTile::CareAboutCollisions");
    return ball->field152 != 0;
}

// CBoardTileBumper::CareAboutCollisions
int CBoardTileBumper::CareAboutCollisions(const CBoardObject* obj1, const CBoardObject* obj2, const int* pt) {
    Helpers::CLogBlock log("CBoardTileBumper::CareAboutCollisions");
    // 还原原始逻辑
    // 伪代码：假设有GetCenterPoint、GetBoundingRect、PointInRect等辅助函数
    POINT center1, center2;
    RECT rect;
    obj1->GetCenterPoint(&center1);
    obj2->GetCenterPoint(&center2);
    obj1->GetBoundingRect(&rect);
    int result = 2;
    int shrink = obj1->size / 3;
    if (obj1->type) {
        if (obj1->type != 2)
            goto skip;
        int color1 = obj1->color;
        int color2 = obj2->color;
        if (!color1 || color1 == color2)
            goto skip;
        if (!pt)
            goto end;
        rect.left += shrink;
        rect.right -= shrink;
        goto check_point;
    }
    int color1 = obj1->color;
    int color2 = obj2->color;
    if (!color1 || color1 == color2)
        goto skip;
    if (pt) {
        rect.top += shrink;
        rect.bottom -= shrink;
check_point:
        if (!PointInRect(pt[0], pt[1], rect))
skip:
            result = 0;
    }
end:
    return result;
}

// CBoardTileOWF::CareAboutCollisions
int CBoardTileOWF::CareAboutCollisions(const int* obj1, const CBoardObject* obj2, const int* pt) {
    Helpers::CLogBlock log("CBoardTileOWF::CareAboutCollisions");
    // 还原原始逻辑
    POINT center1, center2;
    RECT rect;
    reinterpret_cast<const CBoardObject*>(obj1)->GetCenterPoint(&center1);
    obj2->GetCenterPoint(&center2);
    reinterpret_cast<const CBoardObject*>(obj1)->GetBoundingRect(&rect);
    int type = obj1[24];
    int result = 2;
    int shrink = static_cast<int>(obj1[6] / 1.6);
    if (!type) {
        rect.bottom -= shrink;
        if (center2.y < (rect.bottom + rect.top) / 2) {
            double vy = *reinterpret_cast<const double*>(reinterpret_cast<const char*>(obj2) + 80);
            if (vy > 0.0)
                goto skip;
        }
        goto check_color;
    }
    if (type == 1) {
        rect.top += shrink;
        if (center2.y <= (rect.top + rect.bottom) / 2)
            goto check_color;
        double vy = *reinterpret_cast<const double*>(reinterpret_cast<const char*>(obj2) + 80);
        if (vy < 0.0)
            goto skip;
        goto check_color;
    }
    if (type == 2) {
        rect.right -= shrink;
        if (center2.x < (rect.right + rect.left) / 2) {
            double vx = *reinterpret_cast<const double*>(reinterpret_cast<const char*>(obj2) + 72);
            if (vx > 0.0)
                goto skip;
        }
        goto check_color;
    }
    if (type == 3) {
        rect.left += shrink;
        if (center2.x <= (rect.left + rect.right) / 2)
            goto check_color;
        double vx = *reinterpret_cast<const double*>(reinterpret_cast<const char*>(obj2) + 72);
        if (vx < 0.0)
            goto skip;
        goto check_color;
    }
skip:
    result = 0;
check_color:
    int color1 = obj1[12];
    int color2 = *reinterpret_cast<const int*>(reinterpret_cast<const char*>(obj2) + 48);
    if (!color1 || color1 == color2 || (pt && !PointInRect(pt[0], pt[1], rect)))
        result = 0;
    return result;
}

// CBoardTileRLColored::CareAboutCollisions
int CBoardTileRLColored::CareAboutCollisions() {
    Helpers::CLogBlock log("CBoardTileRLColored::CareAboutCollisions");
    return this->field80 > 0 ? 2 : 0;
}

// CBoardTileRLGray::CareAboutCollisions
int CBoardTileRLGray::CareAboutCollisions() {
    Helpers::CLogBlock log("CBoardTileRLGray::CareAboutCollisions");
    return this->field80 > 0 ? 2 : 0;
}
