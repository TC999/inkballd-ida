__int64 __fastcall CBall::Collide(CBall *this, struct CBall *a2)
{
  unsigned int v4; // esi
  BOOL v5; // ebp
  BOOL v6; // ebp
  double v7; // xmm8_8
  double v8; // xmm0_8
  double v9; // xmm7_8
  double v10; // xmm8_8
  double v11; // xmm0_8
  double v12; // xmm4_8
  double v13; // xmm3_8
  double v14; // xmm5_8
  double v15; // xmm2_8
  double v16; // xmm7_8
  double v17; // xmm8_8
  double v18; // xmm6_8
  __int64 v19; // rax
  _BYTE v21[16]; // [rsp+20h] [rbp-58h] BYREF
  _BYTE v22[32]; // [rsp+30h] [rbp-48h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v22, "CBall::Collide", 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CBall::BallsIntersect", 0);
  v4 = 1;
  v5 = (double)*((int *)a2 + 6) * 0.5 + (double)*((int *)this + 6) * 0.5 > sqrt(
                                                                             (*((double *)this + 2) - *((double *)a2 + 2))
                                                                           * (*((double *)this + 2) - *((double *)a2 + 2))
                                                                           + (*((double *)this + 1) - *((double *)a2 + 1))
                                                                           * (*((double *)this + 1) - *((double *)a2 + 1)));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
  if ( v5 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CBall::MovingTowards", 0);
    v6 = (*((double *)a2 + 1) - *((double *)this + 1)) * *((double *)this + 9)
       + (*((double *)a2 + 2) - *((double *)this + 2)) * *((double *)this + 10) > 0.0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
    if ( v6 )
    {
      v7 = (double)*((int *)this + 6) * 0.5;
      v8 = (double)*((int *)a2 + 6) * 0.5;
      v9 = v7 + *((double *)this + 1) - (v8 + *((double *)a2 + 1));
      v10 = v7 + *((double *)this + 2) - (v8 + *((double *)a2 + 2));
      v11 = sqrt(v10 * v10 + v9 * v9);
      v12 = *((double *)this + 10);
      v13 = *((double *)this + 9);
      v14 = *((double *)this + 8);
      v15 = *((double *)a2 + 8);
      v16 = v9 / v11;
      v17 = v10 / v11;
      v18 = (v13 * v16 + v12 * v17 - (v17 * *((double *)a2 + 10) + v16 * *((double *)a2 + 9))) * 2.0 / (v14 + v15);
      *((double *)this + 9) = v13 - v15 * v18 * v16;
      *((double *)this + 10) = v12 - v18 * *((double *)a2 + 8) * v17;
      v19 = *((unsigned int *)a2 + 45);
      *((double *)a2 + 9) = v14 * v18 * v16 + *((double *)a2 + 9);
      *((double *)a2 + 10) = v18 * *((double *)this + 8) * v17 + *((double *)a2 + 10);
      *((_DWORD *)this + v19 + 46) = 1;
      *((_DWORD *)a2 + *((unsigned int *)this + 45) + 46) = 1;
    }
  }
  else
  {
    *((_DWORD *)this + *((unsigned int *)a2 + 45) + 46) = 0;
    *((_DWORD *)a2 + *((unsigned int *)this + 45) + 46) = 0;
    v4 = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v22);
  return v4;
}
