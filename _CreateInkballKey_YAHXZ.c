__int64 CreateInkballKey(void)
{
  unsigned int v0; // ebx
  LSTATUS v1; // eax
  LSTATUS v2; // edi
  unsigned int v3; // r9d
  int *v4; // r8
  _BYTE v6[16]; // [rsp+50h] [rbp-28h] BYREF
  _BYTE v7[24]; // [rsp+60h] [rbp-18h] BYREF
  int v8; // [rsp+80h] [rbp+8h] BYREF
  HKEY hKey; // [rsp+88h] [rbp+10h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CreateInkballKey", 0);
  v0 = 0;
  v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "Helpers::RegCreateKeyExW", &v8);
  v1 = RegCreateKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", 0, 0, 0, 0x2001Fu, 0, &hKey, 0);
  v2 = v1;
  if ( v1 )
  {
    v3 = (unsigned __int16)v1 | 0x80070000;
    if ( v1 <= 0 )
      v3 = v1;
    v8 = v3;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x3Bu, &stru_4015E0, v3);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  if ( !v2 )
  {
    v0 = 1;
    Helpers::RegCloseKey(hKey, 0, v4);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v0;
}
