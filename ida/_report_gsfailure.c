void __cdecl __noreturn _report_gsfailure(uintptr_t StackCookie)
{
  HANDLE CurrentProcess; // rax
  PVOID HandlerData; // [rsp+40h] [rbp-48h] BYREF
  unsigned __int64 EstablisherFrame; // [rsp+48h] [rbp-40h] BYREF
  PRUNTIME_FUNCTION FunctionEntry; // [rsp+50h] [rbp-38h]
  ULONG64 ControlPc; // [rsp+58h] [rbp-30h]
  unsigned __int64 ImageBase[5]; // [rsp+60h] [rbp-28h] BYREF
  DWORD64 retaddr; // [rsp+88h] [rbp+0h]
  uintptr_t v8; // [rsp+90h] [rbp+8h] BYREF

  v8 = StackCookie;
  RtlCaptureContext(&ContextRecord);
  ControlPc = ContextRecord.Rip;
  FunctionEntry = RtlLookupFunctionEntry(ContextRecord.Rip, ImageBase, 0);
  if ( FunctionEntry )
  {
    RtlVirtualUnwind(0, ImageBase[0], ControlPc, FunctionEntry, &ContextRecord, &HandlerData, &EstablisherFrame, 0);
  }
  else
  {
    ContextRecord.Rip = retaddr;
    ContextRecord.Rsp = (DWORD64)&v8;
  }
  qword_464B40 = ContextRecord.Rip;
  ContextRecord.Rcx = v8;
  dword_464B30 = -1073740791;
  dword_464B34 = 1;
  ImageBase[2] = _security_cookie_complement;
  SetUnhandledExceptionFilter(0);
  UnhandledExceptionFilter((struct _EXCEPTION_POINTERS *)&ExceptionInfo);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(CurrentProcess, 0xC0000409);
}
