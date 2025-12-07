// Hidden C++ exception states: #wind=1
_BOOL8 __fastcall CGameBoard::PointIntersectsWithTile(
        CGameBoard *this,
        const struct tagPOINT *a2,
        const struct CBall *a3)
{
  CGameBoard *v5; // rbx
  struct CBoardTile *Tile; // rdi
  BOOL v8; // ebx
  _BYTE v9[32]; // [rsp+28h] [rbp-20h] BYREF

  v5 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::PointIntersectsWithTile", 0);
  Tile = CGameBoard::GetTile(v5, a2->x, a2->y);
  if ( (*(unsigned int (__fastcall **)(struct CBoardTile *, const struct CBall *, const struct tagPOINT *))(*(_QWORD *)Tile + 16LL))(
         Tile,
         a3,
         a2) )
  {
    v8 = (*(__int64 (__fastcall **)(struct CBoardTile *, const struct CBall *, const struct tagPOINT *))(*(_QWORD *)Tile + 16LL))(
           Tile,
           a3,
           a2) != 1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    return v8;
  }
  else
  {
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    return 0;
  }
}
