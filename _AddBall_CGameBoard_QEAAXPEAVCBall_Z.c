void __fastcall CGameBoard::AddBall(CGameBoard *this, struct CBall *a2)
{
  CGameBoard *v2; // rbx
  int v4; // eax
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::AddBall", 0);
  v4 = *((_DWORD *)v2 + 1312);
  if ( v4 < 64 )
  {
    *((_DWORD *)a2 + 45) = v4;
    *((_QWORD *)v2 + (*((_DWORD *)v2 + 1312))++ + 657) = a2;
    ++*((_DWORD *)v2 + 3772);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
