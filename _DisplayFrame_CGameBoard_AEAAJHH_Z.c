// Hidden C++ exception states: #wind=1
__int64 __fastcall CGameBoard::DisplayFrame(CGameBoard *this, int a2, int a3)
{
  int v6; // ebx
  int v7; // ebx
  int v8; // ebp
  CMovingObject **v9; // r12
  CMovingObject *v10; // rsi
  CDisplay *v11; // rbx
  struct IDirectDrawSurface7 *v12; // rbx
  int v13; // eax
  int v14; // ebx
  int v15; // eax
  int v16; // eax
  struct tagRECT v18; // [rsp+38h] [rbp-60h] BYREF
  struct tagRECT v19; // [rsp+48h] [rbp-50h] BYREF
  _BYTE v20[16]; // [rsp+58h] [rbp-40h] BYREF
  _BYTE v21[24]; // [rsp+68h] [rbp-30h] BYREF
  int v22; // [rsp+B8h] [rbp+20h] BYREF

  v22 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CGameBoard::DisplayFrame", &v22);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v18, "BoardIsActive", 0);
  v6 = *((_DWORD *)g_pCGameManager + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v18);
  if ( !v6 && !a3 )
    goto LABEL_25;
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_QWORD *)this + 1888) + 8LL),
    *(_DWORD *)(*((_QWORD *)this + 1888) + 12LL),
    g_pBallManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_QWORD *)this + 1889) + 8LL),
    *(_DWORD *)(*((_QWORD *)this + 1889) + 12LL),
    g_pScoreManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_QWORD *)this + 1890) + 8LL),
    *(_DWORD *)(*((_QWORD *)this + 1890) + 12LL),
    g_pTileManagerSurface,
    0);
  CDisplay::Blt(
    g_pDisplay,
    *(_DWORD *)(*((_QWORD *)this + 1891) + 8LL),
    *(_DWORD *)(*((_QWORD *)this + 1891) + 12LL),
    g_pTimeManagerSurface,
    0);
  if ( (unsigned int)CInk::GetInkUpdateRect(*((CInk **)this + 1893), &v19) )
    CGameBoard::AddDisplayUpdateRect(this, &v19);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v18, "CGameBoard::GetPlayingAreaRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v18);
  v7 = CDisplay::BltInk(g_pDisplay, (struct tagRECT *)this + 505);
  v22 = v7;
  if ( v7 < 0 )
    goto LABEL_26;
  v8 = 0;
  if ( *((int *)this + 1312) > 0 )
  {
    v9 = (CMovingObject **)((char *)this + 5256);
    do
    {
      v10 = *v9;
      if ( *((_DWORD *)*v9 + 43) )
      {
        v11 = g_pDisplay;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CDisplay::GetBackBuffer", 0);
        v12 = (struct IDirectDrawSurface7 *)*((_QWORD *)v11 + 3);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
        v13 = CGameBoard::BltBall(this, v10, v12);
        v22 = v13;
        if ( v13 < 0 )
        {
          v7 = v13;
          goto LABEL_26;
        }
        if ( !a2 )
        {
          CMovingObject::GetMovementRect(v10, &v18);
          CGameBoard::AddDisplayUpdateRect(this, &v18);
        }
      }
      else if ( *((_DWORD *)v10 + 44) )
      {
        CMovingObject::GetMovementRect(*v9, &v18);
        *((_DWORD *)v10 + 44) = 0;
        CGameBoard::AddDisplayUpdateRect(this, &v18);
      }
      ++v8;
      ++v9;
    }
    while ( v8 < *((_DWORD *)this + 1312) );
  }
  if ( a2 )
  {
    v16 = CDisplay::Present(g_pDisplay, 0);
    v22 = v16;
    if ( v16 < 0 )
    {
      v7 = v16;
      goto LABEL_26;
    }
LABEL_25:
    v22 = 0;
    v7 = 0;
    goto LABEL_26;
  }
  v14 = 0;
  if ( *((int *)this + 2028) <= 0 )
    goto LABEL_25;
  while ( 1 )
  {
    v15 = CDisplay::Present(g_pDisplay, (struct tagRECT *)((char *)this + 16 * v14 + 8116));
    v22 = v15;
    if ( v15 < 0 )
      break;
    if ( ++v14 >= *((_DWORD *)this + 2028) )
      goto LABEL_25;
  }
  v7 = v15;
LABEL_26:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
  return (unsigned int)v7;
}
