__int64 __fastcall Helpers::RegCloseKey(HKEY hKey, HKEY a2, int *a3)
{
  LSTATUS v4; // eax
  unsigned int v5; // ebx
  unsigned int v6; // r9d
  const char *v8[3]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v9; // [rsp+48h] [rbp+10h] BYREF
  int v10; // [rsp+4Ch] [rbp+14h]

  v10 = HIDWORD(a2);
  v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "Helpers::RegCloseKey", (int *)&v9);
  v4 = RegCloseKey(hKey);
  v5 = v4;
  if ( v4 )
  {
    v6 = (unsigned __int16)v4 | 0x80070000;
    if ( v4 <= 0 )
      v6 = v4;
    v9 = v6;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x3Au, &stru_4015E0, v6);
  }
  Helpers::CLogBlock::~CLogBlock(v8);
  return v5;
}
