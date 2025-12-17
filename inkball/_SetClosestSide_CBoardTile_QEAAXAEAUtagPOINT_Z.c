void __fastcall CBoardTile::SetClosestSide(CBoardTile *this, struct tagPOINT *a2)
{
  LONG y; // eax
  LONG v5; // eax
  struct tagRECT v6; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v7[24]; // [rsp+30h] [rbp-18h] BYREF
  struct tagPOINT v8; // [rsp+58h] [rbp+10h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBoardTile::SetClosestSide", 0);
  CBoardObject::GetBoundingRect(this, &v6);
  v8.x = a2->x;
  v8.y = v6.top;
  CalcUnsqrtDistance(a2, &v8);
  y = a2->y;
  v8.x = v6.right;
  v8.y = y;
  CalcUnsqrtDistance(a2, &v8);
  v8.x = a2->x;
  v8.y = v6.bottom;
  CalcUnsqrtDistance(a2, &v8);
  v5 = a2->y;
  v8.x = v6.left;
  v8.y = v5;
  CalcUnsqrtDistance(a2, &v8);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
