void __fastcall __noreturn BallPoints::BallPoints_::_1_::catch_0(__int64 a1, __int64 a2)
{
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    LOWORD(a2) = 12;
    WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), a2, qword_401968);
  }
  throw;
}
