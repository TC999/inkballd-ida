__int64 __fastcall CSink::AddRef(CSink *this)
{
  signed __int32 v2; // ebx
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CSink::AddRef", 0);
  v2 = _InterlockedExchangeAdd((volatile signed __int32 *)this + 2, 1u);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return (unsigned int)(v2 + 1);
}
