__int64 AcceptInkInput(void)
{
  unsigned int v0; // ebx
  _BYTE v2[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "AcceptInkInput", 0);
  v0 = *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1893) + 24LL);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return v0;
}
