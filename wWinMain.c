// Hidden C++ exception states: #wind=5
int __stdcall wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPWSTR lpCmdLine, int nShowCmd)
{
  ULONG64 *v7; // rdi
  const GUID **v8; // rsi
  const GUID *v9; // r8
  int BOOLPermission; // edi
  int v11; // esi
  HRESULT v13; // eax
  HRESULT v14; // eax
  int wParam; // r12d
  HRESULT v16; // eax
  int *v17; // r8
  _BOOL8 v18; // r14
  __int64 v19; // rdx
  CGameManager *v20; // rax
  HWND v21; // r13
  CGameManager *v22; // rax
  CGameBoard *v23; // rdi
  __int64 v24; // rdx
  unsigned int v25; // edi
  LPWSTR v26; // rbx
  __int64 v27; // rcx
  LPWSTR v28; // rdi
  bool v29; // zf
  __int64 v30; // rax
  HMENU Menu; // rax
  HANDLE WaitableTimerW; // rax
  signed int LastError; // eax
  unsigned int v34; // r9d
  signed int v35; // eax
  unsigned int v36; // r9d
  CGameManager *v37; // rbx
  CGameBoard *v38; // rdi
  __int64 *v39; // rdx
  __int64 v40; // [rsp+0h] [rbp-128h] BYREF
  PTRACE_GUID_REGISTRATION TraceGuidReg; // [rsp+20h] [rbp-108h]
  HWND hWnd[2]; // [rsp+40h] [rbp-E8h] BYREF
  int v43[2]; // [rsp+50h] [rbp-D8h] BYREF
  HANDLE pHandles; // [rsp+58h] [rbp-D0h] BYREF
  _BYTE v45[16]; // [rsp+60h] [rbp-C8h] BYREF
  LPVOID ppv; // [rsp+70h] [rbp-B8h] BYREF
  struct _TRACE_GUID_REGISTRATION v47; // [rsp+78h] [rbp-B0h] BYREF
  tagMSG Msg; // [rsp+88h] [rbp-A0h] BYREF
  HACCEL hAccTable[2]; // [rsp+C0h] [rbp-68h] BYREF
  LARGE_INTEGER DueTime; // [rsp+D0h] [rbp-58h] BYREF
  __int64 v51; // [rsp+D8h] [rbp-50h]
  _BYTE v52[16]; // [rsp+E0h] [rbp-48h] BYREF
  _QWORD v53[4]; // [rsp+F0h] [rbp-38h] BYREF

  v51 = -2;
  qword_4B8E10 = 0;
  WPP_MAIN_CB = (__int64)&qword_4B8E20;
  byte_4B8E18 = 1;
  byte_4B8E19 = 2;
  word_4B8E1A = 0;
  dword_4B8E1C = 0;
  qword_4B8E30 = 0;
  qword_4B8E20 = 0;
  byte_4B8E38 = 1;
  byte_4B8E39 = 2;
  word_4B8E3A = 0;
  dword_4B8E3C = 0;
  WPP_REGISTRATION_GUIDS = (__int64)WPP_ThisDir_CTLGUID_ControlGuid;
  qword_4B8E48 = (__int64)WPP_ThisDir_CTLGUID_MobTabPerfTraceProvider;
  v7 = (ULONG64 *)&WPP_MAIN_CB;
  WPP_GLOBAL_Control = &WPP_MAIN_CB;
  v8 = (const GUID **)&WPP_REGISTRATION_GUIDS;
  do
  {
    v9 = *v8++;
    v47.Guid = v9;
    v47.RegHandle = 0;
    RegisterTraceGuidsW((WMIDPREQUEST)WppControlCallback, v7, v9, 1u, &v47, 0, 0, v7 + 1);
    v7 = (ULONG64 *)*v7;
  }
  while ( v7 );
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v47, "wWinMain", 0);
  HeapSetInformation(0, HeapEnableTerminationOnCorruption, 0, 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)hWnd, "CanRunInkball", 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)hAccTable, "CTabLicense::CanRunInkball", 0);
  BOOLPermission = CTabLicense::GetBOOLPermission(L"TabletPCInkBall-EnableGame", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)hAccTable);
  if ( BOOLPermission )
  {
    v43[0] = 0;
    if ( (int)TabUtils::TabQueryPolicyValue((TabUtils *)L"DisableInkball", 0, (int)v43, 0, (int *)TraceGuidReg) >= 0
      && v43[0] )
    {
      BOOLPermission = 0;
    }
    v11 = 0;
  }
  else
  {
    v11 = 1;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)hWnd);
  if ( !BOOLPermission )
  {
    if ( !v11 )
      DispError(0, 15011, 0x3AA8u);
    WppCleanupUm();
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v47);
    return -1;
  }
  if ( (unsigned int)WinSqmIsOptedIn() )
  {
    v43[0] = 1;
    LODWORD(hWnd[0]) = 1437;
    memset(&Msg, 0, sizeof(Msg));
    if ( (unsigned int)WinSqmEventEnabled(SQM_INCREMENT_DWORD, 0) )
    {
      Msg.hwnd = (HWND)&unk_41F140;
      Msg.message = 16;
      *(&Msg.message + 1) = 0;
      Msg.wParam = (WPARAM)hWnd;
      Msg.lParam = 4;
      *(_QWORD *)&Msg.time = v43;
      Msg.pt.y = 4;
      *((_DWORD *)&Msg.pt + 2) = 0;
      WinSqmEventWrite(SQM_INCREMENT_DWORD, 3, &Msg);
    }
  }
  SetProcessDPIAware();
  v13 = RegisterApplicationRestart(L" ", 0);
  if ( v13 < 0
    && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
  {
    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xCu, (const GUID *)qword_4015F0, v13);
  }
  v14 = RegisterApplicationRecoveryCallback(InkBallRecovery, 0, 0, 0);
  if ( v14 < 0
    && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
  {
    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xDu, (const GUID *)qword_4015F0, v14);
  }
  wParam = -1;
  ppv = 0;
  pHandles = 0;
  v16 = CoInitialize(0);
  v18 = v16 >= 0;
  if ( v16 < 0 )
  {
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xEu, (const GUID *)qword_4015F0, v16);
    goto LABEL_98;
  }
  hWnd[0] = 0;
  if ( CoCreateInstance(&CLSID_ClassicW, 0, 0x17u, &IID_IUnknown, &ppv) < 0
    || (*(int (__fastcall **)(LPVOID, HWND *))(*(_QWORD *)ppv + 24LL))(ppv, hWnd) < 0
    || (*(__m128i *)hAccTable = _mm_loadu_si128((const __m128i *)&CLSID_EnablingKey),
        ((int (__fastcall *)(HACCEL *))hWnd[0])(hAccTable) < 0) )
  {
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
    {
      LOWORD(v19) = 15;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v19, qword_4015F0);
    }
LABEL_97:
    DispError(0, 15011, 0x3AAAu);
    goto LABEL_98;
  }
  g_hInst = hInstance;
  if ( (int)WinInit(hInstance, (unsigned int)nShowCmd, hWnd, hAccTable) >= 0 )
  {
    _set_new_handler((int (*)(unsigned __int64))new_oom_handler);
    try
    {
      v20 = (CGameManager *)operator new(0x14u);
      *(_QWORD *)v43 = v20;
      if ( v20 )
      {
        v21 = hWnd[0];
        v22 = CGameManager::CGameManager(v20, hWnd[0]);
      }
      else
      {
        v22 = 0;
        v21 = hWnd[0];
      }
      g_pCGameManager = v22;
    }
    catch ( std::bad_alloc v53 )
    {
      v39 = &v40;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LOWORD(v39) = 16;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v39, qword_4015F0);
      }
      v53[0] = &std::bad_alloc::`vftable';
      exception::~exception((exception *)v53);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v47);
      return 0;
    }
    LODWORD(hWnd[0]) = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "CGameManager::Init", (int *)hWnd);
    v23 = g_pCGameBoard;
    v43[0] = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v52, "CGameBoard::Init", v43);
    LODWORD(v23) = CInk::Init(*((CInk **)v23 + 1893));
    v43[0] = (int)v23;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v52);
    LODWORD(hWnd[0]) = (_DWORD)v23;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
    if ( (int)v23 >= 0 )
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "CRegistryManager::ReadDifficulty", 0);
      if ( ReadRegValueDWORD(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", L"Difficulty", (BYTE *)hWnd) )
      {
        v25 = (unsigned int)hWnd[0];
      }
      else
      {
        CreateInkballKey();
        CRegistryManager::WriteDifficulty((CRegistryManager *)&g_CRegistryManager, 0);
        v25 = 0;
        LODWORD(hWnd[0]) = 0;
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
      CBoardManager::SetDifficulty((__int64)&g_CBoardManager, v25);
      if ( !*lpCmdLine )
        goto LABEL_58;
      if ( *lpCmdLine == 47 && (lpCmdLine[1] == 114 || lpCmdLine[1] == 82) )
      {
        if ( lpCmdLine[2] != 58 )
        {
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "ExitBadCommandLine", 0);
          DispError(v21, 15011, 0x3AA7u);
          exit(0);
        }
        v26 = lpCmdLine + 3;
        if ( *v26 == 34 )
          ++v26;
        v27 = -1;
        v28 = v26;
        do
        {
          if ( !v27 )
            break;
          v29 = *v28++ == 0;
          --v27;
        }
        while ( !v29 );
        v30 = -(int)v27 - 3;
        if ( v26[v30] == 34 )
          v26[v30] = 0;
        if ( !(unsigned int)CBoardManager::LoadBoardFromResources(
                              (CBoardManager *)&g_CBoardManager,
                              v26,
                              &BoardData,
                              &iBoardSizeBytes) )
LABEL_58:
          CBoardManager::LoadRandomBoardFromResources((CBoardManager *)&g_CBoardManager, &BoardData, &iBoardSizeBytes);
      }
      if ( g_pCGameManager )
      {
        CGameManager::LoadBoard(g_pCGameManager, &BoardData, iBoardSizeBytes);
        *((_DWORD *)g_pCGameManager + 1) = 1;
      }
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "SetMenuChecks", 0);
      Menu = GetMenu(v21);
      if ( dword_4DA6F4 )
      {
        switch ( dword_4DA6F4 )
        {
          case 1u:
            CheckMenuItem(Menu, 0x9C43u, 8u);
            iLastChecked = 40003;
            break;
          case 2u:
            CheckMenuItem(Menu, 0x9C44u, 8u);
            iLastChecked = 40004;
            break;
          case 3u:
            CheckMenuItem(Menu, 0x9C45u, 8u);
            iLastChecked = 40005;
            break;
          case 4u:
            CheckMenuItem(Menu, 0x9C46u, 8u);
            iLastChecked = 40006;
            break;
        }
      }
      else
      {
        CheckMenuItem(Menu, 0x9C42u, 8u);
        iLastChecked = 40002;
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
      WaitableTimerW = CreateWaitableTimerW(0, 0, 0);
      pHandles = WaitableTimerW;
      if ( !WaitableTimerW
        && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LastError = GetLastError();
        v34 = (unsigned __int16)LastError | 0x80070000;
        if ( LastError <= 0 )
          v34 = LastError;
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x12u, (const GUID *)qword_4015F0, v34);
        WaitableTimerW = pHandles;
      }
      DueTime.QuadPart = -150000;
      SetWaitableTimer(WaitableTimerW, &DueTime, 0, 0, 0, 0);
      ShowWindow(v21, nShowCmd);
      LODWORD(hWnd[0]) = 0;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "Helpers::UpdateWindow", (int *)hWnd);
      if ( !UpdateWindow(v21) )
      {
        v35 = GetLastError();
        v36 = (unsigned __int16)v35 | 0x80070000;
        if ( v35 <= 0 )
          v36 = v35;
        LODWORD(hWnd[0]) = v36;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x5Au, &stru_4015E0, v36);
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
      do
      {
LABEL_84:
        while ( !MsgWaitForMultipleObjects(1u, &pHandles, 0, 0xFFFFFFFF, 0x4FFu) )
        {
          SetWaitableTimer(pHandles, &DueTime, 0, 0, 0, 0);
          if ( g_pCGameManager )
            CGameManager::PerformGameUpdate(g_pCGameManager);
        }
      }
      while ( !PeekMessageW(&Msg, 0, 0, 0, 1u) );
      while ( Msg.message != 18 )
      {
        if ( !TranslateAcceleratorW(v21, hAccTable[0], &Msg) )
        {
          TranslateMessage(&Msg);
          DispatchMessageW(&Msg);
        }
        if ( !PeekMessageW(&Msg, 0, 0, 0, 1u) )
          goto LABEL_84;
      }
      wParam = Msg.wParam;
      goto LABEL_98;
    }
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 8) != 0 )
    {
      LOWORD(v24) = 17;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v24, qword_4015F0);
    }
    goto LABEL_97;
  }
LABEL_98:
  if ( pHandles )
  {
    Helpers::CloseHandle(pHandles, 0, v17);
    pHandles = 0;
  }
  v37 = g_pCGameManager;
  if ( g_pCGameManager )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "CGameManager::~CGameManager", 0);
    v38 = g_pCGameBoard;
    if ( g_pCGameBoard )
    {
      CGameBoard::~CGameBoard(g_pCGameBoard);
      operator delete(v38);
      g_pCGameBoard = 0;
    }
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
    operator delete(v37);
    g_pCGameManager = 0;
  }
  if ( ppv )
  {
    (*(void (__fastcall **)(LPVOID))(*(_QWORD *)ppv + 16LL))(ppv);
    ppv = 0;
  }
  if ( v18 )
    CoUninitialize();
  WppCleanupUm();
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v47);
  return wParam;
}
