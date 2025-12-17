// Hidden C++ exception states: #wind=2
__int64 __fastcall CBall::CBall(__int64 a1, __int64 a2, int a3, int a4, int a5)
{
  BallPoints *v9; // rax
  int v10; // edi
  BallPoints *v11; // rax
  __int64 i; // rax
  CGameBoard *v13; // rdi
  __int64 v14; // rax
  _QWORD *v16; // rdx
  _QWORD v17[5]; // [rsp+0h] [rbp-88h] BYREF
  _BYTE v18[16]; // [rsp+28h] [rbp-60h] BYREF
  _BYTE v19[16]; // [rsp+38h] [rbp-50h] BYREF
  _BYTE v20[24]; // [rsp+48h] [rbp-40h] BYREF

  v17[4] = -2;
  *(_QWORD *)a1 = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CBoardObject::CBoardObject", 0);
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_DWORD *)(a1 + 24) = 32;
  *(_DWORD *)(a1 + 28) = 32;
  *(_QWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_QWORD *)(a1 + 56) = 0x3FF0000000000000LL;
  *(_QWORD *)(a1 + 64) = 0x3FF0000000000000LL;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
  *(_QWORD *)a1 = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CMovingObject::CMovingObject", 0);
  *(_QWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 80) = 0;
  *(_QWORD *)(a1 + 88) = 0;
  *(_QWORD *)(a1 + 96) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
  *(_QWORD *)a1 = &CBall::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CBall::CBall", 0);
  *(_DWORD *)(a1 + 148) = 0;
  try
  {
    v9 = (BallPoints *)operator new(8u);
    if ( v9 )
    {
      v10 = a5;
      v11 = BallPoints::BallPoints(v9, a5);
    }
    else
    {
      v11 = 0;
      v10 = a5;
    }
    *(_QWORD *)(a1 + 128) = v11;
  }
  catch ( std::bad_alloc )
  {
    v16 = v17;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v16) = 10;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v16, qword_401968);
    }
    throw;
  }
  *(_DWORD *)(a1 + 136) = -1;
  *(_DWORD *)(a1 + 140) = 0;
  *(_DWORD *)(a1 + 144) = 32;
  *(_DWORD *)(a1 + 152) = 0;
  *(_DWORD *)(a1 + 48) = a3;
  *(_QWORD *)(a1 + 32) = a2;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 24) = v10;
  *(_DWORD *)(a1 + 28) = v10;
  *(_DWORD *)(a1 + 120) = v10;
  *(_DWORD *)(a1 + 124) = v10;
  *(_DWORD *)(a1 + 172) = 0;
  *(_DWORD *)(a1 + 176) = 0;
  *(_QWORD *)(a1 + 160) = 0x3FF0000000000000LL;
  *(_QWORD *)(a1 + 64) = 0x3FF0000000000000LL;
  for ( i = 0; i < 64; ++i )
    *(_DWORD *)(a1 + 4 * i + 184) = 0;
  if ( a4 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v19, "AddBallToUpdateList", 0);
    v13 = g_pCGameBoard;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CGameBoard::AddBallToUpdateList", 0);
    v14 = *((int *)v13 + 602);
    if ( (int)v14 < 64 )
    {
      *((_QWORD *)v13 + v14 + 302) = a1;
      ++*((_DWORD *)v13 + 602);
    }
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v19);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
  return a1;
}
