ULONG WPP_SF_Sd(TRACEHANDLE LoggerHandle, __int64 a2, __int64 a3, __int64 a4, ...)
{
  __int64 v5; // rcx
  const WCHAR *v6; // rdi
  bool v7; // zf
  va_list va; // [rsp+80h] [rbp+28h] BYREF

  va_start(va, a4);
  v5 = -1;
  v6 = L"TabletPCInkBall-EnableGame";
  do
  {
    if ( !v5 )
      break;
    v7 = *v6++ == 0;
    --v5;
  }
  while ( !v7 );
  return TraceMessage(LoggerHandle, 0x2Bu, &stru_4015D0, 0xAu, L"TabletPCInkBall-EnableGame", 2 * ~v5, va, 4, 0);
}
