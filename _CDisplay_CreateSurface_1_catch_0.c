// positive sp value has been detected, the output may be wrong!
void *__fastcall CDisplay::CreateSurface_::_1_::catch_0(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp

  v2 = a2;
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    LOWORD(a2) = 25;
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, qword_401610);
  }
  *(_DWORD *)(v2 + 32) = -2147024882;
  return &loc_413867;
}
