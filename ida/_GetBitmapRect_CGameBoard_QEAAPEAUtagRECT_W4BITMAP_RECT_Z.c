int *__fastcall CGameBoard::GetBitmapRect(__int64 a1, int a2)
{
  __int64 v2; // rbx
  _BYTE v4[16]; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v5[24]; // [rsp+30h] [rbp-18h] BYREF

  v2 = a2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::GetBitmapRect", 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return &g_CBitmapRects[4 * v2];
}
