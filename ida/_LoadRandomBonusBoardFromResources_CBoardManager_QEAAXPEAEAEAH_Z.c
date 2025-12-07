void __fastcall CBoardManager::LoadRandomBonusBoardFromResources(CBoardManager *this, unsigned __int8 *a2, int *a3)
{
  int RandomNumber; // eax
  __int64 v5; // rbx
  unsigned __int8 *v6; // rdx
  unsigned int v7; // ebx
  HWND MainWindowHwnd; // rax
  int *v9; // [rsp+28h] [rbp-430h]
  _BYTE v10[16]; // [rsp+30h] [rbp-428h] BYREF
  WCHAR String[512]; // [rsp+40h] [rbp-418h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBoardManager::LoadRandomBonusBoardFromResources", 0);
  do
  {
    RandomNumber = GetRandomNumber(iBonusBoardListCount);
    v5 = RandomNumber;
  }
  while ( (unsigned int)fPrevSeen(RandomNumber, (struct BOARDHIST *)&g_bhPrevBonusBoards, iBonusBoardListCount) );
  v6 = (unsigned __int8 *)&g_BoardData + *((int *)paBonusBoardList + 129 * v5);
  v7 = v6[1] + (*v6 << 8);
  memcpy(&byte_4DA740, v6 + 2, v7);
  if ( v7 <= 0x1000 )
    memcpy(&g_pLastLoadedLevel, &byte_4DA740, v7);
  *a3 = -1;
  Helpers::LoadStringW(0, (HINSTANCE)0x3A98, String, (unsigned __int16 *)0x200, 0, v9);
  MainWindowHwnd = GetMainWindowHwnd();
  SetWindowTextW(MainWindowHwnd, String);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
}
