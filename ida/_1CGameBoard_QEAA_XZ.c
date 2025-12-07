// Hidden C++ exception states: #wind=4
void __fastcall CGameBoard::~CGameBoard(CGameBoard *this)
{
  CBall **v2; // rsi
  CBall **v3; // rdi
  __int64 v4; // rbp
  _DWORD *v5; // rdi
  void *v6; // rcx
  void *v7; // rcx
  struct CSurface *v8; // rdi
  struct CSurface *v9; // rdi
  struct CSurface *v10; // rdi
  struct CSurface *v11; // rdi
  struct CSurface *v12; // rdi
  CDisplay *v13; // rdi
  CInk *v14; // rcx
  _BYTE v15[16]; // [rsp+28h] [rbp-50h] BYREF
  _BYTE v16[16]; // [rsp+38h] [rbp-40h] BYREF
  _BYTE v17[24]; // [rsp+48h] [rbp-30h] BYREF
  int v18; // [rsp+80h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CGameBoard::~CGameBoard", 0);
  v2 = (CBall **)*((_QWORD *)this + 1888);
  if ( v2 )
  {
    *v2 = (CBall *)&CBallManager::`vftable';
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CBallManager::~CBallManager", 0);
    v3 = v2 + 8;
    v4 = 6;
    do
    {
      if ( *v3 )
      {
        CBall::Release(*v3);
        *v3 = 0;
      }
      ++v3;
      --v4;
    }
    while ( v4 );
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    operator delete(v2);
    *((_QWORD *)this + 1888) = 0;
  }
  v5 = (_DWORD *)*((_QWORD *)this + 1889);
  if ( v5 )
  {
    *(_QWORD *)v5 = &CScoreManager::`vftable';
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CScoreManager::~CScoreManager", 0);
    CRegistryManager::WriteHiScore((CRegistryManager *)&g_CRegistryManager, v5[10]);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    operator delete(v5);
    *((_QWORD *)this + 1889) = 0;
  }
  v6 = (void *)*((_QWORD *)this + 1890);
  if ( v6 )
  {
    operator delete(v6);
    *((_QWORD *)this + 1890) = 0;
  }
  v7 = (void *)*((_QWORD *)this + 1891);
  if ( v7 )
  {
    operator delete(v7);
    *((_QWORD *)this + 1891) = 0;
  }
  v8 = g_pGamePiecesSurface;
  if ( g_pGamePiecesSurface )
  {
    CSurface::~CSurface(g_pGamePiecesSurface);
    operator delete(v8);
    g_pGamePiecesSurface = 0;
  }
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CGameBoard::FreeDirectDraw", 0);
  v9 = g_pTimeManagerSurface;
  if ( g_pTimeManagerSurface )
  {
    CSurface::~CSurface(g_pTimeManagerSurface);
    operator delete(v9);
    g_pTimeManagerSurface = 0;
  }
  v10 = g_pBallManagerSurface;
  if ( g_pBallManagerSurface )
  {
    CSurface::~CSurface(g_pBallManagerSurface);
    operator delete(v10);
    g_pBallManagerSurface = 0;
  }
  v11 = g_pTileManagerSurface;
  if ( g_pTileManagerSurface )
  {
    CSurface::~CSurface(g_pTileManagerSurface);
    operator delete(v11);
    g_pTileManagerSurface = 0;
  }
  v12 = g_pScoreManagerSurface;
  if ( g_pScoreManagerSurface )
  {
    CSurface::~CSurface(g_pScoreManagerSurface);
    operator delete(v12);
    g_pScoreManagerSurface = 0;
  }
  v13 = g_pDisplay;
  if ( g_pDisplay )
  {
    *(_QWORD *)g_pDisplay = &CDisplay::`vftable';
    v18 = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CDisplay::~CDisplay", &v18);
    v18 = CDisplay::DestroyObjects(v13);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    operator delete(v13);
    g_pDisplay = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  v14 = (CInk *)*((_QWORD *)this + 1893);
  if ( v14 )
  {
    CInk::`scalar deleting destructor'(v14);
    *((_QWORD *)this + 1893) = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
}
