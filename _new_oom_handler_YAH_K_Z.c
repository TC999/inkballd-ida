// Hidden C++ exception states: #wind=1
void __fastcall __noreturn new_oom_handler()
{
  _BYTE v0[16]; // [rsp+28h] [rbp-30h] BYREF
  _QWORD pExceptionObject[4]; // [rsp+38h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v0, "new_oom_handler", 0);
  exception::exception((exception *)pExceptionObject, (const char *const *)&off_4648F0, 1);
  pExceptionObject[0] = &std::bad_alloc::`vftable';
  throw (std::bad_alloc *)pExceptionObject;
}
