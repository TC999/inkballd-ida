void __fastcall CBoardObject::GetBoundingRect(CBoardObject *this, struct tagRECT *a2)
{
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardObject::GetBoundingRect", 0);
  a2->left = (int)*((double *)this + 1);
  a2->right = (int)((double)*((int *)this + 6) + *((double *)this + 1));
  a2->top = (int)*((double *)this + 2);
  a2->bottom = (int)((double)*((int *)this + 7) + *((double *)this + 2));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
