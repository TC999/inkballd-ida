// C++重写 CBitmapRects 构造函数
#include "CBitmapRects.h"
#include "Helpers.h"

// 假设这些全局变量在头文件中声明
extern int dword_4B8F3C, dword_4B8EF8, dword_4B8EFC, dword_4B8F04, dword_4B8F0C, dword_4B8F14, dword_4B8F1C, dword_4B8F24, dword_4B8F2C, dword_4B8F34, dword_4B8F08, dword_4B8F58, dword_4B8F60, dword_4B8F68, dword_4B8F70, dword_4B8F78, dword_4B8F80, dword_4B8F18, dword_4B8F28, dword_4B8F38, dword_4B8F9C, dword_4B8FA4, dword_4B8F48, dword_4B8F4C, dword_4B8F50, dword_4B8F5C, dword_4B8F6C, dword_4B8F7C, dword_4B8F8C, g_CBitmapRects, dword_4B8FAC, dword_4B8ED8, dword_4B8ED4, dword_4B8EDC, dword_4B8EE0, dword_4B8EE8, dword_4B8EE4, dword_4B8EEC, dword_4B8EF0, dword_4B8EF4, dword_4B8F00, dword_4B8F10, dword_4B8F20, dword_4B8F30, dword_4B8F40, dword_4B8F44, dword_4B8F54, dword_4B8F64, dword_4B8F74, dword_4B8F88, dword_4B8F84, dword_4B8F90, dword_4B8F98, dword_4B8F94, dword_4B8FA0, dword_4B8FA8, dword_4B8FB0, dword_4B8FB4, dword_4B8FCC, dword_4B8FD4, dword_4B900C, dword_4B901C, dword_4B904C, dword_4B905C, dword_4B8FB8, dword_4B8FC8, dword_4B8FD8, dword_4B906C, dword_4B907C, dword_4B9084, dword_4B9094, dword_4B908C, dword_4B909C, dword_4B8FBC, dword_4B8FC4, dword_4B90A4, dword_4B90B4, dword_4B8FC0, dword_4B8FD0, dword_4B8FDC, dword_4B90CC;
// ... 省略其它全局变量声明 ...

CBitmapRects::CBitmapRects() {
    Helpers::CLogBlock log("CBitmapRects::CBitmapRects");
    // 初始化所有相关全局变量
    dword_4B8F3C = 277;
    dword_4B8EF8 = 25;
    dword_4B8EFC = 181;
    dword_4B8F04 = 181;
    dword_4B8F0C = 205;
    dword_4B8F14 = 205;
    dword_4B8F1C = 229;
    dword_4B8F24 = 229;
    dword_4B8F2C = 253;
    dword_4B8F34 = 253;
    dword_4B8F08 = 25;
    dword_4B8F58 = 49;
    dword_4B8F60 = 49;
    dword_4B8F68 = 73;
    dword_4B8F70 = 73;
    dword_4B8F78 = 97;
    dword_4B8F80 = 97;
    dword_4B8F18 = 25;
    dword_4B8F28 = 25;
    dword_4B8F38 = 25;
    dword_4B8F9C = 85;
    dword_4B8FA4 = 85;
    dword_4B8F48 = 25;
    dword_4B8F4C = 399;
    dword_4B8F50 = 25;
    dword_4B8F5C = 399;
    dword_4B8F6C = 399;
    dword_4B8F7C = 399;
    dword_4B8F8C = 399;
    g_CBitmapRects[0] = 1;
    dword_4B8FAC = 103;
    // ... 省略其它全局变量初始化 ...
    // 实际项目中建议用结构体或数组封装这些数据
}
