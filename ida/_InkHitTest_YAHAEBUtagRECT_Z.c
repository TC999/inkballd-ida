// Hidden C++ exception states: #wind=1
__int64 __fastcall InkHitTest(const struct tagRECT *a1)
{
  unsigned int v2; // ecx
  unsigned int v3; // ebx
  _BYTE v5[32]; // [rsp+28h] [rbp-20h] BYREF
  struct tagPOINT v6; // [rsp+50h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "InkHitTest", 0);
  v2 = (a1->right - a1->left) / 2;
  v6.x = a1->left + v2;
  v6.y = a1->top + (a1->bottom - a1->top) / 2;
  if ( !v2 )
    v2 = 1;
  v3 = CInk::HitCircleTest(*((CInk **)g_pCGameBoard + 1893), &v6, v2, 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
