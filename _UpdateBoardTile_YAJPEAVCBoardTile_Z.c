// Hidden C++ exception states: #wind=1
__int64 __fastcall UpdateBoardTile(struct tagRECT **this)
{
  int v2; // ebx
  CDisplay *v3; // rbx
  __int64 v4; // rdi
  struct CSurface *v5; // rbx
  __int64 v6; // rbx
  struct tagRECT v8; // [rsp+38h] [rbp-40h] BYREF
  _BYTE v9[16]; // [rsp+48h] [rbp-30h] BYREF
  _BYTE v10[24]; // [rsp+58h] [rbp-20h] BYREF
  int v11; // [rsp+88h] [rbp+10h] BYREF

  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "UpdateBoardTile", &v11);
  CBoardObject::GetBoundingRect((CBoardObject *)this, &v8);
  if ( *((_DWORD *)g_pCGameBoard + 3774) == 1 )
  {
    v2 = CDisplay::BltToBoard(
           g_pDisplay,
           (int)*((double *)this + 1),
           (int)*((double *)this + 2),
           g_pGamePiecesSurface,
           this[4]);
  }
  else
  {
    v3 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CDisplay::GetBoardBuffer", 0);
    v4 = *((_QWORD *)v3 + 6);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    v5 = g_pGamePiecesSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CSurface::GetDDrawSurface", 0);
    v6 = *(_QWORD *)v5;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    v2 = (*(__int64 (__fastcall **)(__int64, struct tagRECT *, __int64, struct tagRECT *, _DWORD, _QWORD, __int64))(*(_QWORD *)v4 + 40LL))(
           v4,
           &v8,
           v6,
           this[4],
           0,
           0,
           -2);
  }
  v11 = v2;
  if ( v2 >= 0 )
  {
    v2 = BltBoardToInk(&v8);
    v11 = v2;
    if ( v2 >= 0 )
    {
      v2 = CDisplay::BltInk(g_pDisplay, &v8);
      v11 = v2;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return (unsigned int)v2;
}
