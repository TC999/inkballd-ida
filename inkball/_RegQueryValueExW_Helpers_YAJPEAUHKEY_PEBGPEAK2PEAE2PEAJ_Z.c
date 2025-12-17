__int64 __fastcall Helpers::RegQueryValueExW(
        HKEY hKey,
        const WCHAR *lpValueName,
        const unsigned __int16 *a3,
        unsigned int *a4,
        LPBYTE lpData,
        DWORD *lpcbData,
        unsigned int *a7)
{
  LSTATUS Value; // eax
  unsigned int v11; // ebx
  unsigned int v12; // r9d
  const char *v14[3]; // [rsp+30h] [rbp-18h] BYREF

  LODWORD(a7) = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "Helpers::RegQueryValueExW", (int *)&a7);
  Value = RegQueryValueExW(hKey, lpValueName, 0, a4, lpData, lpcbData);
  v11 = Value;
  if ( Value )
  {
    v12 = (unsigned __int16)Value | 0x80070000;
    if ( Value <= 0 )
      v12 = Value;
    LODWORD(a7) = v12;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x3Cu, &stru_4015E0, v12);
  }
  Helpers::CLogBlock::~CLogBlock(v14);
  return v11;
}
