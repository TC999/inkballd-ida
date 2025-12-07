void __fastcall CBallManager::UpdateBallPositions(CBallManager *this, int a2)
{
  __int64 v4; // rax
  double v5; // xmm3_8
  int v6; // r8d
  char *v7; // rdx
  __int64 v8; // r9
  __int64 v9; // rcx
  _BYTE v10[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBallManager::UpdateBallPositions", 0);
  v4 = *((_QWORD *)this + 8);
  v5 = (double)a2 / 1000.0;
  if ( *(double *)(v4 + 8) > 6.0 )
  {
    *(double *)(v4 + 72) = *(double *)(v4 + 72) - 6.0;
    *(double *)(*((_QWORD *)this + 8) + 8LL) = v5 * *(double *)(*((_QWORD *)this + 8) + 72LL)
                                             + *(double *)(*((_QWORD *)this + 8) + 8LL);
    *(double *)(*((_QWORD *)this + 8) + 16LL) = v5 * *(double *)(*((_QWORD *)this + 8) + 80LL)
                                              + *(double *)(*((_QWORD *)this + 8) + 16LL);
  }
  else
  {
    *(_QWORD *)(v4 + 72) = 0;
    *(_QWORD *)(*((_QWORD *)this + 8) + 8LL) = 0x4018000000000000LL;
  }
  v6 = 5;
  v7 = (char *)this + 72;
  v8 = 5;
  do
  {
    v9 = *(_QWORD *)v7;
    if ( (double)*(int *)(*((_QWORD *)v7 - 1) + 24LL) + *(double *)(*((_QWORD *)v7 - 1) + 8LL) + 0.0 < *(double *)(*(_QWORD *)v7 + 8LL) )
    {
      *(double *)(v9 + 72) = *(double *)(v9 + 72) - (double)v6;
      *(double *)(*(_QWORD *)v7 + 8LL) = v5 * *(double *)(*(_QWORD *)v7 + 72LL) + *(double *)(*(_QWORD *)v7 + 8LL);
      *(double *)(*(_QWORD *)v7 + 16LL) = v5 * *(double *)(*(_QWORD *)v7 + 80LL) + *(double *)(*(_QWORD *)v7 + 16LL);
    }
    else
    {
      *(_QWORD *)(v9 + 72) = 0;
      *(double *)(*(_QWORD *)v7 + 8LL) = (double)*(int *)(*((_QWORD *)v7 - 1) + 24LL)
                                       + *(double *)(*((_QWORD *)v7 - 1) + 8LL)
                                       + 0.0;
    }
    --v6;
    v7 += 8;
    --v8;
  }
  while ( v8 );
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
}
