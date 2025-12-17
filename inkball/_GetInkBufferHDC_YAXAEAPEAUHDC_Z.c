// Hidden C++ exception states: #wind=1
void __fastcall GetInkBufferHDC(HDC *a1)
{
  CDisplay *v2; // rbx
  __int64 v3; // rbx
  _BYTE v4[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v5[32]; // [rsp+38h] [rbp-20h] BYREF
  int v6; // [rsp+60h] [rbp+8h] BYREF

  v6 = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "GetInkBufferHDC", &v6);
  *a1 = 0;
  v2 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetInkBuffer", 0);
  v3 = *((_QWORD *)v2 + 5);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  if ( v3 )
    v6 = (*(__int64 (__fastcall **)(__int64, HDC *))(*(_QWORD *)v3 + 136LL))(v3, a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
