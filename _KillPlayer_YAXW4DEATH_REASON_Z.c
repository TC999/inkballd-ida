// Hidden C++ exception states: #wind=3
void __fastcall KillPlayer(int a1)
{
  CGameManager *v2; // rax
  BOOL v3; // esi
  _DWORD *v4; // rbx
  _DWORD *v5; // rbx
  CGameManager *v6; // rbx
  int *v7; // [rsp+28h] [rbp-850h]
  _BYTE v8[16]; // [rsp+30h] [rbp-848h] BYREF
  _BYTE v9[16]; // [rsp+40h] [rbp-838h] BYREF
  __int64 v10; // [rsp+50h] [rbp-828h]
  WCHAR Text[512]; // [rsp+60h] [rbp-818h] BYREF
  WCHAR Caption[512]; // [rsp+460h] [rbp-418h] BYREF

  v10 = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "KillPlayer", 0);
  v2 = g_pCGameManager;
  v3 = *((_DWORD *)g_pCGameManager + 1) == 0;
  *((_DWORD *)g_pCGameManager + 1) = 0;
  *((_DWORD *)v2 + 3) = 0;
  *((_DWORD *)v2 + 4) = 0;
  if ( !a1 )
  {
    Helpers::LoadStringW(0, (HINSTANCE)0x3A9A, Text, (unsigned __int16 *)0x200, 0, v7);
LABEL_6:
    Helpers::LoadStringW(0, (HINSTANCE)0x3A99, Caption, (unsigned __int16 *)0x200, 0, v7);
    MessageBoxW(*((HWND *)g_pCGameBoard + 1892), Text, Caption, 0);
    goto LABEL_7;
  }
  if ( a1 == 1 )
    Helpers::LoadStringW(0, (HINSTANCE)0x3A9B, Text, (unsigned __int16 *)0x200, 0, v7);
  if ( a1 != 2 )
    goto LABEL_6;
LABEL_7:
  v4 = (_DWORD *)*((_QWORD *)g_pCGameBoard + 1889);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CScoreManager::ResetScore", 0);
  v4[11] = 0;
  (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v4 + 8LL))(v4);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  v5 = (_DWORD *)*((_QWORD *)g_pCGameBoard + 1890);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CTileManager::ResetTileCount", 0);
  v5[10] = 0;
  v5[11] = 0;
  (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v5 + 8LL))(v5);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  if ( a1 != 2 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBoardManager::GetLastLoadedBoardData", 0);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
    CGameManager::LoadBoard(g_pCGameManager, &g_pLastLoadedLevel, -1);
    v6 = g_pCGameManager;
    *(_DWORD *)v6 = timeGetTime();
  }
  (*(void (__fastcall **)(_QWORD))(**((_QWORD **)g_pCGameBoard + 1891) + 8LL))(*((_QWORD *)g_pCGameBoard + 1891));
  if ( !v3 )
    *((_DWORD *)g_pCGameManager + 1) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
