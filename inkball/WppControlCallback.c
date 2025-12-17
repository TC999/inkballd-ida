__int64 __fastcall WppControlCallback(
        WMIDPREQUESTCODE RequestCode,
        _QWORD **RequestContext,
        ULONG *BufferSize,
        PVOID Buffer)
{
  int v4; // ecx
  TRACEHANDLE TraceLoggerHandle; // rdi
  ULONG TraceEnableFlags; // edx
  UCHAR TraceEnableLevel; // si

  *BufferSize = 0;
  v4 = RequestCode - 4;
  if ( v4 )
  {
    if ( v4 != 1 )
      return 87;
    TraceLoggerHandle = 0;
    TraceEnableFlags = 0;
    TraceEnableLevel = 0;
  }
  else
  {
    TraceLoggerHandle = GetTraceLoggerHandle(Buffer);
    TraceEnableLevel = GetTraceEnableLevel(TraceLoggerHandle);
    TraceEnableFlags = GetTraceEnableFlags(TraceLoggerHandle);
  }
  if ( (*((_BYTE *)RequestContext + 26) & 1) != 0 && RequestContext[2] )
  {
    *RequestContext[2] = TraceLoggerHandle;
    *((_DWORD *)RequestContext[2] + 3) = TraceEnableLevel;
    *((_DWORD *)RequestContext[2] + 2) = TraceEnableFlags;
  }
  else
  {
    if ( (*((_BYTE *)RequestContext + 26) & 2) != 0 )
    {
      if ( RequestContext[2] )
        RequestContext = (_QWORD **)RequestContext[2];
    }
    RequestContext[2] = (_QWORD *)TraceLoggerHandle;
    *((_BYTE *)RequestContext + 25) = TraceEnableLevel;
    *((_DWORD *)RequestContext + 7) = TraceEnableFlags;
  }
  return 0;
}
