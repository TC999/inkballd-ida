__int64 __fastcall CBoardTileOWF::CareAboutCollisions(int *a1, __int64 a2, int *a3)
{
  int v6; // eax
  unsigned int v7; // ebp
  int v8; // edx
  double v9; // xmm0_8
  bool v10; // cc
  int v11; // eax
  struct tagRECT v13; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v14[24]; // [rsp+30h] [rbp-18h] BYREF
  struct tagPOINT v15; // [rsp+50h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CBoardTileOWF::CareAboutCollisions", 0);
  CBoardObject::GetCenterPoint((CBoardObject *)a1, &v15);
  CBoardObject::GetCenterPoint((CBoardObject *)a2, &v15);
  CBoardObject::GetBoundingRect((CBoardObject *)a1, &v13);
  v6 = a1[24];
  v7 = 2;
  v8 = (int)((double)a1[6] / 1.6);
  if ( !v6 )
  {
    v13.bottom -= v8;
    if ( v15.y < (v13.bottom + v13.top) / 2 )
    {
      v9 = *(double *)(a2 + 80);
LABEL_4:
      v10 = v9 <= 0.0;
      goto LABEL_14;
    }
    goto LABEL_15;
  }
  if ( v6 == 1 )
  {
    v13.top += v8;
    if ( v15.y <= (v13.top + v13.bottom) / 2 )
      goto LABEL_15;
    v10 = *(double *)(a2 + 80) >= 0.0;
LABEL_14:
    if ( !v10 )
      goto LABEL_20;
    goto LABEL_15;
  }
  if ( v6 != 2 )
  {
    if ( v6 != 3 )
    {
LABEL_19:
      v7 = 0;
      goto LABEL_20;
    }
    v13.left += v8;
    if ( v15.x <= (v13.left + v13.right) / 2 )
      goto LABEL_15;
    v10 = *(double *)(a2 + 72) >= 0.0;
    goto LABEL_14;
  }
  v13.right -= v8;
  if ( v15.x < (v13.right + v13.left) / 2 )
  {
    v9 = *(double *)(a2 + 72);
    goto LABEL_4;
  }
LABEL_15:
  v11 = a1[12];
  if ( !v11 || v11 == *(_DWORD *)(a2 + 48) || a3 && !PointInRect(*a3, a3[1], &v13) )
    goto LABEL_19;
LABEL_20:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v7;
}
