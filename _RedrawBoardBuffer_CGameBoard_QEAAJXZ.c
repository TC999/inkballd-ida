// Hidden C++ exception states: #wind=2
__int64 __fastcall CGameBoard::RedrawBoardBuffer(CGameBoard *this)
{
  int v2; // edi
  __int64 v3; // rbp
  int v4; // eax
  int v5; // r12d
  __int64 i; // r13
  struct CBoardTile *v7; // rbx
  __int64 v8; // rbp
  int v9; // ebx
  CDisplay *v10; // rbx
  __int64 v11; // rdi
  struct CSurface *v12; // rbx
  __int64 v13; // rbx
  int v14; // eax
  int v15; // eax
  _BYTE v17[16]; // [rsp+30h] [rbp-118h] BYREF
  _BYTE v18[16]; // [rsp+40h] [rbp-108h] BYREF
  struct tagRECT v19; // [rsp+50h] [rbp-F8h] BYREF
  _BYTE v20[16]; // [rsp+60h] [rbp-E8h] BYREF
  __int64 v21; // [rsp+70h] [rbp-D8h]
  struct tagRECT v22; // [rsp+78h] [rbp-D0h] BYREF
  _DWORD v23[34]; // [rsp+90h] [rbp-B8h] BYREF
  int v24; // [rsp+150h] [rbp+8h] BYREF
  int v25; // [rsp+158h] [rbp+10h] BYREF

  v21 = -2;
  v24 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CGameBoard::RedrawBoardBuffer", &v24);
  v2 = 0;
  v3 = 0;
  if ( *((int *)this + 3769) > 0 )
  {
    v4 = *((_DWORD *)this + 3768);
    do
    {
      v5 = 0;
      for ( i = 0; v5 < v4; v4 = *((_DWORD *)this + 3768) )
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CGameBoard::GetTileByIndices", 0);
        v7 = (struct CBoardTile *)*((_QWORD *)this + i + v3 * *((int *)this + 3768) + 721);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
        CGameBoard::SetTile(this, v7);
        ++v5;
        ++i;
      }
      ++v2;
      ++v3;
    }
    while ( v2 < *((_DWORD *)this + 3769) );
  }
  v25 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CGameBoard::Shadowize", &v25);
  memset(v23, 0, sizeof(v23));
  v23[0] = 136;
  v8 = *((_QWORD *)this + 721);
  CBoardObject::GetBoundingRect((CBoardObject *)v8, &v22);
  if ( *((_DWORD *)this + 3774) == 1 )
  {
    v9 = CDisplay::BltToBoard(
           g_pDisplay,
           (int)*(double *)(v8 + 8),
           (int)*(double *)(v8 + 16),
           g_pGamePiecesSurface,
           *(struct tagRECT **)(v8 + 32));
    v25 = v9;
    if ( v9 < 0 )
    {
LABEL_8:
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
      goto LABEL_11;
    }
  }
  else
  {
    CBoardObject::GetBoundingRect((CBoardObject *)v8, &v19);
    v10 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CDisplay::GetBoardBuffer", 0);
    v11 = *((_QWORD *)v10 + 6);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
    v12 = g_pGamePiecesSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CSurface::GetDDrawSurface", 0);
    v13 = *(_QWORD *)v12;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
    v9 = (*(__int64 (__fastcall **)(__int64, struct tagRECT *, __int64, _QWORD, _DWORD, _QWORD))(*(_QWORD *)v11 + 40LL))(
           v11,
           &v19,
           v13,
           *(_QWORD *)(v8 + 32),
           0,
           0);
    v25 = v9;
    if ( v9 < 0 )
      goto LABEL_8;
  }
  v25 = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  v9 = 0;
LABEL_11:
  v24 = v9;
  if ( v9 >= 0 )
  {
    v14 = CGameBoard::BltBoardToInk(this, 0, 0);
    v24 = v14;
    if ( v14 >= 0 )
    {
      CInk::DrawInkToSurface(*((CInk **)this + 1893), 0);
      v15 = CDisplay::BltInk(g_pDisplay, 0);
      v24 = v15;
      if ( v15 >= 0 )
      {
        v24 = 0;
        v9 = 0;
      }
      else
      {
        v9 = v15;
      }
    }
    else
    {
      v9 = v14;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
  return (unsigned int)v9;
}
