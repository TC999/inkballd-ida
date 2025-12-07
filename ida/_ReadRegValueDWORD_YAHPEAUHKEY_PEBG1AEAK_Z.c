_BOOL8 __fastcall ReadRegValueDWORD(HKEY a1, const unsigned __int16 *a2, unsigned __int16 *a3, BYTE *a4)
{
  BOOL v6; // ebx
  int *v7; // r8
  int *v9; // [rsp+30h] [rbp-38h]
  int *v10; // [rsp+38h] [rbp-30h]
  unsigned __int8 v11[4]; // [rsp+40h] [rbp-28h] BYREF
  unsigned int v12; // [rsp+44h] [rbp-24h] BYREF
  HKEY hKey; // [rsp+48h] [rbp-20h] BYREF
  _BYTE v14[24]; // [rsp+50h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "ReadRegValueDWORD", 0);
  v6 = 0;
  *(_DWORD *)v11 = 4;
  if ( !Helpers::RegOpenKeyExW(
          (Helpers *)0xFFFFFFFF80000001LL,
          (HKEY)L"SOFTWARE\\Microsoft\\Inkball",
          0,
          0x20019u,
          (unsigned int)&hKey,
          0,
          v9) )
  {
    v6 = Helpers::RegQueryValueExW(hKey, (HKEY)a3, 0, &v12, a4, v11, 0, v10) == 0;
    Helpers::RegCloseKey(hKey, 0, v7);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v6;
}
