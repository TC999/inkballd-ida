ULONG WppCleanupUm()
{
  _QWORD *v0; // rbx
  TRACEHANDLE v1; // rcx
  ULONG result; // eax

  v0 = WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control )
  {
    while ( v0 )
    {
      v1 = v0[1];
      if ( v1 )
      {
        result = UnregisterTraceGuids(v1);
        v0[1] = 0;
      }
      v0 = (_QWORD *)*v0;
    }
    WPP_GLOBAL_Control = &WPP_GLOBAL_Control;
  }
  return result;
}
