__int64 __fastcall Helpers::LoadStringW(
        HINSTANCE hInstance,
        HINSTANCE uID,
        LPWSTR lpBuffer,
        unsigned __int16 *cchBufferMax,
        unsigned int a5)
{
  UINT v6; // esi
  int v8; // ebx
  unsigned int StringW; // ebx
  signed int LastError; // eax
  unsigned int v11; // r9d
  const char *v13[3]; // [rsp+20h] [rbp-18h] BYREF

  a5 = 0;
  v6 = (unsigned int)uID;
  v8 = (int)cchBufferMax;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "Helpers::LoadStringW", (int *)&a5);
  StringW = LoadStringW(hInstance, v6, lpBuffer, v8);
  if ( !StringW )
  {
    LastError = GetLastError();
    v11 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v11 = LastError;
    a5 = v11;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Eu, &stru_4015E0, v11);
  }
  Helpers::CLogBlock::~CLogBlock(v13);
  return StringW;
}
