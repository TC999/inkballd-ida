_BOOL8 __fastcall WriteRegValueDWORD(HKEY a1, const unsigned __int16 *a2, unsigned __int16 *a3, int a4)
{
  BOOL v5; // ebx
  int *v6; // r8
  unsigned __int8 *v8; // [rsp+28h] [rbp-40h]
  int *v9; // [rsp+30h] [rbp-38h]
  int *v10; // [rsp+38h] [rbp-30h]
  HKEY hKey; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v12[32]; // [rsp+48h] [rbp-20h] BYREF
  int v13; // [rsp+88h] [rbp+20h] BYREF

  v13 = a4;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "WriteRegValueDWORD", 0);
  v5 = 0;
  if ( !Helpers::RegOpenKeyExW(
          (Helpers *)0xFFFFFFFF80000001LL,
          (HKEY)L"SOFTWARE\\Microsoft\\Inkball",
          0,
          0x2001Fu,
          (unsigned int)&hKey,
          0,
          v9) )
  {
    LODWORD(v8) = 4;
    v5 = Helpers::RegSetValueExW(hKey, (HKEY)a3, 0, 4u, (BYTE *)&v13, v8, 0, v10) == 0;
    Helpers::RegCloseKey(hKey, 0, v6);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
  return v5;
}
