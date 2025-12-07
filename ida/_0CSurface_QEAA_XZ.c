CSurface *__fastcall CSurface::CSurface(CSurface *this)
{
  _BYTE v3[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CSurface::CSurface", 0);
  *(_QWORD *)this = 0;
  *((_DWORD *)this + 36) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
