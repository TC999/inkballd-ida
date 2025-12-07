struct CBall *__fastcall CGameBoard::GetBall(CGameBoard *this, int a2)
{
  CGameBoard *v2; // rbx
  __int64 v3; // rdi
  __int64 v4; // rbx
  _BYTE v6[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = g_pCGameBoard;
  v3 = a2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::GetBall", 0);
  v4 = *((_QWORD *)v2 + v3 + 657);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (struct CBall *)v4;
}
