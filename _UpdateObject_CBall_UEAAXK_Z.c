// Hidden C++ exception states: #wind=1
void __fastcall CBall::UpdateObject(CBall *this, int a2)
{
  double v4; // xmm3_8
  double v5; // xmm1_8
  double v6; // xmm2_8
  int v7; // edi
  CGameBoard *i; // rax
  struct CBall *Ball; // rax
  _BYTE v10[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v11[32]; // [rsp+38h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBall::UpdateObject", 0);
  if ( *((_DWORD *)this + 43) )
  {
    v4 = (double)a2 / 1000.0;
    v5 = *((double *)this + 1);
    *((double *)this + 13) = v5;
    v6 = *((double *)this + 2);
    *((double *)this + 14) = v6;
    *((double *)this + 1) = v4 * *((double *)this + 9) + v5;
    *((double *)this + 2) = v4 * *((double *)this + 10) + v6;
    if ( !(unsigned int)CBall::CheckBoardBounds(this) )
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBall::AddRef", 0);
      ++*((_DWORD *)this + 37);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
      CheckForBallCollisionWithNonDeflectingTile(this);
      if ( (int)*((double *)this + 1) != (int)*((double *)this + 13)
        || (int)*((double *)this + 2) != (int)*((double *)this + 14) )
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CheckForBallCollisionWithBall", 0);
        v7 = 0;
        for ( i = g_pCGameBoard; v7 < *((_DWORD *)i + 1312); ++v7 )
        {
          if ( v7 != *((_DWORD *)this + 45) )
          {
            Ball = CGameBoard::GetBall(i, v7);
            if ( *((_DWORD *)Ball + 43) )
              CBall::Collide(this, Ball);
            i = g_pCGameBoard;
          }
        }
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
        CheckForBallCollisionWithInk(this);
        CheckForBallCollisionWithTile(this);
      }
      CBall::Release(this);
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
}
