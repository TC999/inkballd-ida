// Hidden C++ exception states: #wind=1
void __fastcall CInk::ClearInk(CInk *this)
{
  _BYTE v1[32]; // [rsp+28h] [rbp-20h] BYREF
  int v2; // [rsp+58h] [rbp+10h] BYREF
  unsigned int v3; // [rsp+60h] [rbp+18h] BYREF

  v2 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "CInk::ClearInk", &v2);
  v2 = (*(__int64 (__fastcall **)(struct IInkObject *, unsigned int *))(*(_QWORD *)g_pIInkObject + 32LL))(
         g_pIInkObject,
         &v3);
  if ( v2 >= 0 )
    v2 = (*(__int64 (__fastcall **)(struct IInkObject *, _QWORD, _QWORD))(*(_QWORD *)g_pIInkObject + 136LL))(
           g_pIInkObject,
           0,
           v3);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
