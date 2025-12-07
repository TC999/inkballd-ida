__int64 __fastcall CGameBoard::BallOnTile(CGameBoard *this, struct CBoardTile *a2)
{
  CGameBoard *v2; // rbp
  int v4; // esi
  CBoardObject **v5; // rdi
  unsigned int v6; // ebx
  struct tagRECT v8; // [rsp+20h] [rbp-48h] BYREF
  struct tagRECT v9; // [rsp+30h] [rbp-38h] BYREF
  _BYTE v10[16]; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v11[16]; // [rsp+50h] [rbp-18h] BYREF

  v2 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CGameBoard::BallOnTile", 0);
  CBoardObject::GetBoundingRect(a2, &v9);
  v4 = 0;
  if ( *((int *)v2 + 1312) > 0 )
  {
    v5 = (CBoardObject **)((char *)v2 + 5256);
    v6 = 1;
    do
    {
      if ( *((_DWORD *)*v5 + 43) )
      {
        CBoardObject::GetBoundingRect(*v5, &v8);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "RectIntersectsRect", 0);
        NormalizeRect(&v8);
        NormalizeRect(&v9);
        if ( PointInRect(v8.left, v8.top, &v9)
          || PointInRect(v8.right, v8.top, &v9)
          || PointInRect(v8.left, v8.bottom, &v9)
          || PointInRect(v8.right, v8.bottom, &v9) )
        {
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
          goto LABEL_11;
        }
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
      }
      ++v4;
      ++v5;
    }
    while ( v4 < *((_DWORD *)v2 + 1312) );
  }
  v6 = 0;
LABEL_11:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v6;
}
