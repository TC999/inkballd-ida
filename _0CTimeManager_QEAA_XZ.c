// Hidden C++ exception states: #wind=1
CTimeManager *__fastcall CTimeManager::CTimeManager(CTimeManager *this)
{
  struct CSurface *v2; // rbx
  __int64 v3; // rdi
  struct CSurface *v4; // rbx
  __int64 v5; // rbx
  _QWORD pExceptionObject[3]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v8[16]; // [rsp+50h] [rbp-18h] BYREF
  int v9; // [rsp+70h] [rbp+8h] BYREF

  *(_QWORD *)this = &CTimeManager::`vftable';
  v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CTimeManager::CTimeManager", &v9);
  *((_DWORD *)this + 2) = 486;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 58;
  *((_DWORD *)this + 5) = 42;
  *((_DWORD *)this + 6) = 486;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 544;
  *((_DWORD *)this + 9) = 42;
  dwTimeDigitWidth = 9;
  dwTopDrawLoc = 13;
  dwLeftDrawDif = 3;
  if ( (int)CTimeManager::InitSurface(this) < 0 )
  {
    exception::exception((exception *)pExceptionObject, (const char *const *)&off_4648F0, 1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    throw (std::bad_alloc *)pExceptionObject;
  }
  v2 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)pExceptionObject, "CSurface::GetDDrawSurface", 0);
  v3 = *(_QWORD *)v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)pExceptionObject);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)pExceptionObject, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)pExceptionObject);
  v4 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)pExceptionObject, "CSurface::GetDDrawSurface", 0);
  v5 = *(_QWORD *)v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)pExceptionObject);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD, __int64))(*(_QWORD *)v3 + 56LL))(
    v3,
    0,
    0,
    v5,
    &dword_4B95A0,
    0,
    -2);
  *((_DWORD *)this + 10) = -1;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 1;
  *((_DWORD *)this + 15) = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return this;
}
