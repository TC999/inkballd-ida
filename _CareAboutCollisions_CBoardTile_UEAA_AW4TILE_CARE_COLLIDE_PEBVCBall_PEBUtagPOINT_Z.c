_BOOL8 __fastcall CBoardTile::CareAboutCollisions(__int64 a1, __int64 a2)
{
  BOOL v3; // edi
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBoardTile::CareAboutCollisions", 0);
  v3 = *(_DWORD *)(a2 + 152) != 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
