CDisplay *__fastcall CDisplay::CDisplay(CDisplay *this)
{
  _BYTE v3[24]; // [rsp+20h] [rbp-18h] BYREF

  *(_QWORD *)this = &CDisplay::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CDisplay::CDisplay", 0);
  *((_QWORD *)this + 1) = 0;
  *((_QWORD *)this + 2) = 0;
  *((_QWORD *)this + 3) = 0;
  *((_QWORD *)this + 4) = 0;
  *((_QWORD *)this + 5) = 0;
  *((_QWORD *)this + 6) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
