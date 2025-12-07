HWND __fastcall Helpers::CreateWindowExW(
        Helpers *this,
        __int64 a2,
        const unsigned __int16 *a3,
        const unsigned __int16 *a4,
        unsigned int a5,
        int a6,
        int nWidth,
        int nHeight,
        int a9,
        HWND a10,
        HINSTANCE hInstance,
        HINSTANCE a12,
        void *a13)
{
  HWND Window; // rbx
  signed int LastError; // eax
  signed int v16; // r9d
  const char *v18[3]; // [rsp+60h] [rbp-18h] BYREF

  LODWORD(a13) = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "Helpers::CreateWindowExW", (int *)&a13);
  Window = CreateWindowExW(0, g_szAppName, a3, 0xCA0000u, 0x80000000, 0x80000000, nWidth, nHeight, 0, 0, hInstance, 0);
  if ( !Window )
  {
    LastError = GetLastError();
    v16 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v16 = LastError;
    if ( v16 >= 0 )
      v16 = -2147467259;
    LODWORD(a13) = v16;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x60u, &stru_4015E0, v16);
  }
  Helpers::CLogBlock::~CLogBlock(v18);
  return Window;
}
