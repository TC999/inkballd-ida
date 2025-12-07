// Hidden C++ exception states: #wind=1
CTileManager *__fastcall CTileManager::CTileManager(CTileManager *this)
{
  _BYTE v3[16]; // [rsp+28h] [rbp-30h] BYREF
  _QWORD pExceptionObject[4]; // [rsp+38h] [rbp-20h] BYREF

  *(_QWORD *)this = &CTileManager::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTileManager::CTileManager", 0);
  *((_DWORD *)this + 2) = 445;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 42;
  *((_DWORD *)this + 5) = 42;
  *((_DWORD *)this + 6) = 445;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 487;
  *((_DWORD *)this + 9) = 42;
  if ( (int)CTileManager::InitSurface(this) < 0 )
  {
    exception::exception((exception *)pExceptionObject, (const char *const *)&off_4648F0, 1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    throw (std::bad_alloc *)pExceptionObject;
  }
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 12) = 1600;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return this;
}
