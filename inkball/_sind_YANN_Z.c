double __fastcall sind(double a1)
{
  _BYTE v2[16]; // [rsp+20h] [rbp-28h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "sind", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return sin(a1 * 0.01745327777777778);
}
