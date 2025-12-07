// Hidden C++ exception states: #wind=1
__int64 __fastcall SetCursorAttributes(unsigned int a1)
{
  unsigned int v2; // ebx
  int v4; // [rsp+20h] [rbp-38h] BYREF
  _QWORD v5[2]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v6[32]; // [rsp+38h] [rbp-20h] BYREF
  int v7; // [rsp+68h] [rbp+10h] BYREF
  float v8; // [rsp+70h] [rbp+18h] BYREF
  int v9; // [rsp+78h] [rbp+20h] BYREF

  v5[1] = -2;
  v2 = 0;
  v7 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "SetCursorAttributes", &v7);
  v5[0] = 0;
  v7 = (*(__int64 (__fastcall **)(struct IInkObject *, _QWORD, _QWORD *))(*(_QWORD *)g_pIInkObject + 88LL))(
         g_pIInkObject,
         a1,
         v5);
  if ( v7 >= 0 )
  {
    v8 = FLOAT_100_0;
    v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, float *))(*(_QWORD *)v5[0] + 24LL))(
           v5[0],
           *(_QWORD *)&GUID_PEN_WIDTH.Data1,
           4,
           &v8);
    v9 = 20;
    v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, int *))(*(_QWORD *)v5[0] + 24LL))(
           v5[0],
           *(_QWORD *)&GUID_DRAWING_FLAGS.Data1,
           4,
           &v9);
    v4 = 0;
    v7 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, __int64, int *))(*(_QWORD *)v5[0] + 24LL))(
           v5[0],
           *(_QWORD *)GUID_PEN_STYLE.Data4,
           4,
           &v4);
    v7 = (*(__int64 (__fastcall **)(struct IInkObject *, _QWORD, _QWORD))(*(_QWORD *)g_pIInkObject + 80LL))(
           g_pIInkObject,
           a1,
           v5[0]);
    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)v5[0] + 16LL))(v5[0]);
  }
  else
  {
    v2 = -1;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return v2;
}
