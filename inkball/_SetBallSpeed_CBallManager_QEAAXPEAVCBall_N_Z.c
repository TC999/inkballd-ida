void __fastcall CBallManager::SetBallSpeed(CBallManager *this, struct CBall *a2, double a3)
{
  double v5; // xmm6_8
  int v6; // ecx
  int v7; // eax
  double v8; // xmm7_8
  double v9; // xmm1_8
  double v10; // xmm6_8
  double v11; // xmm0_8
  _BYTE v12[48]; // [rsp+20h] [rbp-58h] BYREF

  v5 = a3;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CBallManager::SetBallSpeed", 0);
  v6 = *((_DWORD *)this + 634);
  v7 = *((_DWORD *)this + 633);
  if ( v6 == v7 )
    v8 = (double)v6;
  else
    v8 = (double)(int)(*((_DWORD *)this + 633) + GetRandomNumber(v6 - v7));
  if ( a3 == -1.0 )
  {
    v9 = (double)(int)GetRandomNumber(100) / 100.0 * v8;
    *((double *)a2 + 9) = v9;
    *((double *)a2 + 10) = sqrt(v8 * v8 - v9 * v9);
    if ( (unsigned int)GetRandomNumber(2) )
      *((double *)a2 + 9) = -0.0 - *((double *)a2 + 9);
    if ( (unsigned int)GetRandomNumber(2) )
    {
      v10 = -0.0 - *((double *)a2 + 10);
LABEL_19:
      *((double *)a2 + 10) = v10;
    }
  }
  else
  {
    if ( a3 == 0.0 )
      v5 = 360.0;
    if ( v5 > 90.0 )
    {
      if ( v5 > 180.0 )
      {
        if ( v5 > 270.0 )
        {
          *((double *)a2 + 9) = -0.0 - sind(360.0 - v5) * v8;
          v10 = -0.0 - cosd(360.0 - v5) * v8;
          goto LABEL_19;
        }
        *((double *)a2 + 9) = -0.0 - cosd(270.0 - v5) * v8;
        v11 = sind(270.0 - v5);
      }
      else
      {
        *((double *)a2 + 9) = sind(180.0 - v5) * v8;
        v11 = cosd(180.0 - v5);
      }
      *((double *)a2 + 10) = v11 * v8;
    }
    else
    {
      *((double *)a2 + 9) = cosd(90.0 - v5) * v8;
      *((double *)a2 + 10) = -0.0 - sind(90.0 - v5) * v8;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
}
