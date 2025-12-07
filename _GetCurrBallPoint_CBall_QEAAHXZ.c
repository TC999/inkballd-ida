__int64 __fastcall CBall::GetCurrBallPoint(CBall *this)
{
  _BYTE v3[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBall::GetCurrBallPoint", 0);
  LODWORD(this) = (*((_DWORD *)this + 34) + *((_DWORD *)this + 35)) % 32;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return (unsigned int)this;
}
