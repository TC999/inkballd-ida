void __fastcall CBoardManager::LoadRandomBoardFromResources(CBoardManager *this, unsigned __int8 *a2, int *a3)
{
  int RandomNumber; // eax
  __int64 v6; // rbx
  unsigned __int8 *v7; // rdx
  unsigned int v8; // ebx
  HWND MainWindowHwnd; // rax
  int *v10; // [rsp+28h] [rbp-440h]
  _BYTE v11[16]; // [rsp+30h] [rbp-438h] BYREF
  WCHAR String[512]; // [rsp+40h] [rbp-428h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBoardManager::LoadRandomBoardFromResources", 0);
  do
  {
    RandomNumber = GetRandomNumber(iBoardListCount);
    v6 = RandomNumber;
  }
  while ( (unsigned int)fPrevSeen(RandomNumber, (struct BOARDHIST *)&g_bhPrevBoards, iBoardListCount) );
  v7 = (unsigned __int8 *)&g_BoardData + *((int *)paBoardList + 129 * v6);
  v8 = v7[1] + (*v7 << 8);
  memcpy(a2, v7 + 2, v8);
  if ( v8 <= 0x1000 )
    memcpy(&g_pLastLoadedLevel, a2, v8);
  *a3 = -1;
  Helpers::LoadStringW(0, (HINSTANCE)0x3A98, String, (unsigned __int16 *)0x200, 0, v10);
  MainWindowHwnd = GetMainWindowHwnd();
  SetWindowTextW(MainWindowHwnd, String);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
}
