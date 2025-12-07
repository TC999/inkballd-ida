int *__fastcall GetBitmapRect(int a1)
{
  int *BitmapRect; // rbx
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "GetBitmapRect", 0);
  BitmapRect = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return BitmapRect;
}
