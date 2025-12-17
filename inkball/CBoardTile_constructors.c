// 合并自 _0CBoardTile_QEAA_XZ.c 和 _0CBoardTile_QEAA_W4TILE_TYPE_HHPEAUtagRECT_Z.c
// 仅做物理合并，保留两个独立构造函数实现

// 无参构造函数
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

// 多参数构造函数
__int64 __fastcall CBoardTile::CBoardTile(__int64 a1, int a2, int a3, int a4, __int64 a5)
{
  _BYTE v10[24]; // [rsp+20h] [rbp-18h] BYREF

  *(_QWORD *)a1 = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBoardObject::CBoardObject", 0);
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 32) = 0;
  *(_DWORD *)(a1 + 44) = 0;
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 24) = 32;
  *(_DWORD *)(a1 + 28) = 32;
  *(_QWORD *)(a1 + 56) = 0x3FF0000000000000LL;
  *(_QWORD *)(a1 + 64) = 0x3FF0000000000000LL;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  *(_QWORD *)a1 = &CBoardTile::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBoardTile::CBoardTile", 0);
  *(_DWORD *)(a1 + 80) = 0;
  *(_DWORD *)(a1 + 72) = 0;
  *(_QWORD *)(a1 + 32) = a5;
  *(_DWORD *)(a1 + 76) = a2;
  *(_DWORD *)(a1 + 84) = a3;
  *(_DWORD *)(a1 + 88) = a4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return a1;
}
