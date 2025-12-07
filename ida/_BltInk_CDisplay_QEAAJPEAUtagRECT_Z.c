// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::BltInk(CDisplay *this, struct tagRECT *a2)
{
  CDisplay *v3; // rbx
  __int64 v4; // r8
  unsigned int v5; // ebx
  _BYTE v7[32]; // [rsp+38h] [rbp-20h] BYREF
  unsigned int v8; // [rsp+60h] [rbp+8h] BYREF
  int v9; // [rsp+64h] [rbp+Ch]

  v9 = HIDWORD(this);
  v3 = g_pDisplay;
  v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CDisplay::BltInk", (int *)&v8);
  if ( *((_QWORD *)v3 + 3) && (v4 = *((_QWORD *)v3 + 5)) != 0 )
  {
    v5 = (*(__int64 (__fastcall **)(_QWORD, struct tagRECT *, __int64, struct tagRECT *, int, _QWORD, __int64))(**((_QWORD **)v3 + 3) + 40LL))(
           *((_QWORD *)v3 + 3),
           a2,
           v4,
           a2,
           0x1000000,
           0,
           -2);
    v8 = v5;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    return v5;
  }
  else
  {
    v8 = -2147467261;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    return 2147500035LL;
  }
}
