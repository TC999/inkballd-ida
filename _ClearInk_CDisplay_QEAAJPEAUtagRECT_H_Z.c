// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::ClearInk(CDisplay *this, struct tagRECT *a2)
{
  CDisplay *v3; // rbx
  unsigned int v4; // ebx
  _BYTE v6[32]; // [rsp+38h] [rbp-20h] BYREF
  unsigned int v7; // [rsp+60h] [rbp+8h] BYREF
  int v8; // [rsp+64h] [rbp+Ch]

  v8 = HIDWORD(this);
  v3 = g_pDisplay;
  v7 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CDisplay::ClearInk", (int *)&v7);
  if ( *((_QWORD *)v3 + 5) )
  {
    v4 = (*(__int64 (__fastcall **)(_QWORD, struct tagRECT *, _QWORD, struct tagRECT *, int, _QWORD, __int64))(**((_QWORD **)v3 + 5) + 40LL))(
           *((_QWORD *)v3 + 5),
           a2,
           *((_QWORD *)v3 + 6),
           a2,
           0x1000000,
           0,
           -2);
    v7 = v4;
  }
  else
  {
    v4 = -2147467261;
    v7 = -2147467261;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return v4;
}
