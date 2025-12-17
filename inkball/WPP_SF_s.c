ULONG __fastcall WPP_SF_s(TRACEHANDLE LoggerHandle, USHORT a2, __int64 a3, const char *a4)
{
  unsigned __int64 v5; // rcx
  const char *v6; // rax

  if ( a4 )
    v5 = strlen(a4) + 1;
  else
    v5 = 5;
  v6 = "NULL";
  if ( a4 )
    v6 = a4;
  return TraceMessage(LoggerHandle, 0x2Bu, &stru_4015E0, a2, v6, v5, 0);
}
