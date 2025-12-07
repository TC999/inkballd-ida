// Hidden C++ exception states: #wind=6
__int64 __fastcall CGameBoard::CGameBoard(__int64 a1, HWND a2)
{
  CTimeManager *v4; // rbx
  unsigned int v5; // eax
  _DWORD *v6; // rsi
  int *v7; // r9
  CBallManager *v8; // rax
  CBallManager *v9; // rax
  CScoreManager *v10; // rax
  CScoreManager *v11; // rax
  CTileManager *v12; // rax
  CTileManager *v13; // rax
  CTimeManager *v14; // rax
  CInk *v16; // rcx
  _QWORD *v17; // rcx
  __int64 *v18; // rdx
  CBall **v19; // r13
  CBall **v20; // r12
  __int64 v21; // r14
  _DWORD *v22; // r12
  __int64 v23; // [rsp+0h] [rbp-B8h] BYREF
  __int64 v24; // [rsp+30h] [rbp-88h]
  _BYTE v25[16]; // [rsp+38h] [rbp-80h] BYREF
  _BYTE v26[16]; // [rsp+48h] [rbp-70h] BYREF
  _QWORD pExceptionObject[3]; // [rsp+58h] [rbp-60h] BYREF
  _QWORD v28[9]; // [rsp+70h] [rbp-48h] BYREF
  int inited; // [rsp+D0h] [rbp+18h] BYREF

  v24 = -2;
  v4 = 0;
  inited = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v26, "CGameBoard::CGameBoard", &inited);
  *(_QWORD *)(a1 + 15136) = a2;
  *(_DWORD *)(a1 + 15096) = 1;
  dSizeFactor = DOUBLE_1_0;
  *(_DWORD *)(a1 + 15056) = 544;
  *(_DWORD *)(a1 + 15060) = 586;
  *(_DWORD *)(a1 + 15064) = 0;
  *(_DWORD *)(a1 + 15068) = 42;
  *(_DWORD *)(a1 + 8096) = 0;
  *(_DWORD *)(a1 + 8104) = 544;
  *(_DWORD *)(a1 + 8100) = 0;
  *(_DWORD *)(a1 + 8108) = 42;
  *(_DWORD *)(a1 + 8080) = 0;
  *(_DWORD *)(a1 + 8088) = 544;
  *(_DWORD *)(a1 + 8084) = 42;
  *(_DWORD *)(a1 + 8092) = 586;
  *(_DWORD *)(a1 + 15072) = 17;
  *(_DWORD *)(a1 + 15076) = 17;
  *(_DWORD *)(a1 + 15080) = 24;
  *(_QWORD *)(a1 + 15084) = 32;
  *(_DWORD *)(a1 + 15092) = 0;
  *(_DWORD *)a1 = 0;
  memset((void *)(a1 + 8), 0, 0x960u);
  *(_DWORD *)(a1 + 2408) = 0;
  memset((void *)(a1 + 2416), 0, 0x200u);
  *(_DWORD *)(a1 + 2928) = 0;
  memset((void *)(a1 + 2936), 0, 0x908u);
  *(_DWORD *)(a1 + 5248) = 0;
  memset((void *)(a1 + 5256), 0, 0x200u);
  memset((void *)(a1 + 5768), 0, 0x908u);
  *(_DWORD *)(a1 + 8112) = 0;
  *(_DWORD *)(a1 + 12740) = 0;
  v5 = time(0);
  srand(v5);
  inited = CGameBoard::InitDirectDraw((CGameBoard *)a1);
  if ( inited < 0 )
  {
    exception::exception((exception *)pExceptionObject, (const char *const *)&off_4648F0, 1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    throw (std::bad_alloc *)pExceptionObject;
  }
  inited = CDisplay::CreateSurfaceFromBitmap(
             g_pDisplay,
             &g_pGamePiecesSurface,
             (unsigned __int16 *)0x1F5,
             0x17Du,
             0x190u);
  if ( inited < 0 )
  {
    exception::exception((exception *)v28, (const char *const *)&off_4648F0, 1);
    v28[0] = &std::bad_alloc::`vftable';
    throw (std::bad_alloc *)v28;
  }
  inited = CSurface::SetColorKey(g_pGamePiecesSurface, 0xFF00FFu);
  *(_QWORD *)(a1 + 15144) = 0;
  *(_QWORD *)(a1 + 15104) = 0;
  *(_QWORD *)(a1 + 15112) = 0;
  *(_QWORD *)(a1 + 15120) = 0;
  *(_QWORD *)(a1 + 15128) = 0;
  try
  {
    v6 = operator new(0x20u);
    if ( v6 )
    {
      *(_QWORD *)v6 = &CInk::`vftable';
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v25, "CInk::CInk", 0);
      Helpers::GetClientRect(a2, &g_rcClient, 0, v7);
      dword_4B8E90 = 10 * (dword_4B8EA0 - g_rcClient.unused);
      dword_4B8E94 = 10 * (dword_4B8EA4 - dword_4B8E9C);
      g_hWnd = a2;
      v6[6] = 0;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v25);
    }
    else
    {
      v6 = 0;
    }
    *(_QWORD *)(a1 + 15144) = v6;
    v8 = (CBallManager *)operator new(0x9F0u);
    if ( v8 )
      v9 = CBallManager::CBallManager(v8);
    else
      v9 = 0;
    *(_QWORD *)(a1 + 15104) = v9;
    v10 = (CScoreManager *)operator new(0x30u);
    if ( v10 )
      v11 = CScoreManager::CScoreManager(v10);
    else
      v11 = 0;
    *(_QWORD *)(a1 + 15112) = v11;
    v12 = (CTileManager *)operator new(0x38u);
    if ( v12 )
      v13 = CTileManager::CTileManager(v12);
    else
      v13 = 0;
    *(_QWORD *)(a1 + 15120) = v13;
    v14 = (CTimeManager *)operator new(0x40u);
    if ( v14 )
      v4 = CTimeManager::CTimeManager(v14);
    *(_QWORD *)(a1 + 15128) = v4;
  }
  catch ( std::bad_alloc )
  {
    v18 = &v23;
    v16 = *(CInk **)(a1 + 15144);
    if ( v16 )
    {
      CInk::`scalar deleting destructor'(v16, 1u);
      *(_QWORD *)(a1 + 15144) = 0;
      v17 = WPP_GLOBAL_Control;
    }
    else
    {
      v17 = WPP_GLOBAL_Control;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LOWORD(v18) = 10;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v18, qword_401928);
        v17 = WPP_GLOBAL_Control;
      }
    }
    v19 = *(CBall ***)(a1 + 15104);
    if ( v19 )
    {
      *v19 = (CBall *)&CBallManager::`vftable';
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v25, "CBallManager::~CBallManager", 0);
      v20 = v19 + 8;
      v21 = 6;
      do
      {
        if ( *v20 )
        {
          CBall::Release(*v20);
          *v20 = 0;
        }
        ++v20;
        --v21;
      }
      while ( v21 );
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v25);
      operator delete(v19);
      *(_QWORD *)(a1 + 15104) = 0;
      v17 = WPP_GLOBAL_Control;
    }
    else if ( v17 != &WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 4) != 0 )
    {
      LOWORD(v18) = 11;
      WPP_SF_(v17[2], v18, qword_401928);
      v17 = WPP_GLOBAL_Control;
    }
    v22 = *(_DWORD **)(a1 + 15112);
    if ( v22 )
    {
      *(_QWORD *)v22 = &CScoreManager::`vftable';
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v25, "CScoreManager::~CScoreManager", 0);
      CRegistryManager::WriteHiScore((CRegistryManager *)&g_CRegistryManager, v22[10]);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v25);
      operator delete(v22);
      *(_QWORD *)(a1 + 15112) = 0;
      v17 = WPP_GLOBAL_Control;
    }
    else if ( v17 != &WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 4) != 0 )
    {
      LOWORD(v18) = 12;
      WPP_SF_(v17[2], v18, qword_401928);
      v17 = WPP_GLOBAL_Control;
    }
    if ( *(_QWORD *)(a1 + 15120) )
    {
      operator delete(*(void **)(a1 + 15120));
      *(_QWORD *)(a1 + 15120) = 0;
      v17 = WPP_GLOBAL_Control;
    }
    else if ( v17 != &WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 4) != 0 )
    {
      LOWORD(v18) = 13;
      WPP_SF_(v17[2], v18, qword_401928);
      v17 = WPP_GLOBAL_Control;
    }
    if ( *(_QWORD *)(a1 + 15128) )
    {
      operator delete(*(void **)(a1 + 15128));
      *(_QWORD *)(a1 + 15128) = 0;
    }
    else if ( v17 != &WPP_GLOBAL_Control && (*((_BYTE *)v17 + 28) & 4) != 0 )
    {
      LOWORD(v18) = 14;
      WPP_SF_(v17[2], v18, qword_401928);
    }
    inited = -2147467259;
    throw;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v26);
  return a1;
}
