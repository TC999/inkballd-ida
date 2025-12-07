void __fastcall __noreturn CGameBoard::CGameBoard_::_1_::catch_0(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // rdi
  CInk *v4; // rcx
  _QWORD *v5; // rcx
  CBall **v6; // r13
  CBall **v7; // r12
  __int64 v8; // r14
  _DWORD *v9; // r12

  v2 = a2;
  v3 = *(_QWORD *)(a2 + 192);
  v4 = *(CInk **)(v3 + 15144);
  if ( v4 )
  {
    CInk::`scalar deleting destructor'(v4, 1u);
    *(_QWORD *)(v3 + 15144) = 0;
    v5 = WPP_GLOBAL_Control;
  }
  else
  {
    v5 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(a2) = 10;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, qword_401928);
      v5 = WPP_GLOBAL_Control;
    }
  }
  v6 = *(CBall ***)(v3 + 15104);
  if ( v6 )
  {
    *v6 = (CBall *)&CBallManager::`vftable';
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)(v2 + 56), "CBallManager::~CBallManager", 0);
    v7 = v6 + 8;
    v8 = 6;
    do
    {
      if ( *v7 )
      {
        CBall::Release(*v7);
        *v7 = 0;
      }
      ++v7;
      --v8;
    }
    while ( v8 );
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)(v2 + 56));
    operator delete(v6);
    *(_QWORD *)(v3 + 15104) = 0;
    v5 = WPP_GLOBAL_Control;
  }
  else if ( v5 != &WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
  {
    LOWORD(a2) = 11;
    WPP_SF_(v5[2], a2, qword_401928);
    v5 = WPP_GLOBAL_Control;
  }
  v9 = *(_DWORD **)(v3 + 15112);
  if ( v9 )
  {
    *(_QWORD *)v9 = &CScoreManager::`vftable';
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)(v2 + 56), "CScoreManager::~CScoreManager", 0);
    CRegistryManager::WriteHiScore((CRegistryManager *)&g_CRegistryManager, v9[10]);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)(v2 + 56));
    operator delete(v9);
    *(_QWORD *)(v3 + 15112) = 0;
    v5 = WPP_GLOBAL_Control;
  }
  else if ( v5 != &WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
  {
    LOWORD(a2) = 12;
    WPP_SF_(v5[2], a2, qword_401928);
    v5 = WPP_GLOBAL_Control;
  }
  if ( *(_QWORD *)(v3 + 15120) )
  {
    operator delete(*(void **)(v3 + 15120));
    *(_QWORD *)(v3 + 15120) = 0;
    v5 = WPP_GLOBAL_Control;
  }
  else if ( v5 != &WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
  {
    LOWORD(a2) = 13;
    WPP_SF_(v5[2], a2, qword_401928);
    v5 = WPP_GLOBAL_Control;
  }
  if ( *(_QWORD *)(v3 + 15128) )
  {
    operator delete(*(void **)(v3 + 15128));
    *(_QWORD *)(v3 + 15128) = 0;
  }
  else if ( v5 != &WPP_GLOBAL_Control && (*((_BYTE *)v5 + 28) & 4) != 0 )
  {
    LOWORD(a2) = 14;
    WPP_SF_(v5[2], a2, qword_401928);
  }
  *(_DWORD *)(v2 + 208) = -2147467259;
  throw;
}
