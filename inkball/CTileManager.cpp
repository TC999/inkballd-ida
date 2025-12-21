// C++重写 CTileManager 构造函数
#include "CTileManager.h"
#include "Helpers.h"
#include <stdexcept>
#include <new>

CTileManager::CTileManager() {
    Helpers::CLogBlock log("CTileManager::CTileManager");
    // 按原C代码顺序初始化成员变量
    this->field8 = 445;
    this->fieldC = 0;
    this->field10 = 42;
    this->field14 = 42;
    this->field18 = 445;
    this->field1C = 0;
    this->field20 = 487;
    this->field24 = 42;
    // InitSurface失败则抛出bad_alloc异常
    if (this->InitSurface() < 0) {
        throw std::bad_alloc();
    }
    this->field28 = 0;
    this->field2C = 0;
    this->field30 = 1600;
}
