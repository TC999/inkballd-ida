// 合并并重写日志相关函数为C++风格
#include <windows.h>
#include <string>
#include <cstdarg>
#include <cstring>
#include <cwchar>
#include <type_traits>

// 假设这些GUID和结构体在其它头文件中定义
extern const GUID MessageGuid;
extern const GUID stru_4015E0;
extern const GUID stru_4015D0;

namespace LogHelper {

inline ULONG TraceInt(TRACEHANDLE handle, USHORT code, const GUID* guid, int value) {
    return TraceMessage(handle, 0x2Bu, guid, code, &value, sizeof(value), 0);
}

inline ULONG TraceIntDefaultGuid(TRACEHANDLE handle, __int64 a2, __int64 a3, int value) {
    return TraceMessage(handle, 0x2Bu, &MessageGuid, 0xAu, &value, sizeof(value), 0);
}

inline ULONG TraceString(TRACEHANDLE handle, USHORT code, const char* str) {
    size_t len = str ? std::strlen(str) + 1 : 5;
    const char* msg = str ? str : "NULL";
    return TraceMessage(handle, 0x2Bu, &stru_4015E0, code, msg, len, 0);
}

inline ULONG TraceStringWithArgs(TRACEHANDLE handle, __int64 a2, __int64 a3, const char* str, ...) {
    va_list args;
    va_start(args, str);
    size_t len = str ? std::strlen(str) + 1 : 5;
    const char* msg = str ? str : "NULL";
    ULONG ret = TraceMessage(handle, 0x2Bu, &stru_4015E0, 0xBu, msg, len, args, 4, 0);
    va_end(args);
    return ret;
}

inline ULONG TraceWStringWithArgs(TRACEHANDLE handle, __int64 a2, __int64 a3, __int64 a4, ...) {
    va_list args;
    va_start(args, a4);
    const wchar_t* wmsg = L"TabletPCInkBall-EnableGame";
    size_t len = wcslen(wmsg) + 1;
    ULONG ret = TraceMessage(handle, 0x2Bu, &stru_4015D0, 0xAu, wmsg, len * sizeof(wchar_t), args, 4, 0);
    va_end(args);
    return ret;
}

} // namespace LogHelper
