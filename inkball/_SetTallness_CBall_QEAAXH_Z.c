// Hidden C++ exception states: #wind=3
void __fastcall CBall::SetTallness(CBall *this, int a2)
{
  int v4; // ecx
  BallPoints *v5; // rax
  BallPoints *v6; // rsi
  void **v7; // rdi
  _QWORD *v8; // rdx
  _QWORD v9[5]; // [rsp+0h] [rbp-58h] BYREF
  _BYTE v10[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v11[32]; // [rsp+38h] [rbp-20h] BYREF

  v9[4] = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBall::SetTallness", 0);
  v4 = a2 - *((_DWORD *)this + 38);
  if ( a2 != *((_DWORD *)this + 38) )
  {
    *((_DWORD *)this + 6) += 2 * v4;
    *((_DWORD *)this + 7) += 2 * v4;
    *((double *)this + 1) = *((double *)this + 1) - (double)v4;
    *((double *)this + 2) = *((double *)this + 2) - (double)v4;
    CBall::CheckBoardBounds(this);
    *((_DWORD *)this + 38) = a2;
    try
    {
      v5 = (BallPoints *)operator new(8u);
      if ( v5 )
        v6 = BallPoints::BallPoints(v5, *((_DWORD *)this + 6));
      else
        v6 = 0;
      v7 = (void **)*((_QWORD *)this + 16);
      if ( v7 )
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "BallPoints::~BallPoints", 0);
        if ( *v7 )
        {
          operator delete[](*v7);
          *v7 = 0;
        }
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
        operator delete(v7);
        *((_QWORD *)this + 16) = 0;
      }
      *((_QWORD *)this + 16) = v6;
    }
    catch ( std::bad_alloc )
    {
      v8 = v9;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LOWORD(v8) = 11;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v8, qword_401968);
      }
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
}
