void __fastcall AddDisplayUpdateRect(struct tagRECT *a1)
{
  _BYTE v2[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "AddDisplayUpdateRect", 0);
  CGameBoard::AddDisplayUpdateRect(g_pCGameBoard, a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
