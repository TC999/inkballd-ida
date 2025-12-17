// Hidden C++ exception states: #wind=1
LRESULT __fastcall MainWndProc(HWND a1, UINT Msg, WPARAM wParam, _DWORD *lParam)
{
  HMENU Menu; // rbx
  BOOL v9; // edi
  LONG WindowLongW; // ebx
  LONG v11; // eax
  int v12; // r11d
  int v13; // eax
  LONG v14; // ebx
  LONG v15; // eax
  CGameManager *v17; // rbx
  CGameManager *v18; // rbx
  signed int LastError; // eax
  LONG v20; // r9d
  LRESULT v21; // rbx
  int *v22; // r9
  HICON IconW; // rax
  HRESULT Instance; // ebp
  BSTR v25; // rax
  OLECHAR *v26; // rbx
  CGameManager *v27; // rax
  int *v28; // [rsp+28h] [rbp-C30h]
  struct tagRECT Rect; // [rsp+50h] [rbp-C08h] BYREF
  _BYTE v30[16]; // [rsp+60h] [rbp-BF8h] BYREF
  tagTRACKMOUSEEVENT EventTrack; // [rsp+70h] [rbp-BE8h] BYREF
  __int64 v32; // [rsp+88h] [rbp-BD0h]
  tagPAINTSTRUCT Paint; // [rsp+90h] [rbp-BC8h] BYREF
  _OSVERSIONINFOW VersionInformation; // [rsp+E0h] [rbp-B78h] BYREF
  WCHAR szApp[264]; // [rsp+200h] [rbp-A58h] BYREF
  WCHAR szOtherStuff[1024]; // [rsp+410h] [rbp-848h] BYREF

  v32 = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "MainWndProc", 0);
  Menu = GetMenu(a1);
  v9 = 0;
  if ( Msg <= 0x86 )
  {
    if ( Msg != 134 )
    {
      switch ( Msg )
      {
        case 2u:
          goto LABEL_26;
        case 3u:
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&Rect, "CGameBoard::UpdateBounds", 0);
          CDisplay::UpdateBounds(g_pDisplay);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&Rect);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
        case 5u:
          if ( g_pCGameManager )
          {
            if ( wParam == 4 || wParam == 1 )
            {
              *((_DWORD *)g_pCGameManager + 1) = 0;
            }
            else if ( !*((_DWORD *)g_pCGameManager + 2) )
            {
              *((_DWORD *)g_pCGameManager + 1) = 1;
            }
            Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&Rect, "CGameBoard::UpdateBounds", 0);
            CDisplay::UpdateBounds(g_pDisplay);
            Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&Rect);
          }
          goto LABEL_71;
        case 0xFu:
          BeginPaint(a1, &Paint);
          CGameBoard::Paint(g_pCGameBoard);
          EndPaint(a1, &Paint);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
        case 0x12u:
LABEL_26:
          PostQuitMessage(0);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
      }
      if ( Msg != 20 )
      {
        if ( Msg != 36 )
        {
          if ( Msg == 126 )
            CInk::OnDisplayChange(*((CInk **)g_pCGameBoard + 1893));
          goto LABEL_71;
        }
        Rect.left = 0;
        Rect.top = 0;
        if ( g_pCGameBoard )
        {
          Rect.right = *((_DWORD *)g_pCGameBoard + 3764);
          Rect.bottom = *((_DWORD *)g_pCGameBoard + 3765);
          WindowLongW = GetWindowLongW(a1, -20);
          LOBYTE(v9) = GetMenu(a1) != 0;
          v11 = GetWindowLongW(a1, -16);
          AdjustWindowRectEx(&Rect, v11, v9, WindowLongW);
          v12 = Rect.right - Rect.left;
          lParam[6] = Rect.right - Rect.left;
          v13 = Rect.bottom - Rect.top;
          lParam[7] = Rect.bottom - Rect.top;
          lParam[8] = v12;
          lParam[9] = v13;
        }
        else
        {
          Rect.right = 544;
          Rect.bottom = 586;
          v14 = GetWindowLongW(a1, -20);
          LOBYTE(v9) = GetMenu(a1) != 0;
          v15 = GetWindowLongW(a1, -16);
          AdjustWindowRectEx(&Rect, v15, v9, v14);
          lParam[8] = Rect.right - Rect.left;
          lParam[9] = Rect.bottom - Rect.top;
        }
LABEL_15:
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        return 0;
      }
      goto LABEL_83;
    }
    if ( g_pCGameManager && !g_fLastPauseFromMenu )
      *((_DWORD *)g_pCGameManager + 1) = wParam != 0;
LABEL_45:
    if ( !g_fMouseInside )
    {
      g_fMouseInside = 1;
      EventTrack.cbSize = 24;
      memset(&EventTrack.dwFlags, 0, 0x14u);
      EventTrack.dwFlags = 2;
      EventTrack.hwndTrack = a1;
      TrackMouseEvent(&EventTrack);
    }
    goto LABEL_71;
  }
  if ( Msg != 273 )
  {
    if ( Msg != 512 )
    {
      switch ( Msg )
      {
        case 0x204u:
          CGameManager::DropWallTile(g_pCGameManager, (__int16)lParam, SWORD1(lParam));
          break;
        case 0x211u:
          *((_DWORD *)g_pCGameManager + 1) = 0;
          break;
        case 0x212u:
          v18 = g_pCGameManager;
          *(_DWORD *)v18 = timeGetTime();
          if ( !*((_DWORD *)g_pCGameManager + 2) )
            *((_DWORD *)g_pCGameManager + 1) = 1;
          break;
        case 0x232u:
          v17 = g_pCGameManager;
          *(_DWORD *)v17 = timeGetTime();
          break;
        case 0x2A3u:
          g_fMouseInside = 0;
          break;
        case 0x30Fu:
          CGameBoard::QueryNewPallete(g_pCGameBoard);
          break;
      }
      goto LABEL_71;
    }
    goto LABEL_45;
  }
  if ( (unsigned __int16)wParam > 0x9C45u )
  {
    switch ( (unsigned __int16)wParam )
    {
      case 0x9C46u:
        CheckMenuItem(Menu, iLastChecked, 0);
        iLastChecked = 40006;
        CheckMenuItem(Menu, 0x9C46u, 8u);
        CBoardManager::SetDifficulty((__int64)&g_CBoardManager, 4u);
        CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
        CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        return 0;
      case 0x9C4Au:
        v27 = g_pCGameManager;
        if ( *((_DWORD *)g_pCGameManager + 2) )
        {
          *((_DWORD *)g_pCGameManager + 1) = 1;
          *((_DWORD *)v27 + 2) = 0;
          *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1893) + 24LL) = 1;
          CheckMenuItem(Menu, 0x9C4Au, 0);
          g_fLastPauseFromMenu = 0;
        }
        else
        {
          *((_DWORD *)g_pCGameManager + 1) = 0;
          *((_DWORD *)v27 + 2) = 1;
          *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1893) + 24LL) = 0;
          CheckMenuItem(Menu, 0x9C4Au, 8u);
          g_fLastPauseFromMenu = 1;
        }
LABEL_83:
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        return 0;
      case 0x9C68u:
        *(_QWORD *)&Rect.left = 0;
        Instance = CoCreateInstance(
                     &GUID_8cec58e7_07a1_11d9_b15e_000d56bfe6ee,
                     0,
                     0x17u,
                     &GUID_8cec5884_07a1_11d9_b15e_000d56bfe6ee,
                     (LPVOID *)&Rect);
        if ( Instance < 0 )
          goto LABEL_78;
        v25 = SysAllocString(L"mshelp://Windows/?id=c209fb0d-530b-43ce-954b-7c91aeca0013");
        v26 = v25;
        if ( v25 )
        {
          Instance = (*(__int64 (__fastcall **)(_QWORD, BSTR))(**(_QWORD **)&Rect.left + 24LL))(
                       *(_QWORD *)&Rect.left,
                       v25);
          SysFreeString(v26);
        }
        (*(void (__fastcall **)(_QWORD))(**(_QWORD **)&Rect.left + 16LL))(*(_QWORD *)&Rect.left);
        if ( Instance < 0 )
LABEL_78:
          DispError(a1, 0x3AA3u, 0x3AA9u);
        goto LABEL_15;
      case 0x9C69u:
        szOtherStuff[0] = 0;
        Helpers::LoadStringW(g_hInst, (HINSTANCE)0x3A98, szApp, (unsigned __int16 *)0x104, 0, v28);
        memset(&VersionInformation, 0, sizeof(VersionInformation));
        VersionInformation.dwOSVersionInfoSize = 276;
        GetVersionExW(&VersionInformation);
        StringCchPrintfExW(
          szOtherStuff,
          0x400u,
          0,
          0,
          0x100u,
          L"%s %lu.%lu.%lu",
          szApp,
          VersionInformation.dwMajorVersion,
          VersionInformation.dwMinorVersion,
          VersionInformation.dwBuildNumber);
        IconW = Helpers::LoadIconW(g_hInst, (HINSTANCE)0x65, 0, v22);
        ShellAboutW(a1, szApp, szOtherStuff, IconW);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        return 0;
      case 0x9C6Au:
        CInk::ClearInk(*((CInk **)g_pCGameBoard + 1893));
        BltBoardToInk(0);
        InvalidateRect(a1, 0, 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        return 0;
      default:
LABEL_71:
        v21 = DefWindowProcW(a1, Msg, wParam, (LPARAM)lParam);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        return v21;
    }
  }
  else
  {
    if ( (unsigned __int16)wParam == 40005 )
    {
      CheckMenuItem(Menu, iLastChecked, 0);
      iLastChecked = 40005;
      CheckMenuItem(Menu, 0x9C45u, 8u);
      CBoardManager::SetDifficulty((__int64)&g_CBoardManager, 3u);
      CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
      CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
      return 0;
    }
    if ( (unsigned __int16)wParam != 40000 )
    {
      switch ( (unsigned __int16)wParam )
      {
        case 0x9C41u:
          KillPlayer(2);
          CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
          CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
          InvalidateRect(a1, 0, 0);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
        case 0x9C42u:
          CheckMenuItem(Menu, iLastChecked, 0);
          iLastChecked = 40002;
          CheckMenuItem(Menu, 0x9C42u, 8u);
          CBoardManager::SetDifficulty((__int64)&g_CBoardManager, 0);
          CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
          CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
        case 0x9C43u:
          CheckMenuItem(Menu, iLastChecked, 0);
          iLastChecked = 40003;
          CheckMenuItem(Menu, 0x9C43u, 8u);
          CBoardManager::SetDifficulty((__int64)&g_CBoardManager, 1u);
          CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
          CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
        case 0x9C44u:
          CheckMenuItem(Menu, iLastChecked, 0);
          iLastChecked = 40004;
          CheckMenuItem(Menu, 0x9C44u, 8u);
          CBoardManager::SetDifficulty((__int64)&g_CBoardManager, 2u);
          CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
          CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          return 0;
      }
      goto LABEL_71;
    }
    Rect.left = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&EventTrack, "Helpers::PostMessageW", &Rect.left);
    if ( !PostMessageW(a1, 0x10u, 0, 0) )
    {
      LastError = GetLastError();
      v20 = (unsigned __int16)LastError | 0x80070000;
      if ( LastError <= 0 )
        v20 = LastError;
      Rect.left = v20;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x37u, &stru_4015E0, v20);
    }
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&EventTrack);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
    return 0;
  }
}
