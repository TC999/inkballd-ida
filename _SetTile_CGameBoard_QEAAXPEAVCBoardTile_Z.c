// Hidden C++ exception states: #wind=1
void __fastcall CGameBoard::SetTile(CGameBoard *this, struct CBoardTile *a2)
{
  int v4; // eax
  CDisplay *v5; // rbx
  __int64 v6; // rdi
  struct CSurface *v7; // rbx
  __int64 v8; // rbx
  _BYTE v9[16]; // [rsp+38h] [rbp-40h] BYREF
  struct tagRECT v10; // [rsp+48h] [rbp-30h] BYREF
  _BYTE v11[24]; // [rsp+58h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CGameBoard::SetTile", 0);
  v4 = *((_DWORD *)a2 + 21) + *((_DWORD *)a2 + 22) * *((_DWORD *)this + 3768);
  if ( v4 < 289 )
    *((_QWORD *)this + v4 + 721) = a2;
  if ( *((_DWORD *)this + 3774) == 1 )
  {
    CDisplay::BltToBoard(
      g_pDisplay,
      (int)*((double *)a2 + 1),
      (int)*((double *)a2 + 2),
      g_pGamePiecesSurface,
      *((struct tagRECT **)a2 + 4));
  }
  else
  {
    CBoardObject::GetBoundingRect(a2, &v10);
    v5 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CDisplay::GetBoardBuffer", 0);
    v6 = *((_QWORD *)v5 + 6);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    v7 = g_pGamePiecesSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CSurface::GetDDrawSurface", 0);
    v8 = *(_QWORD *)v7;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    (*(void (__fastcall **)(__int64, struct tagRECT *, __int64, _QWORD, _DWORD, _QWORD, __int64))(*(_QWORD *)v6 + 40LL))(
      v6,
      &v10,
      v8,
      *((_QWORD *)a2 + 4),
      0,
      0,
      -2);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
}
