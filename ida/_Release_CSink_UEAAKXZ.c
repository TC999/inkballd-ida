__int64 __fastcall CSink::Release(CSink *this)
{
  unsigned __int32 v2; // ebx
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CSink::Release", 0);
  v2 = _InterlockedDecrement((volatile signed __int32 *)this + 2);
  if ( !v2 )
    operator delete(this);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
