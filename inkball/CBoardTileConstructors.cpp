// C++重写 CBoardTile 构造函数（无参和多参）
#include "CBoardTile.h"
#include "Helpers.h"

// 无参构造函数
CBoardTile::CBoardTile() : CInk() {
    Helpers::CLogBlock logObj("CBoardObject::CBoardObject");
    this->ptr1 = nullptr;
    this->ptr2 = nullptr;
    this->ptr3 = nullptr;
    this->val1 = 0;
    this->val2 = 0;
    this->sizeX = 32;
    this->sizeY = 32;
    this->scaleX = 1.0;
    this->scaleY = 1.0;
    Helpers::CLogBlock logTile("CBoardTile::CBoardTile");
    this->tileType = 0;
}

// 多参数构造函数
CBoardTile::CBoardTile(int type, int x, int y, int extra, void* rect) : CInk() {
    Helpers::CLogBlock logObj("CBoardObject::CBoardObject");
    this->ptr1 = nullptr;
    this->ptr2 = nullptr;
    this->ptr3 = rect;
    this->val1 = 0;
    this->val2 = 0;
    this->sizeX = 32;
    this->sizeY = 32;
    this->scaleX = 1.0;
    this->scaleY = 1.0;
    Helpers::CLogBlock logTile("CBoardTile::CBoardTile");
    this->tileType = type;
    this->x = x;
    this->y = y;
    this->extra = extra;
}
