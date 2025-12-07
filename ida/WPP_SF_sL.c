ULONG WPP_SF_sL(TRACEHANDLE LoggerHandle, __int64 a2, __int64 a3, const char *a4, ...)
{
  unsigned __int64 v5; // rcx
  const char *v6; // rax
  va_list va; // [rsp+80h] [rbp+28h] BYREF

  va_start(va, a4);
  if ( a4 )
    v5 = strlen(a4) + 1;
  else
    v5 = 5;
  v6 = "NULL";
  if ( a4 )
    v6 = a4;
  return TraceMessage(LoggerHandle, 0x2Bu, &stru_4015E0, 0xBu, v6, v5, va, 4, 0);
}
