// Hidden C++ exception states: #wind=2
void __fastcall CGameBoard::ResetBoard(CGameBoard *this)
{
  CGameBoard *v1; // rdi
  CBall **v2; // rbx
  __int64 v3; // rsi
  void **v4; // rbx
  __int64 v5; // rsi
  CDisplay *v6; // rbx
  _BYTE v7[16]; // [rsp+30h] [rbp-B8h] BYREF
  _BYTE v8[16]; // [rsp+40h] [rbp-A8h] BYREF
  __int64 v9; // [rsp+50h] [rbp-98h]
  _DWORD v10[32]; // [rsp+60h] [rbp-88h] BYREF
  CGameBoard *v11; // [rsp+F0h] [rbp+8h] BYREF

  v11 = this;
  v9 = -2;
  v1 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CGameBoard::ResetBoard", 0);
  *(_DWORD *)v1 = 0;
  memset((char *)v1 + 8, 0, 0x960u);
  *((_DWORD *)v1 + 602) = 0;
  memset((char *)v1 + 2416, 0, 0x200u);
  *((_DWORD *)v1 + 732) = 0;
  memset((char *)v1 + 2936, 0, 0x908u);
  *((_DWORD *)v1 + 1312) = 0;
  v2 = (CBall **)((char *)v1 + 5256);
  v3 = 64;
  do
  {
    if ( *v2 )
    {
      CBall::Release(*v2);
      *v2 = 0;
    }
    ++v2;
    --v3;
  }
  while ( v3 );
  *((_DWORD *)v1 + 3772) = 0;
  v4 = (void **)((char *)v1 + 5768);
  v5 = 289;
  do
  {
    if ( *v4 )
    {
      operator delete(*v4);
      *v4 = 0;
    }
    ++v4;
    --v5;
  }
  while ( v5 );
  CInk::ClearInk(*((CInk **)v1 + 1893));
  CDisplay::ClearInk(g_pDisplay, 0, 0);
  v6 = g_pDisplay;
  LODWORD(v11) = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CDisplay::Clear", (int *)&v11);
  if ( *((_QWORD *)v6 + 6) )
  {
    memset(v10, 0, sizeof(v10));
    v10[0] = 128;
    v10[26] = 0;
    LODWORD(v11) = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, int, _DWORD *))(**((_QWORD **)v6 + 3)
                                                                                            + 40LL))(
                     *((_QWORD *)v6 + 3),
                     0,
                     0,
                     0,
                     1024,
                     v10);
  }
  else
  {
    LODWORD(v11) = -2147467261;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
