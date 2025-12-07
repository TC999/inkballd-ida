Helpers::CLogBlock *__fastcall Helpers::CLogBlock::CLogBlock(Helpers::CLogBlock *this, const char *a2, int *a3)
{
  *((_QWORD *)this + 1) = a2;
  *(_QWORD *)this = a3;
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
    && _bittest((const signed __int32 *)WPP_GLOBAL_Control + 7, 0xAu) )
  {
    WPP_SF_s(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (__int64)&stru_4015E0, a2);
  }
  return this;
}
