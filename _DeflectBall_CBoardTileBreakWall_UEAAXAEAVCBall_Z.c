// Hidden C++ exception states: #wind=2
void __fastcall CBoardTileBreakWall::DeflectBall(CBoardTileBreakWall *this, struct CBall *a2)
{
  int v4; // r11d
  int v5; // ebx
  _BYTE v6[16]; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v7[16]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v8[32]; // [rsp+48h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBoardTileBreakWall::DeflectBall", 0);
  PerformStandardWallDeflection(this, a2);
  v4 = *((_DWORD *)this + 12);
  if ( !v4 || v4 == *((_DWORD *)a2 + 12) )
  {
    ConvertTileToFloor(this);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "ScoreBreak", 0);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBall::GetBreakWallPoints", 0);
    v5 = BreakPoints[*((int *)a2 + 12)];
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
    CScoreManager::IncrementScore(*((CScoreManager **)g_pCGameBoard + 1889), v5);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
