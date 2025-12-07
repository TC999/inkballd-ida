__int64 __fastcall CBoardTileBumper::CareAboutCollisions(CBoardObject *a1, CBoardObject *a2, int *a3)
{
  unsigned int v6; // edi
  int v7; // edx
  int v8; // eax
  int v9; // eax
  struct tagRECT v11; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v12[24]; // [rsp+30h] [rbp-18h] BYREF
  struct tagPOINT v13; // [rsp+50h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CBoardTileBumper::CareAboutCollisions", 0);
  CBoardObject::GetCenterPoint(a1, &v13);
  CBoardObject::GetCenterPoint(a2, &v13);
  CBoardObject::GetBoundingRect(a1, &v11);
  v6 = 2;
  v7 = *((_DWORD *)a1 + 6) / 3;
  if ( *((_DWORD *)a1 + 24) )
  {
    if ( *((_DWORD *)a1 + 24) != 2 )
      goto LABEL_12;
    v9 = *((_DWORD *)a1 + 12);
    if ( !v9 || v9 == *((_DWORD *)a2 + 12) )
      goto LABEL_12;
    if ( !a3 )
      goto LABEL_13;
    v11.left += v7;
    v11.right -= v7;
    goto LABEL_11;
  }
  v8 = *((_DWORD *)a1 + 12);
  if ( !v8 || v8 == *((_DWORD *)a2 + 12) )
    goto LABEL_12;
  if ( a3 )
  {
    v11.top += v7;
    v11.bottom -= v7;
LABEL_11:
    if ( !PointInRect(*a3, a3[1], &v11) )
LABEL_12:
      v6 = 0;
  }
LABEL_13:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
  return v6;
}
