__int64 __fastcall CalcUnsqrtDistance(struct tagPOINT *a1, struct tagPOINT *a2)
{
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CalcUnsqrtDistance", 0);
  LODWORD(a1) = (a1->y - a2->y) * (a1->y - a2->y) + (a1->x - a2->x) * (a1->x - a2->x);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (unsigned int)a1;
}
