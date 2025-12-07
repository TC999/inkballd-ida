__int64 __fastcall CBall::GetPrevBallPoint(CBall *this)
{
  unsigned int v2; // ebx
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetPrevBallPoint", 0);
  if ( (unsigned int)CBall::GetCurrBallPoint(this) )
    v2 = CBall::GetCurrBallPoint(this) - 1;
  else
    v2 = 31;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
