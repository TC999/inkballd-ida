// Modern C++ rewrite of wWinMain
//#include <windows.h>
#include <memory>
#include <string>
#include <stdexcept>
#include "CGameManager.h" // 假设有这些头文件
#include "CGameBoard.h"
#include "Helpers.h"
#include "RegistryManager.h"
#include "BoardManager.h"
// ... 其它需要的头文件

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
    // 初始化全局和日志
    Helpers::CLogBlock logMain("wWinMain");
    HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

    // 权限检查
    {
        Helpers::CLogBlock logPerm("CanRunInkball");
        Helpers::CLogBlock logTab("CTabLicense::CanRunInkball");
        bool canRun = CTabLicense::GetBOOLPermission(L"TabletPCInkBall-EnableGame", false);
        if (canRun) {
            int policy = 0;
            if (TabUtils::TabQueryPolicyValue(L"DisableInkball", 0, &policy, 0, nullptr) >= 0 && policy) {
                canRun = false;
            }
        }
        if (!canRun) {
            DispError(nullptr, 15011, 0x3AA8u);
            WppCleanupUm();
            return -1;
        }
    }

    SetProcessDPIAware();
    RegisterApplicationRestart(L" ", 0);
    RegisterApplicationRecoveryCallback(InkBallRecovery, nullptr, 0, 0);

    int wParam = -1;
    HRESULT hr = CoInitialize(nullptr);
    bool comInited = SUCCEEDED(hr);
    if (!comInited) {
        WppCleanupUm();
        return wParam;
    }

    HWND hWnd = nullptr;
    HACCEL hAccel = nullptr;
    // 省略COM对象创建和初始化，假设成功
    g_hInst = hInstance;
    if (WinInit(hInstance, nShowCmd, &hWnd, &hAccel) >= 0) {
        std::set_new_handler(new_oom_handler);
        std::unique_ptr<CGameManager> gameManager;
        try {
            gameManager = std::make_unique<CGameManager>(hWnd);
            g_pCGameManager = gameManager.get();
        } catch (const std::bad_alloc&) {
            return 0;
        }

        Helpers::CLogBlock logInit("CGameManager::Init");
        if (CInk::Init(g_pCGameBoard) >= 0) {
            Helpers::CLogBlock logDiff("CRegistryManager::ReadDifficulty");
            int difficulty = 0;
            if (!ReadRegValueDWORD(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", L"Difficulty", (BYTE*)&difficulty)) {
                CreateInkballKey();
                CRegistryManager::WriteDifficulty(&g_CRegistryManager, 0);
                difficulty = 0;
            }
            CBoardManager::SetDifficulty(&g_CBoardManager, difficulty);
            // 处理命令行参数和关卡加载
            if (lpCmdLine && *lpCmdLine) {
                if (*lpCmdLine == L'/' && (lpCmdLine[1] == L'r' || lpCmdLine[1] == L'R')) {
                    // ... 解析关卡文件名并加载 ...
                } else {
                    CBoardManager::LoadRandomBoardFromResources(&g_CBoardManager, &BoardData, &iBoardSizeBytes);
                }
            } else {
                CBoardManager::LoadRandomBoardFromResources(&g_CBoardManager, &BoardData, &iBoardSizeBytes);
            }
            if (g_pCGameManager) {
                CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
                g_pCGameManager->SetActive(true);
            }
            // ... 菜单和窗口初始化 ...
            ShowWindow(hWnd, nShowCmd);
            UpdateWindow(hWnd);
            // 主消息循环
            MSG msg = {};
            while (GetMessage(&msg, nullptr, 0, 0)) {
                if (!TranslateAccelerator(hWnd, hAccel, &msg)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }
            wParam = static_cast<int>(msg.wParam);
        }
    }
    // 清理
    gameManager.reset();
    if (comInited) CoUninitialize();
    WppCleanupUm();
    return wParam;
}
