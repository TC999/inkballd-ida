__int64 __fastcall CBall::VerifyCollision(CBall *this, struct tagRECT *a2, struct tagPOINT *a3)
{
  int v6; // esi
  LONG x; // ebx
  LONG y; // r12d
  unsigned int v9; // edi
  struct BallPoint *Point; // rax
  LONG v11; // ecx
  LONG v12; // edx
  _BYTE v14[56]; // [rsp+20h] [rbp-38h] BYREF
  struct tagPOINT v15; // [rsp+60h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CBall::VerifyCollision", 0);
  CBoardObject::GetCenterPoint(this, &v15);
  v6 = 0;
  if ( *((int *)this + 36) <= 0 )
  {
LABEL_5:
    v9 = 0;
  }
  else
  {
    x = v15.x;
    y = v15.y;
    v9 = 1;
    while ( 1 )
    {
      Point = CBall::GetPoint(this, v6);
      v11 = x + *(_DWORD *)Point;
      a3->x = v11;
      v12 = y + *((_DWORD *)Point + 1);
      a3->y = v12;
      if ( PointInRect(v11, v12, a2) )
        break;
      if ( ++v6 >= *((_DWORD *)this + 36) )
        goto LABEL_5;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v9;
}
