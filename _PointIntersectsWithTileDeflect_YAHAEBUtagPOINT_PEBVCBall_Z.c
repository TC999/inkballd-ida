// Hidden C++ exception states: #wind=1
__int64 __fastcall PointIntersectsWithTileDeflect(const struct tagPOINT *a1, const struct CBall *a2)
{
  _BYTE v5[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "PointIntersectsWithTileDeflect", 0);
  LODWORD(a2) = CGameBoard::PointIntersectsWithTile(g_pCGameBoard, a1, a2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (unsigned int)a2;
}
