ULONG __fastcall WPP_SF_d(TRACEHANDLE a1, __int64 a2, __int64 a3, int a4)
{
  int v5; // [rsp+68h] [rbp+20h] BYREF

  v5 = a4;
  return TraceMessage(a1, 0x2Bu, &MessageGuid, 0xAu, &v5, 4, 0);
}
