void __fastcall __noreturn CGameManager::CGameManager_::_1_::catch_0(__int64 a1, __int64 a2)
{
  CGameBoard *v2; // rdi

  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    LOWORD(a2) = 10;
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, qword_401918);
  }
  v2 = g_pCGameBoard;
  if ( g_pCGameBoard )
  {
    CGameBoard::~CGameBoard(g_pCGameBoard);
    operator delete(v2);
    g_pCGameBoard = 0;
  }
  throw;
}
