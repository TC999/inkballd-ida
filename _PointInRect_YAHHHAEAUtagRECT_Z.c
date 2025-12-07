_BOOL8 __fastcall PointInRect(LONG a1, LONG a2, struct tagRECT *a3)
{
  BOOL v6; // ebx
  _BYTE v8[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "PointInRect", 0);
  NormalizeRect(a3);
  v6 = a1 >= a3->left && a1 < a3->right && a2 >= a3->top && a2 < a3->bottom;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v6;
}
