// Hidden C++ exception states: #wind=2
CGameManager *__fastcall CGameManager::CGameManager(CGameManager *this, HWND a2)
{
  void *v4; // rax
  CGameBoard *v5; // rax
  CGameBoard *v7; // rdi
  _QWORD *v8; // rdx
  _QWORD v9[5]; // [rsp+0h] [rbp-48h] BYREF
  _BYTE v10[32]; // [rsp+28h] [rbp-20h] BYREF

  v9[4] = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameManager::CGameManager", 0);
  g_pCGameBoard = 0;
  try
  {
    v4 = operator new(0x3B30u);
    if ( v4 )
      v5 = (CGameBoard *)CGameBoard::CGameBoard((__int64)v4, a2);
    else
      v5 = 0;
    g_pCGameBoard = v5;
  }
  catch ( std::bad_alloc )
  {
    v8 = v9;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v8) = 10;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v8, qword_401918);
    }
    v7 = g_pCGameBoard;
    if ( g_pCGameBoard )
    {
      CGameBoard::~CGameBoard(g_pCGameBoard);
      operator delete(v7);
      g_pCGameBoard = 0;
    }
    throw;
  }
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)this = timeGetTime();
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return this;
}
