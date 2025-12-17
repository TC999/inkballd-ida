// Hidden C++ exception states: #wind=1
__int64 __fastcall CGameBoard::ShadowizeTile(CGameBoard *this, struct CBoardTile *a2)
{
  CGameBoard *v3; // rdi
  int v4; // ebx
  __int64 v5; // rbx
  struct tagRECT v7; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v8[16]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v9[32]; // [rsp+48h] [rbp-20h] BYREF
  int v10; // [rsp+88h] [rbp+20h] BYREF

  v3 = g_pCGameBoard;
  v10 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::ShadowizeTile", &v10);
  CBoardObject::GetBoundingRect(a2, &v7);
  v4 = CGameBoard::BltBoardToInk(v3, &v7, 1);
  v10 = v4;
  if ( v4 >= 0 )
  {
    CGameBoard::AddDisplayUpdateRect(v3, &v7);
    v5 = *((_QWORD *)v3 + 1893);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CInk::SetInkRedrawFlag", 0);
    *(_DWORD *)(v5 + 20) = 1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
    v10 = 0;
    v4 = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return (unsigned int)v4;
}
