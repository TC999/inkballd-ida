__int64 __fastcall Round(double a1)
{
  double v2; // xmm0_8
  double v3; // xmm0_8
  _BYTE v5[16]; // [rsp+20h] [rbp-28h] BYREF
  double Y; // [rsp+58h] [rbp+10h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "Round", 0);
  v2 = modf(a1, &Y);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  if ( v2 < 0.5 )
    v3 = floor(a1);
  else
    v3 = ceil(a1);
  return (unsigned int)(int)v3;
}
