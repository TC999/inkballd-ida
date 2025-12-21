// 合并并重写 CBoardTile 及其 RL 派生类构造函数为 C++ 风格
#include "CBoardTile.h"
#include "CBoardTileRLColored.h"
#include "CBoardTileRLGray.h"
#include "CGameBoard.h"
#include "Helpers.h"

// CBoardTile 默认构造函数
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

// CBoardTile 带参数构造函数
CBoardTile::CBoardTile(int type, int x, int y, RECT* rect) : CInk() {
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
    this->tileType = type;
    this->x = x;
    this->y = y;
    this->rect = rect;
}

// CBoardTileRLColored 构造函数
CBoardTileRLColored::CBoardTileRLColored(int x, int y, RECT* rect, int color, int flag) : CBoardTile(7, x, y, rect) {
    Helpers::CLogBlock log("CBoardTileRLColored::CBoardTileRLColored");
    this->color = color;
    this->flag = flag;
    this->someVal = (flag != 0) ? 2 : 0;
    Helpers::CLogBlock logAdd("AddGameObjectToUpdateList");
    CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, this);
    Helpers::CLogBlock logWall("AddRLColoredWallToList");
    int& wallCount = g_pCGameBoard->rlColoredWallCount;
    if (wallCount < 289) {
        g_pCGameBoard->rlColoredWalls[wallCount] = this;
        ++wallCount;
    }
}

// CBoardTileRLGray 构造函数
CBoardTileRLGray::CBoardTileRLGray(int x, int y, RECT* rect, int color, int flag, int extra1, int extra2)
    : CBoardTile(7, x, y, rect) {
    Helpers::CLogBlock log("CBoardTileRLGray::CBoardTileRLGray");
    this->color = color;
    this->flag = flag;
    this->extra1 = extra1;
    this->extra2 = extra2;
    this->someVal = (flag != 0) ? 2 : 0;
    Helpers::CLogBlock logAdd("AddGameObjectToUpdateList");
    CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, this);
}
