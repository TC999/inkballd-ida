void __fastcall NormalizeRect(struct tagRECT *a1)
{
  LONG left; // ecx
  LONG right; // eax
  LONG bottom; // eax
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "NormalizeRect", 0);
  left = a1->left;
  right = a1->right;
  if ( a1->left > right )
  {
    a1->left = right;
    a1->right = left;
  }
  bottom = a1->bottom;
  if ( a1->top > bottom )
    a1->top = bottom;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
