__int64 __fastcall CBoardManager::LoadBoardFromResources(
        CBoardManager *this,
        unsigned __int16 *a2,
        unsigned __int8 *a3,
        int *a4)
{
  const wchar_t *v4; // r13
  unsigned int v5; // ebx
  int *v6; // rbp
  struct BoardCollection * near **v7; // rdi
  struct BoardCollection * near *v8; // r14
  __int64 v9; // rbx
  int v10; // r12d
  __int64 v11; // rsi
  __int64 v12; // r15
  struct BoardCollection * near *v13; // rbx
  unsigned __int8 *v14; // rdx
  unsigned int v15; // r13d
  HWND MainWindowHwnd; // rax
  int *v18; // [rsp+28h] [rbp-470h]
  _BYTE v20[16]; // [rsp+38h] [rbp-460h] BYREF
  _BYTE v21[24]; // [rsp+48h] [rbp-450h] BYREF
  WCHAR String[512]; // [rsp+60h] [rbp-438h] BYREF

  v4 = a2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CBoardManager::LoadBoardFromResources", 0);
  v5 = 0;
  v6 = (int *)&iBoardCounts;
  v7 = &pBoardCollections;
  do
  {
    if ( (__int64)v7 >= (__int64)&off_4648F0 )
      break;
    v8 = *v7;
    v9 = *v6;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "SearchBoardList", 0);
    v10 = 0;
    v11 = 0;
    v12 = v9;
    if ( (int)v9 <= 0 )
    {
LABEL_9:
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
      v5 = 0;
      goto LABEL_10;
    }
    v13 = v8;
    while ( _wcsicmp(v4, (const wchar_t *)v8 + 258 * v10 + 2) )
    {
LABEL_8:
      ++v11;
      ++v10;
      v13 = (struct BoardCollection * near *)((char *)v13 + 516);
      if ( v11 >= v12 )
        goto LABEL_9;
    }
    v14 = (unsigned __int8 *)&g_BoardData + *(int *)v13;
    v15 = v14[1] + (*v14 << 8);
    memcpy(&BoardData, v14 + 2, v15);
    if ( v15 > 0x1000 )
    {
      v4 = a2;
      goto LABEL_8;
    }
    memcpy(&g_pLastLoadedLevel, &BoardData, v15);
    iBoardSizeBytes = -1;
    memset(String, 0, sizeof(String));
    Helpers::LoadStringW(0, (HINSTANCE)0x3A98, String, (unsigned __int16 *)0x200, 0, v18);
    MainWindowHwnd = GetMainWindowHwnd();
    SetWindowTextW(MainWindowHwnd, String);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
    v5 = 1;
LABEL_10:
    v4 = a2;
    ++v7;
    ++v6;
  }
  while ( !v5 );
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
  return v5;
}
