// Hidden C++ exception states: #wind=1
__int64 __fastcall CBall::Collide(CBall *this, int (*const a2)(const struct tagRECT *))
{
  int PrevBallPoint; // esi
  int v4; // r12d
  int v5; // r13d
  struct BallPoint *NextPoint; // r11
  unsigned int v7; // ebp
  LONG x; // ebx
  LONG y; // r14d
  int v10; // eax
  int *Point; // rax
  struct tagRECT v13; // [rsp+28h] [rbp-50h] BYREF
  _BYTE v14[24]; // [rsp+38h] [rbp-40h] BYREF
  struct tagPOINT v15; // [rsp+90h] [rbp+18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CBall::Collide", 0);
  CBall::InitBallPoints(this);
  PrevBallPoint = -1;
  v4 = -1;
  v5 = 0;
  CBoardObject::GetCenterPoint(this, &v15);
  NextPoint = CBall::GetNextPoint(this);
  if ( !NextPoint )
    goto LABEL_13;
  v7 = 1;
  x = v15.x;
  y = v15.y;
  do
  {
    v13.left = x + *(_DWORD *)NextPoint;
    v13.right = x + *(_DWORD *)NextPoint;
    v13.top = y + *((_DWORD *)NextPoint + 1);
    v13.bottom = y + *((_DWORD *)NextPoint + 1);
    if ( (unsigned int)InkHitTest(&v13) )
    {
      if ( PrevBallPoint == -1 )
      {
        PrevBallPoint = CBall::GetPrevBallPoint(this);
        v4 = PrevBallPoint;
      }
      else
      {
        v4 = CBall::GetPrevBallPoint(this);
      }
      v5 = 1;
    }
    NextPoint = CBall::GetNextPoint(this);
  }
  while ( NextPoint );
  if ( v5 )
  {
    v10 = (v4 + PrevBallPoint) / 2;
    if ( v4 < PrevBallPoint )
      v10 = (v10 + 16) % 32;
    Point = (int *)CBall::GetPoint(this, v10);
    CBall::Deflect(this, (double)*Point, (double)Point[1]);
  }
  else
  {
LABEL_13:
    v7 = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v7;
}
