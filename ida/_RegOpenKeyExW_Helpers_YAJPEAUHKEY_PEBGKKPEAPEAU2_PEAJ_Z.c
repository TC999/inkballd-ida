__int64 __fastcall Helpers::RegOpenKeyExW(
        Helpers *this,
        HKEY a2,
        const unsigned __int16 *a3,
        REGSAM a4,
        HKEY *phkResult,
        HKEY *a6)
{
  LSTATUS v7; // eax
  unsigned int v8; // ebx
  unsigned int v9; // r9d
  const char *v11[3]; // [rsp+30h] [rbp-18h] BYREF

  LODWORD(a6) = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "Helpers::RegOpenKeyExW", (int *)&a6);
  v7 = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Inkball", 0, a4, phkResult);
  v8 = v7;
  if ( v7 )
  {
    v9 = (unsigned __int16)v7 | 0x80070000;
    if ( v7 <= 0 )
      v9 = v7;
    LODWORD(a6) = v9;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x39u, &stru_4015E0, v9);
  }
  Helpers::CLogBlock::~CLogBlock(v11);
  return v8;
}
