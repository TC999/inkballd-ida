__int64 __fastcall GetRandomNumber(int a1)
{
  unsigned int v2; // ebx
  _BYTE v4[16]; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v5[24]; // [rsp+30h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "GetRandomNumber", 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::GetRandomNumber", 0);
  v2 = rand() % a1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v2;
}
