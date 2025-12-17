// Hidden C++ exception states: #wind=1
void __fastcall CBoardTileWall::DeflectBall(CBoardTileWall *this, struct CBall *a2)
{
  int v4; // esi
  _BYTE v5[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v6[32]; // [rsp+38h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBoardTileWall::DeflectBall", 0);
  v4 = *((_DWORD *)this + 12);
  if ( v4 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "SetBallColor", 0);
    *((_DWORD *)a2 + 12) = v4;
    *((_QWORD *)a2 + 4) = CGameBoard::GetBitmapRect(g_pCGameBoard, (unsigned int)(v4 + 2));
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  }
  PerformStandardWallDeflection(this, a2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
