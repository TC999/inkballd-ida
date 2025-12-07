// Hidden C++ exception states: #wind=1
void __fastcall CBoardTileDrain::DeflectBall(CBoardTileDrain *this, struct CBall *a2)
{
  int v4; // r11d
  LONG right; // ebp
  LONG bottom; // ebx
  int v7; // r12d
  int v8; // ebp
  double v9; // xmm6_8
  int v10; // ebx
  int v11; // edx
  __int64 v12; // rcx
  double v13; // xmm4_8
  int v14; // eax
  struct tagRECT v15; // [rsp+28h] [rbp-50h] BYREF
  _BYTE v16[24]; // [rsp+38h] [rbp-40h] BYREF
  struct tagPOINT v17; // [rsp+80h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CBoardTileDrain::DeflectBall", 0);
  CBoardObject::GetBoundingRect(this, &v15);
  v4 = *((_DWORD *)this + 19);
  if ( v4 == 2 || v4 == 4 )
    right = v15.right;
  else
    right = v15.left;
  if ( v4 == 2 || v4 == 3 )
    bottom = v15.bottom;
  else
    bottom = v15.top;
  CBoardObject::GetCenterPoint(a2, &v17);
  v7 = v17.x - right;
  v8 = v17.y - bottom;
  v9 = sqrt((double)(v7 * v7 + v8 * v8));
  if ( v9 > 42.0 )
    v10 = *((_DWORD *)a2 + 12) + 2;
  else
    v10 = *((_DWORD *)a2 + 12) + 7;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v15, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v15);
  *((_QWORD *)a2 + 4) = &g_CBitmapRects[4 * v10];
  if ( (double)*((int *)a2 + 6) * 0.5 + v9 > 12.0 )
  {
    if ( v9 <= 32.0 )
    {
      v13 = 1.0 / (v9 * v9);
      *((double *)a2 + 9) = *((double *)a2 + 9) * 0.993 - (double)v7 * v13 * 25.0;
      *((double *)a2 + 10) = *((double *)a2 + 10) * 0.993 - (double)v8 * v13 * 25.0;
      v14 = Round(0.0 - 3.0 / v9 * 8.0);
      CBall::SetTallness(a2, v14);
    }
  }
  else
  {
    v11 = *((_DWORD *)this + 12);
    if ( v11 != *((_DWORD *)a2 + 12) && v11 && *((_DWORD *)a2 + 12) )
    {
      KillPlayer(1);
    }
    else
    {
      ScoreBall(a2);
      *((_DWORD *)a2 + 43) = 0;
      v12 = *((unsigned int *)this + 12);
      if ( (_DWORD)v12 && *((_DWORD *)a2 + 12) )
        ToggleRLWalls(v12);
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
}
