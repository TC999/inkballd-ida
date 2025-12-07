// Hidden C++ exception states: #wind=3
__int64 __fastcall CGameBoard::CreateNewSurfaces(CGameBoard *this)
{
  CGameBoard *v1; // rdi
  CDisplay *v2; // rax
  CDisplay *v3; // rsi
  int WindowedDisplay; // ebx
  CDisplay *v5; // r12
  struct CSurface *v6; // rsi
  struct CSurface *v7; // rsi
  struct CSurface *v8; // rsi
  struct CSurface *v9; // rsi
  _QWORD *v11; // rdx
  _QWORD v12[5]; // [rsp+0h] [rbp-68h] BYREF
  _BYTE v13[16]; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v14[48]; // [rsp+38h] [rbp-30h] BYREF
  int v16; // [rsp+78h] [rbp+10h] BYREF
  __int64 v17; // [rsp+80h] [rbp+18h] BYREF

  v12[4] = -2;
  v1 = this;
  v16 = -2147024882;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CGameBoard::CreateNewSurfaces", &v16);
  try
  {
    v2 = (CDisplay *)operator new(0x58u);
    if ( v2 )
      v3 = CDisplay::CDisplay(v2);
    else
      v3 = 0;
  }
  catch ( std::bad_alloc )
  {
    v11 = v12;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v11) = 16;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v11, qword_401928);
    }
    v16 = -2147024882;
    v17 = 0;
    v1 = this;
    v3 = 0;
  }
  if ( v3 )
  {
    WindowedDisplay = CDisplay::CreateWindowedDisplay(
                        v3,
                        *((HWND *)v1 + 1892),
                        *((_DWORD *)v1 + 3764),
                        *((_DWORD *)v1 + 3765));
    v16 = WindowedDisplay;
    if ( WindowedDisplay < 0 )
    {
      *(_QWORD *)v3 = &CDisplay::`vftable';
      LODWORD(v17) = 0;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CDisplay::~CDisplay", (int *)&v17);
      LODWORD(v17) = CDisplay::DestroyObjects(v3);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
      operator delete(v3);
      WindowedDisplay = v16;
    }
    else
    {
      v5 = g_pDisplay;
      if ( g_pDisplay )
      {
        *(_QWORD *)g_pDisplay = &CDisplay::`vftable';
        LODWORD(v17) = 0;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CDisplay::~CDisplay", (int *)&v17);
        LODWORD(v17) = CDisplay::DestroyObjects(v5);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
        operator delete(v5);
        WindowedDisplay = v16;
      }
      g_pDisplay = v3;
    }
  }
  else
  {
    WindowedDisplay = v16;
  }
  if ( WindowedDisplay >= 0 )
  {
    v6 = g_pBallManagerSurface;
    WindowedDisplay = CBallManager::InitSurface(*((CBallManager **)v1 + 1888));
    v16 = WindowedDisplay;
    if ( WindowedDisplay < 0 )
    {
      g_pBallManagerSurface = v6;
    }
    else if ( v6 )
    {
      CSurface::~CSurface(v6);
      operator delete(v6);
      WindowedDisplay = v16;
    }
    if ( WindowedDisplay >= 0 )
    {
      v7 = g_pScoreManagerSurface;
      WindowedDisplay = CScoreManager::InitSurface(*((CScoreManager **)v1 + 1889));
      v16 = WindowedDisplay;
      if ( WindowedDisplay < 0 )
      {
        g_pScoreManagerSurface = v7;
      }
      else if ( v7 )
      {
        CSurface::~CSurface(v7);
        operator delete(v7);
        WindowedDisplay = v16;
      }
      if ( WindowedDisplay >= 0 )
      {
        v8 = g_pTileManagerSurface;
        WindowedDisplay = CTileManager::InitSurface(*((CTileManager **)v1 + 1890));
        v16 = WindowedDisplay;
        if ( WindowedDisplay < 0 )
        {
          g_pTileManagerSurface = v8;
        }
        else if ( v8 )
        {
          CSurface::~CSurface(v8);
          operator delete(v8);
          WindowedDisplay = v16;
        }
        if ( WindowedDisplay >= 0 )
        {
          v9 = g_pTimeManagerSurface;
          WindowedDisplay = CTimeManager::InitSurface(*((CTimeManager **)v1 + 1891));
          v16 = WindowedDisplay;
          if ( WindowedDisplay < 0 )
          {
            g_pTimeManagerSurface = v9;
          }
          else if ( v9 )
          {
            CSurface::~CSurface(v9);
            operator delete(v9);
            WindowedDisplay = v16;
          }
        }
      }
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return (unsigned int)WindowedDisplay;
}
