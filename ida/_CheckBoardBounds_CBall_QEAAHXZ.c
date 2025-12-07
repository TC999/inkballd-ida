__int64 __fastcall CBall::CheckBoardBounds(CBall *this)
{
  unsigned int v2; // esi
  int v3; // ebx
  int v4; // r13d
  int v5; // r12d
  int v6; // ebp
  double v7; // xmm1_8
  int v8; // r12d
  double v9; // xmm1_8
  double v10; // xmm0_8
  int v11; // ebp
  double v12; // xmm2_8
  _BYTE v14[16]; // [rsp+20h] [rbp-38h] BYREF
  _BYTE v15[40]; // [rsp+30h] [rbp-28h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CBall::CheckBoardBounds", 0);
  v2 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "GetBoardRect", 0);
  v3 = *((_DWORD *)g_pCGameBoard + 3766);
  v4 = *((_DWORD *)g_pCGameBoard + 3767);
  v5 = *((_DWORD *)g_pCGameBoard + 3764);
  v6 = *((_DWORD *)g_pCGameBoard + 3765);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  v7 = *((double *)this + 1);
  if ( (double)v3 <= v7 )
  {
    v8 = v5 - *((_DWORD *)this + 6);
    if ( v7 <= (double)v8 )
      goto LABEL_6;
    *((double *)this + 9) = -0.0 - *((double *)this + 9);
    *((double *)this + 1) = (double)(v8 - 1);
  }
  else
  {
    *((double *)this + 1) = (double)v3;
    *((double *)this + 9) = -0.0 - *((double *)this + 9);
  }
  v2 = 1;
LABEL_6:
  v9 = *((double *)this + 2);
  v10 = (double)v4;
  if ( (double)v4 > v9 )
  {
LABEL_9:
    v12 = -0.0 - *((double *)this + 10);
    *((double *)this + 2) = v10;
    v2 = 1;
    *((double *)this + 10) = v12;
    goto LABEL_10;
  }
  v11 = v6 - *((_DWORD *)this + 7);
  if ( v9 > (double)v11 )
  {
    v10 = (double)(v11 - 1);
    goto LABEL_9;
  }
LABEL_10:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
  return v2;
}
