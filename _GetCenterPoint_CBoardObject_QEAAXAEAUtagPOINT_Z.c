void __fastcall CBoardObject::GetCenterPoint(CBoardObject *this, struct tagPOINT *a2)
{
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardObject::GetCenterPoint", 0);
  a2->x = (int)((double)(*((int *)this + 6) >> 1) + *((double *)this + 1));
  a2->y = (int)((double)(*((int *)this + 7) >> 1) + *((double *)this + 2));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
