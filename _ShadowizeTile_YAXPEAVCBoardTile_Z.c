// Hidden C++ exception states: #wind=1
void __fastcall ShadowizeTile(struct CBoardTile *a1)
{
  _BYTE v2[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "ShadowizeTile", 0);
  CGameBoard::ShadowizeTile(g_pCGameBoard, a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
