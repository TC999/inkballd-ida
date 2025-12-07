// Hidden C++ exception states: #wind=1
__int64 __fastcall CheckForBallCollisionWithInk(struct CBall *this)
{
  unsigned int v2; // esi
  unsigned int v3; // edi
  struct tagRECT *v4; // rbx
  _BYTE v6[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v7[32]; // [rsp+38h] [rbp-20h] BYREF
  struct tagPOINT v8; // [rsp+60h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CheckForBallCollisionWithInk", 0);
  CBoardObject::GetCenterPoint(this, &v8);
  v2 = *((_DWORD *)this + 6) / 2;
  v3 = 0;
  if ( (unsigned int)CInk::HitCircleTest(*((CInk **)g_pCGameBoard + 1893), &v8, v2, 0)
    && (unsigned int)CBall::Collide(this, (int (*const)(const struct tagRECT *))InkHitTest) )
  {
    v3 = 1;
    CInk::HitCircleTest(*((CInk **)g_pCGameBoard + 1893), &v8, v2, 1);
    CDisplay::BltInk(g_pDisplay, 0);
    v4 = (struct tagRECT *)g_pCGameBoard;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::GetPlayingAreaRect", 0);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
    AddDisplayUpdateRect(v4 + 505);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v3;
}
