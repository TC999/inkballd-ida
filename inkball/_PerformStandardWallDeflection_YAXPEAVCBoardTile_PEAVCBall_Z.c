// Hidden C++ exception states: #wind=2
void __fastcall PerformStandardWallDeflection(struct CBoardTile *a1, struct CBall *a2)
{
  int PrevBallPoint; // edi
  int v4; // ebp
  int v5; // r12d
  struct BallPoint *NextPoint; // r11
  LONG x; // ebx
  LONG y; // r13d
  int v9; // eax
  int *Point; // rax
  _BYTE v11[16]; // [rsp+28h] [rbp-50h] BYREF
  _BYTE v12[64]; // [rsp+38h] [rbp-40h] BYREF
  struct tagPOINT v13; // [rsp+90h] [rbp+18h] BYREF
  struct tagPOINT v14; // [rsp+98h] [rbp+20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "PerformStandardWallDeflection", 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBall::Collide", 0);
  CBall::InitBallPoints(a2);
  PrevBallPoint = -1;
  v4 = -1;
  v5 = 0;
  CBoardObject::GetCenterPoint(a2, &v13);
  NextPoint = CBall::GetNextPoint(a2);
  if ( !NextPoint )
    goto LABEL_13;
  x = v13.x;
  y = v13.y;
  do
  {
    v14.x = x + *(_DWORD *)NextPoint;
    v14.y = y + *((_DWORD *)NextPoint + 1);
    if ( (unsigned int)PointIntersectsWithTileDeflect(&v14, a2) )
    {
      if ( PrevBallPoint == -1 )
      {
        PrevBallPoint = CBall::GetPrevBallPoint(a2);
        v4 = PrevBallPoint;
      }
      else
      {
        v4 = CBall::GetPrevBallPoint(a2);
      }
      v5 = 1;
    }
    NextPoint = CBall::GetNextPoint(a2);
  }
  while ( NextPoint );
  if ( v5 )
  {
    v9 = (v4 + PrevBallPoint) / 2;
    if ( v4 < PrevBallPoint )
      v9 = (v9 + 16) % 32;
    Point = (int *)CBall::GetPoint(a2, v9);
    CBall::Deflect(a2, (double)*Point, (double)Point[1]);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  }
  else
  {
LABEL_13:
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
}
