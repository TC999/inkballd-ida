// Hidden C++ exception states: #wind=1
void __fastcall CBoardTile::DeflectBall(CBoardTile *this, struct CBall *a2)
{
  _BYTE v3[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardTile::DeflectBall", 0);
  CBall::SetTallness(a2, 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
