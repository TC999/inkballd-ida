// Hidden C++ exception states: #wind=1
__int64 __fastcall CGameBoard::BltBall(CGameBoard *this, struct CBall *a2, struct IDirectDrawSurface7 *a3)
{
  struct CSurface *v5; // rbx
  __int64 v6; // rbx
  _BYTE v8[16]; // [rsp+38h] [rbp-40h] BYREF
  struct tagRECT v9; // [rsp+48h] [rbp-30h] BYREF
  _BYTE v10[24]; // [rsp+58h] [rbp-20h] BYREF
  int v11; // [rsp+88h] [rbp+10h] BYREF

  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::BltBall", &v11);
  CBoardObject::GetBoundingRect(a2, &v9);
  v5 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSurface::GetDDrawSurface", 0);
  v6 = *(_QWORD *)v5;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  LODWORD(v6) = ((__int64 (__fastcall *)(struct IDirectDrawSurface7 *, struct tagRECT *, __int64, _QWORD, int, _QWORD, __int64))a3->lpVtbl->Blt)(
                  a3,
                  &v9,
                  v6,
                  *((_QWORD *)a2 + 4),
                  0x8000,
                  0,
                  -2);
  v11 = v6;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return (unsigned int)v6;
}
