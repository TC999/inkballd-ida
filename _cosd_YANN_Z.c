double __fastcall cosd(double a1)
{
  _BYTE v2[16]; // [rsp+20h] [rbp-28h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "cosd", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return cos(a1 * 0.01745327777777778);
}
