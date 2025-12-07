__int64 __fastcall BallOnTile(struct CBoardTile *a1)
{
  _BYTE v3[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "BallOnTile", 0);
  LODWORD(a1) = CGameBoard::BallOnTile(g_pCGameBoard, a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return (unsigned int)a1;
}
