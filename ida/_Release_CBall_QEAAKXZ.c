// Hidden C++ exception states: #wind=3
__int64 __fastcall CBall::Release(CBall *this)
{
  bool v2; // zf
  unsigned int v3; // esi
  void **v4; // rdi
  _BYTE v6[16]; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v7[16]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v8[32]; // [rsp+48h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBall::Release", 0);
  v2 = (*((_DWORD *)this + 37))-- == 1;
  v3 = *((_DWORD *)this + 37);
  if ( v2 )
  {
    *(_QWORD *)this = &CBall::`vftable';
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBall::~CBall", 0);
    v4 = (void **)*((_QWORD *)this + 16);
    if ( v4 )
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "BallPoints::~BallPoints", 0);
      if ( *v4 )
      {
        operator delete[](*v4);
        *v4 = 0;
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
      operator delete(v4);
      *((_QWORD *)this + 16) = 0;
    }
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    operator delete(this);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v3;
}
