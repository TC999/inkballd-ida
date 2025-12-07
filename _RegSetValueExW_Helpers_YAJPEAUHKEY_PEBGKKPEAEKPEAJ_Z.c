__int64 __fastcall Helpers::RegSetValueExW(
        HKEY hKey,
        const WCHAR *lpValueName,
        const unsigned __int16 *a3,
        __int64 a4,
        BYTE *lpData,
        unsigned __int8 *a6,
        unsigned int a7)
{
  LSTATUS v9; // eax
  unsigned int v10; // ebx
  unsigned int v11; // r9d
  const char *v13[3]; // [rsp+30h] [rbp-18h] BYREF

  a7 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "Helpers::RegSetValueExW", (int *)&a7);
  v9 = RegSetValueExW(hKey, lpValueName, 0, 4u, lpData, 4u);
  v10 = v9;
  if ( v9 )
  {
    v11 = (unsigned __int16)v9 | 0x80070000;
    if ( v9 <= 0 )
      v11 = v9;
    a7 = v11;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x3Du, &stru_4015E0, v11);
  }
  Helpers::CLogBlock::~CLogBlock(v13);
  return v10;
}
