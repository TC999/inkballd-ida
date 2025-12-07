void __fastcall CGameBoard::AddGameObjectToUpdateList(CGameBoard *this, struct CGameObject *a2)
{
  CGameBoard *v2; // rbx
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddGameObjectToUpdateList", 0);
  if ( *(int *)v2 < 300 )
    *((_QWORD *)v2 + ++*(_DWORD *)v2) = a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
