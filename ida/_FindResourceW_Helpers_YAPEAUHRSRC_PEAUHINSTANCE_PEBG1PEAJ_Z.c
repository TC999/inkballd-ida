HRSRC __fastcall Helpers::FindResourceW(
        Helpers *this,
        const WCHAR *a2,
        const unsigned __int16 *a3,
        const unsigned __int16 *a4)
{
  HRSRC ResourceW; // rbx
  signed int LastError; // eax
  unsigned int v8; // r9d
  const char *v10[3]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v11; // [rsp+58h] [rbp+20h] BYREF
  int v12; // [rsp+5Ch] [rbp+24h]

  v12 = HIDWORD(a4);
  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "Helpers::FindResourceW", (int *)&v11);
  ResourceW = FindResourceW(0, a2, a3);
  if ( !ResourceW )
  {
    LastError = GetLastError();
    v8 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v8 = LastError;
    v11 = v8;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x67u, &stru_4015E0, v8);
  }
  Helpers::CLogBlock::~CLogBlock(v10);
  return ResourceW;
}
