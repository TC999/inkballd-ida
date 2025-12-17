// Hidden C++ exception states: #wind=1
void __fastcall CBoardTileOWF::DeflectBall(CBoardTileOWF *this, struct CBall *a2)
{
  _BYTE v4[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardTileOWF::DeflectBall", 0);
  PerformStandardWallDeflection(this, a2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
