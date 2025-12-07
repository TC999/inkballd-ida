int _wmainCRTStartup()
{
  PVOID StackBase; // rdi
  int v1; // r12d
  signed __int64 v2; // rax
  int v3; // eax
  __int64 (**i)(void); // rdi
  int result; // eax
  wchar_t *v6; // rcx
  BOOL v7; // edx
  int wShowWindow; // r9d
  _STARTUPINFOW StartupInfo; // [rsp+40h] [rbp-78h] BYREF

  GetStartupInfoW(&StartupInfo);
  StackBase = NtCurrentTeb()->NtTib.StackBase;
  v1 = 0;
  while ( 1 )
  {
    v2 = _InterlockedCompareExchange64(&_native_startup_lock, (signed __int64)StackBase, 0);
    if ( !v2 )
      break;
    if ( (PVOID)v2 == StackBase )
    {
      v1 = 1;
      break;
    }
    Sleep(0x3E8u);
  }
  if ( _native_startup_state == 1 )
  {
    amsg_exit(31);
  }
  else
  {
    v3 = _native_startup_state;
    if ( _native_startup_state )
    {
      dword_464B14 = 1;
    }
    else
    {
      _native_startup_state = 1;
      for ( i = (__int64 (**)(void))&_xi_a; i < (__int64 (**)(void))&_xi_z && !v3; ++i )
      {
        if ( *i )
          v3 = (*i)();
      }
      if ( v3 )
        return 255;
    }
  }
  if ( _native_startup_state == 1 )
  {
    initterm((_PVFV *)&_xc_a, (_PVFV *)&_xc_z);
    _native_startup_state = 2;
  }
  if ( !v1 )
    _InterlockedExchange64(&_native_startup_lock, 0);
  if ( _dyn_tls_init_callback && (unsigned int)IsNonwritableInCurrentImage(&_dyn_tls_init_callback) )
    _dyn_tls_init_callback(0, 2);
  if ( !_wcmdln )
    return 255;
  v6 = _wcmdln;
  v7 = 0;
  while ( *v6 > 0x20u || *v6 && v7 )
  {
    if ( *v6 == 34 )
      v7 = !v7;
    ++v6;
  }
  while ( *v6 && *v6 <= 0x20u )
    ++v6;
  wShowWindow = 10;
  if ( (StartupInfo.dwFlags & 1) != 0 )
    wShowWindow = StartupInfo.wShowWindow;
  result = wWinMain((HINSTANCE)0x400000, 0, v6, wShowWindow);
  dword_464B10 = result;
  if ( !dword_464AF4 )
    exit(result);
  if ( !dword_464B14 )
  {
    _cexit();
    return dword_464B10;
  }
  return result;
}
