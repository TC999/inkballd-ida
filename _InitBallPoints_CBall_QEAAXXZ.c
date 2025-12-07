void __fastcall CBall::InitBallPoints(CBall *this)
{
  __int64 v2; // rdx
  int v3; // r8d
  int *v4; // rcx
  int v5; // eax
  float v6; // xmm3_4
  float v7; // xmm2_4
  _BYTE v8[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBall::InitBallPoints", 0);
  v2 = *((_QWORD *)this + 16);
  v3 = 0;
  v4 = (int *)(*(_QWORD *)v2 + 8LL);
  v5 = 1;
  v6 = (double)*(int *)(*(_QWORD *)v2 + 4LL) * *((double *)this + 10) + (double)**(int **)v2 * *((double *)this + 9);
  do
  {
    v7 = (double)v4[1] * *((double *)this + 10) + (double)*v4 * *((double *)this + 9);
    if ( v7 > v6 )
    {
      v6 = (double)v4[1] * *((double *)this + 10) + (double)*v4 * *((double *)this + 9);
      v3 = v5;
    }
    ++v5;
    v4 += 2;
  }
  while ( v5 < 32 );
  *((_DWORD *)this + 34) = v3 - 8;
  if ( v3 - 8 < 0 )
    *((_DWORD *)this + 34) = v3 - 8 + 32;
  *((_DWORD *)this + 35) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
