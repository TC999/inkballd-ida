// 合并并重写 BuildTileObject::_1_::catch_N 系列异常处理函数
#include "LogHelper.h" // 假设日志宏和WPP_SF_等已在此头中声明
#include <cstdint>

namespace BuildTileObjectCatch {

void* catchHandler(int code, void* loc) {
    // 日志记录
    if (WPP_GLOBAL_Control != reinterpret_cast<void*>(&WPP_GLOBAL_Control) && ((*reinterpret_cast<uint8_t*>(WPP_GLOBAL_Control) + 28) & 4) != 0) {
        LogHelper::WPP_SF_(reinterpret_cast<uint64_t*>(WPP_GLOBAL_Control)[2], static_cast<uint16_t>(code), qword_401918);
    }
    return loc;
}

void* catch_0() { return catchHandler(14, reinterpret_cast<void*>(&loc_40D4BB)); }
void* catch_1() { return catchHandler(15, reinterpret_cast<void*>(&loc_40D5D2)); }
void* catch_2() { return catchHandler(16, reinterpret_cast<void*>(&loc_40D6E2)); }
void* catch_3() { return catchHandler(17, reinterpret_cast<void*>(&loc_40D7F1)); }
void* catch_4() { return catchHandler(18, reinterpret_cast<void*>(&loc_40D919)); }
void* catch_5() { return catchHandler(19, reinterpret_cast<void*>(&loc_40DA2F)); }
void* catch_6() { return catchHandler(20, reinterpret_cast<void*>(&loc_40DB08)); }
void* catch_7() { return catchHandler(21, reinterpret_cast<void*>(&loc_40DBFF)); }
void* catch_8() { return catchHandler(22, reinterpret_cast<void*>(&loc_40DD1B)); }
void* catch_9() { return catchHandler(13, reinterpret_cast<void*>(&loc_40DE34)); }

} // namespace BuildTileObjectCatch
