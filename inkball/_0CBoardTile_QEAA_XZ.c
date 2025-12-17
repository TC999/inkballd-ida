CBoardTile *__fastcall CBoardTile::CBoardTile(CBoardTile *this)
{
  _BYTE v3[24]; // [rsp+20h] [rbp-18h] BYREF

  *(_QWORD *)this = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardObject::CBoardObject", 0);
  *((_QWORD *)this + 1) = 0;
  *((_QWORD *)this + 2) = 0;
  *((_QWORD *)this + 4) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 6) = 32;
  *((_DWORD *)this + 7) = 32;
  *((_QWORD *)this + 7) = 0x3FF0000000000000LL;
  *((_QWORD *)this + 8) = 0x3FF0000000000000LL;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  *(_QWORD *)this = &CBoardTile::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardTile::CBoardTile", 0);
  *((_DWORD *)this + 20) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
