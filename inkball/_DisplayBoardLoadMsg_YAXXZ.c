void __noreturn DisplayBoardLoadMsg(void)
{
  int *v0; // [rsp+28h] [rbp-2B0h]
  int *v1; // [rsp+28h] [rbp-2B0h]
  _BYTE v2[16]; // [rsp+30h] [rbp-2A8h] BYREF
  WCHAR Caption[64]; // [rsp+40h] [rbp-298h] BYREF
  WCHAR Text[256]; // [rsp+C0h] [rbp-218h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "DisplayBoardLoadMsg", 0);
  Helpers::LoadStringW(0, (HINSTANCE)0x3AA3, Caption, (unsigned __int16 *)0x40, 0, v0);
  Helpers::LoadStringW(0, (HINSTANCE)0x3AA4, Text, (unsigned __int16 *)0x100, 0, v1);
  MessageBoxW(0, Text, Caption, 0x30u);
  exit(0);
}
