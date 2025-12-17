void __fastcall CBall::Deflect(CBall *this, double a2, double a3)
{
  double v4; // xmm3_8
  double v5; // xmm5_8
  double v6; // xmm0_8
  _BYTE v7[16]; // [rsp+20h] [rbp-38h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBall::Deflect", 0);
  v4 = *((double *)this + 9);
  v5 = *((double *)this + 10);
  v6 = (v5 * a3 + v4 * a2) * 2.0 / (a2 * a2 + a3 * a3);
  *((double *)this + 10) = v5 - v6 * a3;
  *((double *)this + 9) = v4 - v6 * a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
