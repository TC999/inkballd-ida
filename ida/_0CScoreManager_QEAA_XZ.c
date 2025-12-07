// Hidden C++ exception states: #wind=1
CScoreManager *__fastcall CScoreManager::CScoreManager(CScoreManager *this)
{
  unsigned int v2; // ebx
  _QWORD pExceptionObject[3]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v5[24]; // [rsp+40h] [rbp-18h] BYREF
  unsigned int v6; // [rsp+60h] [rbp+8h] BYREF

  *(_QWORD *)this = &CScoreManager::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CScoreManager::CScoreManager", 0);
  *((_DWORD *)this + 2) = 104;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 341;
  *((_DWORD *)this + 5) = 42;
  *((_DWORD *)this + 6) = 104;
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 445;
  *((_DWORD *)this + 9) = 42;
  if ( (int)CScoreManager::InitSurface(this) < 0 )
  {
    exception::exception((exception *)pExceptionObject, (const char *const *)&off_4648F0, 1);
    pExceptionObject[0] = &std::bad_alloc::`vftable';
    throw (std::bad_alloc *)pExceptionObject;
  }
  CSurface::Clear(g_pScoreManagerSurface, 0);
  *((_DWORD *)this + 11) = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)pExceptionObject, "CRegistryManager::ReadHiScore", 0);
  if ( ReadRegValueDWORD(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", L"HiScore", (BYTE *)&v6) )
  {
    v2 = v6;
  }
  else
  {
    CreateInkballKey();
    v2 = 5000;
    CRegistryManager::WriteHiScore((CRegistryManager *)&g_CRegistryManager, 5000);
    v6 = 5000;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)pExceptionObject);
  *((_DWORD *)this + 10) = v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return this;
}
