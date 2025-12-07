// Hidden C++ exception states: #wind=2
CBallManager *__fastcall CBallManager::CBallManager(CBallManager *this)
{
  struct CSurface *v2; // rbx
  __int64 v3; // rdi
  struct CSurface *v4; // rbx
  __int64 v5; // rbx
  int v6; // edi
  void *v7; // rax
  __int64 v8; // rbx
  int v10; // edi
  __int64 v11; // rbx
  CBall **v12; // r12
  __int64 *v13; // rdx
  __int64 v14; // [rsp+0h] [rbp-98h] BYREF
  __int64 v15; // [rsp+30h] [rbp-68h]
  _BYTE v16[16]; // [rsp+38h] [rbp-60h] BYREF
  _BYTE v17[16]; // [rsp+48h] [rbp-50h] BYREF
  _QWORD pExceptionObject[8]; // [rsp+58h] [rbp-40h] BYREF
  int v20; // [rsp+A8h] [rbp+10h] BYREF
  int v21; // [rsp+B0h] [rbp+18h]
  void *v22; // [rsp+B8h] [rbp+20h]

  v15 = -2;
  *(_QWORD *)this = &CBallManager::`vftable';
  v20 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CBallManager::CBallManager", &v20);
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 104;
  *((_DWORD *)this + 5) = 42;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 104;
  *((_DWORD *)this + 9) = 42;
  if ( (int)CBallManager::InitSurface(this) < 0 )
  {
    exception::exception((exception *)pExceptionObject, (const char *const *)&off_4648F0, 1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    throw (std::bad_alloc *)pExceptionObject;
  }
  v2 = g_pBallManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CSurface::GetDDrawSurface", 0);
  v3 = *(_QWORD *)v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  v4 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CSurface::GetDDrawSurface", 0);
  v5 = *(_QWORD *)v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  v20 = (*(__int64 (__fastcall **)(__int64, char *, __int64, int *, _DWORD, _QWORD, __int64))(*(_QWORD *)v3 + 40LL))(
          v3,
          (char *)this + 24,
          v5,
          &dword_4B9570,
          0,
          0,
          v15);
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 4;
  *((_DWORD *)this + 632) = 0;
  *((_DWORD *)this + 633) = 150;
  *((_DWORD *)this + 634) = 150;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 14) = 0;
  v6 = 0;
  v21 = 0;
  try
  {
    while ( v6 < 6 )
    {
      v7 = operator new(0x1B8u);
      v22 = v7;
      if ( v7 )
        v8 = CBall::CBall((__int64)v7, 0, 0, 0, 18);
      else
        v8 = 0;
      *((_QWORD *)this + v6 + 8) = v8;
      if ( v8 )
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CBall::AddRef", 0);
        ++*(_DWORD *)(v8 + 148);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
      }
      v21 = ++v6;
    }
  }
  catch ( std::bad_alloc )
  {
    v13 = &v14;
    v10 = v21;
    v11 = v21;
    if ( v21 > 0LL )
    {
      v12 = (CBall **)((char *)this + 8 * v21 + 64);
      v10 = 0;
      do
      {
        --v11;
        if ( *--v12 )
        {
          CBall::Release(*v12);
          *v12 = 0;
        }
      }
      while ( v11 > 0 );
    }
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v13) = 10;
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), (__int64)v13, (__int64)&MessageGuid, v10 - 1);
    }
    v20 = -2147467259;
    throw;
  }
  *((_DWORD *)this + 28) = 0;
  memset((char *)this + 120, 0, 0x908u);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  return this;
}
