void __fastcall CRegistryManager::WriteHiScore(CRegistryManager *this, int a2)
{
  _BYTE v3[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CRegistryManager::WriteHiScore", 0);
  if ( !WriteRegValueDWORD(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", L"HiScore", a2) )
  {
    CreateInkballKey();
    WriteRegValueDWORD(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", L"HiScore", a2);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
