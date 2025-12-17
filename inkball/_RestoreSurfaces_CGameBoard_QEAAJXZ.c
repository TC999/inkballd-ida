// Hidden C++ exception states: #wind=5
__int64 __fastcall CGameBoard::RestoreSurfaces(CGameBoard *this)
{
  CDisplay *v2; // rbx
  __int64 v3; // rbx
  int v4; // ebx
  CDisplay *v5; // rbx
  __int64 v6; // rbx
  CDisplay *v7; // rbx
  __int64 v8; // rbx
  CDisplay *v9; // rbx
  __int64 v10; // rbx
  CDisplay *v11; // rbx
  __int64 v12; // rbx
  int v13; // eax
  struct IDirectDrawPalette *v14; // rdi
  CDisplay *v15; // rbx
  int SurfaceFromBitmap; // eax
  struct CSurface *v17; // rbx
  int v18; // eax
  __int64 v19; // rdi
  struct CSurface *v20; // rbx
  __int64 v21; // rbx
  __int64 v22; // rdi
  struct CSurface *v23; // rbx
  __int64 v24; // rbx
  __int64 v25; // rdi
  struct CSurface *v26; // rbx
  __int64 v27; // rbx
  struct CSurface *v29[3]; // [rsp+30h] [rbp-58h] BYREF
  _BYTE v30[16]; // [rsp+48h] [rbp-40h] BYREF
  _BYTE v31[48]; // [rsp+58h] [rbp-30h] BYREF
  int v32; // [rsp+98h] [rbp+10h] BYREF
  int v33; // [rsp+A0h] [rbp+18h] BYREF
  struct IDirectDrawPalette *v34; // [rsp+A8h] [rbp+20h] BYREF

  v29[2] = (struct CSurface *)-2LL;
  v32 = -2147467259;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v31, "CGameBoard::RestoreSurfaces", &v32);
  v34 = 0;
  v2 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CDisplay::GetDirectDraw", 0);
  v3 = *((_QWORD *)v2 + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
  v4 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v3 + 200LL))(v3);
  v32 = v4;
  if ( v4 >= 0 )
  {
    v5 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CDisplay::GetBoardBuffer", 0);
    v6 = *((_QWORD *)v5 + 6);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 216LL))(v6);
    v7 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CDisplay::GetInkBuffer", 0);
    v8 = *((_QWORD *)v7 + 5);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v8 + 216LL))(v8);
    v9 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CDisplay::GetBackBuffer", 0);
    v10 = *((_QWORD *)v9 + 3);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v10 + 216LL))(v10);
    v11 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CDisplay::GetFrontBuffer", 0);
    v12 = *((_QWORD *)v11 + 2);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v12 + 216LL))(v12);
    v13 = CDisplay::CreatePaletteFromBitmap(g_pDisplay, &v34, (const unsigned __int16 *)0x1F5);
    v32 = v13;
    if ( v13 >= 0 )
    {
      v14 = v34;
      v15 = g_pDisplay;
      v33 = 0;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CDisplay::SetPalette", &v33);
      if ( *((_QWORD *)v15 + 2) )
        v33 = (*(__int64 (__fastcall **)(_QWORD, struct IDirectDrawPalette *))(**((_QWORD **)v15 + 2) + 248LL))(
                *((_QWORD *)v15 + 2),
                v14);
      else
        v33 = -2147467261;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
      if ( v34 )
      {
        (*(void (__fastcall **)(struct IDirectDrawPalette *))(*(_QWORD *)v34 + 16LL))(v34);
        v34 = 0;
      }
      SurfaceFromBitmap = CDisplay::CreateSurfaceFromBitmap(g_pDisplay, v29, (unsigned __int16 *)0x1F5, 0x17Du, 0x190u);
      v32 = SurfaceFromBitmap;
      if ( SurfaceFromBitmap >= 0 )
      {
        v17 = g_pGamePiecesSurface;
        if ( g_pGamePiecesSurface )
        {
          CSurface::~CSurface(g_pGamePiecesSurface);
          operator delete(v17);
        }
        g_pGamePiecesSurface = v29[0];
        v18 = CSurface::SetColorKey(v29[0], 0xFF00FFu);
        v32 = v18;
        if ( v18 >= 0 )
        {
          v19 = *((_QWORD *)this + 1889);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CScoreManager::Restore", 0);
          v20 = g_pScoreManagerSurface;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CSurface::GetDDrawSurface", 0);
          v21 = *(_QWORD *)v20;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v21 + 216LL))(v21);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v19 + 8LL))(v19);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          v22 = *((_QWORD *)this + 1890);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CTileManager::Restore", 0);
          v23 = g_pTileManagerSurface;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CSurface::GetDDrawSurface", 0);
          v24 = *(_QWORD *)v23;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v24 + 216LL))(v24);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v22 + 8LL))(v22);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
          v25 = *((_QWORD *)this + 1888);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v29, "CBallManager::Restore", 0);
          v26 = g_pBallManagerSurface;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CSurface::GetDDrawSurface", 0);
          v27 = *(_QWORD *)v26;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v27 + 216LL))(v27);
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v25 + 8LL))(v25);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v29);
          CTimeManager::Restore(*((CTimeManager **)this + 1891));
          CGameBoard::RedrawBoardBuffer(this);
          v32 = 0;
          v4 = 0;
        }
        else
        {
          v4 = v18;
        }
      }
      else
      {
        v4 = SurfaceFromBitmap;
      }
    }
    else
    {
      v4 = v13;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v31);
  return (unsigned int)v4;
}
