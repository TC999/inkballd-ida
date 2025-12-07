// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::Blt(
        CDisplay *this,
        unsigned int a2,
        unsigned int a3,
        struct IDirectDrawSurface7 *a4,
        struct tagRECT *a5,
        unsigned int a6)
{
  unsigned int v10; // ebx
  _BYTE v12[32]; // [rsp+38h] [rbp-20h] BYREF
  unsigned int v13; // [rsp+60h] [rbp+8h] BYREF

  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CDisplay::Blt", (int *)&v13);
  if ( *((_QWORD *)this + 3) )
  {
    v10 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, struct IDirectDrawSurface7 *, struct tagRECT *, unsigned int, __int64))(**((_QWORD **)this + 3) + 56LL))(
            *((_QWORD *)this + 3),
            a2,
            a3,
            a4,
            a5,
            a6,
            -2);
    v13 = v10;
  }
  else
  {
    v10 = -2147467261;
    v13 = -2147467261;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
  return v10;
}
