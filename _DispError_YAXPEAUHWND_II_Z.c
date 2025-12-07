void __fastcall DispError(HWND a1, __int64 a2, unsigned int a3)
{
  int *v5; // [rsp+28h] [rbp-20B0h]
  int *v6; // [rsp+28h] [rbp-20B0h]
  _BYTE v7[16]; // [rsp+30h] [rbp-20A8h] BYREF
  WCHAR Caption[64]; // [rsp+40h] [rbp-2098h] BYREF
  WCHAR Text[4096]; // [rsp+C0h] [rbp-2018h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "DispError", 0);
  Helpers::LoadStringW(0, (HINSTANCE)0x3AA3, Caption, (unsigned __int16 *)0x40, 0, v5);
  Helpers::LoadStringW(0, (HINSTANCE)a3, Text, (unsigned __int16 *)0x1000, 0, v6);
  MessageBoxW(a1, Text, Caption, 0x10u);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
