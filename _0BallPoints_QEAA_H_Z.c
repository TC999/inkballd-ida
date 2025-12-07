// Hidden C++ exception states: #wind=1
BallPoints *__fastcall BallPoints::BallPoints(BallPoints *this, int a2)
{
  double v4; // xmm8_8
  int *v5; // rax
  int v6; // ebx
  _QWORD *v8; // rdx
  _QWORD v9[5]; // [rsp+0h] [rbp-68h] BYREF
  _BYTE v10[24]; // [rsp+28h] [rbp-40h] BYREF

  v9[4] = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "BallPoints::BallPoints", 0);
  v4 = (double)a2 * 0.5;
  try
  {
    v5 = (int *)operator new[](0x100u);
    *(_QWORD *)this = v5;
  }
  catch ( std::bad_alloc )
  {
    v8 = v9;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v8) = 12;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v8, qword_401968);
    }
    throw;
  }
  if ( v5 )
  {
    v6 = (int)(-0.0 - v4);
    *v5 = v6;
    *(_DWORD *)(*(_QWORD *)this + 4LL) = 0;
    *(_DWORD *)(*(_QWORD *)this + 8LL) = (int)(-0.0 - cosd(11.25) * v4);
    *(_DWORD *)(*(_QWORD *)this + 12LL) = (int)(-0.0 - sind(11.25) * v4);
    *(_DWORD *)(*(_QWORD *)this + 16LL) = (int)(-0.0 - cosd(22.5) * v4);
    *(_DWORD *)(*(_QWORD *)this + 20LL) = (int)(-0.0 - sind(22.5) * v4);
    *(_DWORD *)(*(_QWORD *)this + 24LL) = (int)(-0.0 - cosd(33.75) * v4);
    *(_DWORD *)(*(_QWORD *)this + 28LL) = (int)(-0.0 - sind(33.75) * v4);
    *(_DWORD *)(*(_QWORD *)this + 32LL) = (int)(-0.0 - cosd(45.0) * v4);
    *(_DWORD *)(*(_QWORD *)this + 36LL) = (int)(-0.0 - sind(45.0) * v4);
    *(_DWORD *)(*(_QWORD *)this + 40LL) = (int)(-0.0 - cosd(56.25) * v4);
    *(_DWORD *)(*(_QWORD *)this + 44LL) = (int)(-0.0 - sind(56.25) * v4);
    *(_DWORD *)(*(_QWORD *)this + 48LL) = (int)(-0.0 - cosd(67.5) * v4);
    *(_DWORD *)(*(_QWORD *)this + 52LL) = (int)(-0.0 - sind(67.5) * v4);
    *(_DWORD *)(*(_QWORD *)this + 56LL) = (int)(-0.0 - cosd(78.75) * v4);
    *(_DWORD *)(*(_QWORD *)this + 60LL) = (int)(-0.0 - sind(78.75) * v4);
    *(_DWORD *)(*(_QWORD *)this + 64LL) = 0;
    *(_DWORD *)(*(_QWORD *)this + 68LL) = v6;
    *(_DWORD *)(*(_QWORD *)this + 72LL) = -*(_DWORD *)(*(_QWORD *)this + 56LL);
    *(_DWORD *)(*(_QWORD *)this + 76LL) = *(_DWORD *)(*(_QWORD *)this + 60LL);
    *(_DWORD *)(*(_QWORD *)this + 80LL) = -*(_DWORD *)(*(_QWORD *)this + 48LL);
    *(_DWORD *)(*(_QWORD *)this + 84LL) = *(_DWORD *)(*(_QWORD *)this + 52LL);
    *(_DWORD *)(*(_QWORD *)this + 88LL) = -*(_DWORD *)(*(_QWORD *)this + 40LL);
    *(_DWORD *)(*(_QWORD *)this + 92LL) = *(_DWORD *)(*(_QWORD *)this + 44LL);
    *(_DWORD *)(*(_QWORD *)this + 96LL) = -*(_DWORD *)(*(_QWORD *)this + 32LL);
    *(_DWORD *)(*(_QWORD *)this + 100LL) = *(_DWORD *)(*(_QWORD *)this + 36LL);
    *(_DWORD *)(*(_QWORD *)this + 104LL) = -*(_DWORD *)(*(_QWORD *)this + 24LL);
    *(_DWORD *)(*(_QWORD *)this + 108LL) = *(_DWORD *)(*(_QWORD *)this + 28LL);
    *(_DWORD *)(*(_QWORD *)this + 112LL) = -*(_DWORD *)(*(_QWORD *)this + 16LL);
    *(_DWORD *)(*(_QWORD *)this + 116LL) = *(_DWORD *)(*(_QWORD *)this + 20LL);
    *(_DWORD *)(*(_QWORD *)this + 120LL) = -*(_DWORD *)(*(_QWORD *)this + 8LL);
    *(_DWORD *)(*(_QWORD *)this + 124LL) = *(_DWORD *)(*(_QWORD *)this + 12LL);
    *(_QWORD *)(*(_QWORD *)this + 128LL) = (unsigned int)(int)v4;
    *(_DWORD *)(*(_QWORD *)this + 136LL) = *(_DWORD *)(*(_QWORD *)this + 120LL);
    *(_DWORD *)(*(_QWORD *)this + 140LL) = -*(_DWORD *)(*(_QWORD *)this + 124LL);
    *(_DWORD *)(*(_QWORD *)this + 144LL) = *(_DWORD *)(*(_QWORD *)this + 112LL);
    *(_DWORD *)(*(_QWORD *)this + 148LL) = -*(_DWORD *)(*(_QWORD *)this + 116LL);
    *(_DWORD *)(*(_QWORD *)this + 152LL) = *(_DWORD *)(*(_QWORD *)this + 104LL);
    *(_DWORD *)(*(_QWORD *)this + 156LL) = -*(_DWORD *)(*(_QWORD *)this + 108LL);
    *(_DWORD *)(*(_QWORD *)this + 160LL) = *(_DWORD *)(*(_QWORD *)this + 96LL);
    *(_DWORD *)(*(_QWORD *)this + 164LL) = -*(_DWORD *)(*(_QWORD *)this + 100LL);
    *(_DWORD *)(*(_QWORD *)this + 168LL) = *(_DWORD *)(*(_QWORD *)this + 88LL);
    *(_DWORD *)(*(_QWORD *)this + 172LL) = -*(_DWORD *)(*(_QWORD *)this + 92LL);
    *(_DWORD *)(*(_QWORD *)this + 176LL) = *(_DWORD *)(*(_QWORD *)this + 80LL);
    *(_DWORD *)(*(_QWORD *)this + 180LL) = -*(_DWORD *)(*(_QWORD *)this + 84LL);
    *(_DWORD *)(*(_QWORD *)this + 184LL) = *(_DWORD *)(*(_QWORD *)this + 72LL);
    *(_DWORD *)(*(_QWORD *)this + 188LL) = -*(_DWORD *)(*(_QWORD *)this + 76LL);
    *(_DWORD *)(*(_QWORD *)this + 192LL) = 0;
    *(_DWORD *)(*(_QWORD *)this + 196LL) = (int)v4;
    *(_DWORD *)(*(_QWORD *)this + 200LL) = -*(_DWORD *)(*(_QWORD *)this + 184LL);
    *(_DWORD *)(*(_QWORD *)this + 204LL) = *(_DWORD *)(*(_QWORD *)this + 188LL);
    *(_DWORD *)(*(_QWORD *)this + 208LL) = -*(_DWORD *)(*(_QWORD *)this + 176LL);
    *(_DWORD *)(*(_QWORD *)this + 212LL) = *(_DWORD *)(*(_QWORD *)this + 180LL);
    *(_DWORD *)(*(_QWORD *)this + 216LL) = -*(_DWORD *)(*(_QWORD *)this + 168LL);
    *(_DWORD *)(*(_QWORD *)this + 220LL) = *(_DWORD *)(*(_QWORD *)this + 172LL);
    *(_DWORD *)(*(_QWORD *)this + 224LL) = -*(_DWORD *)(*(_QWORD *)this + 160LL);
    *(_DWORD *)(*(_QWORD *)this + 228LL) = *(_DWORD *)(*(_QWORD *)this + 164LL);
    *(_DWORD *)(*(_QWORD *)this + 232LL) = -*(_DWORD *)(*(_QWORD *)this + 152LL);
    *(_DWORD *)(*(_QWORD *)this + 236LL) = *(_DWORD *)(*(_QWORD *)this + 156LL);
    *(_DWORD *)(*(_QWORD *)this + 240LL) = -*(_DWORD *)(*(_QWORD *)this + 144LL);
    *(_DWORD *)(*(_QWORD *)this + 244LL) = *(_DWORD *)(*(_QWORD *)this + 148LL);
    *(_DWORD *)(*(_QWORD *)this + 248LL) = -*(_DWORD *)(*(_QWORD *)this + 136LL);
    *(_DWORD *)(*(_QWORD *)this + 252LL) = *(_DWORD *)(*(_QWORD *)this + 140LL);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return this;
}
