HWND GetMainWindowHwnd(void)
{
  __int64 v0; // rbx
  _BYTE v2[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "GetMainWindowHwnd", 0);
  v0 = *((_QWORD *)g_pCGameBoard + 1892);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return (HWND)v0;
}
