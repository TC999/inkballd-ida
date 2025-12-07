void __fastcall __noreturn CBallManager::CBallManager_::_1_::catch_0(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // rdi
  __int64 v4; // rbx
  CBall **v5; // r12

  v2 = a2;
  v3 = *(int *)(a2 + 176);
  v4 = v3;
  if ( v3 > 0 )
  {
    v5 = (CBall **)(*(_QWORD *)(a2 + 160) + 8 * v3 + 64);
    LODWORD(v3) = 0;
    do
    {
      --v4;
      if ( *--v5 )
      {
        CBall::Release(*v5);
        *v5 = 0;
      }
    }
    while ( v4 > 0 );
  }
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    LOWORD(a2) = 10;
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, (__int64)&MessageGuid, v3 - 1);
  }
  *(_DWORD *)(v2 + 168) = -2147467259;
  throw;
}
