// Hidden C++ exception states: #wind=1
__int64 __fastcall CTimeManager::InitSurface(CTimeManager *this)
{
  _BYTE v3[32]; // [rsp+28h] [rbp-20h] BYREF
  int v4; // [rsp+50h] [rbp+8h] BYREF

  v4 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTimeManager::InitSurface", &v4);
  LODWORD(this) = CDisplay::CreateSurface(
                    g_pDisplay,
                    &g_pTimeManagerSurface,
                    *((_DWORD *)this + 4),
                    *((_DWORD *)this + 5));
  v4 = (int)this;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return (unsigned int)this;
}
