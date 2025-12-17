__int64 __fastcall CBoardTileRLColored::CareAboutCollisions(__int64 a1)
{
  unsigned int v2; // edi
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardTileRLColored::CareAboutCollisions", 0);
  v2 = 0;
  if ( *(int *)(a1 + 80) > 0 )
    v2 = 2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
