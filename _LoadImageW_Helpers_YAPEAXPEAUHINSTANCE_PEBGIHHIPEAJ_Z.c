HANDLE __fastcall Helpers::LoadImageW(
        HINSTANCE hInst,
        HINSTANCE a2,
        const unsigned __int16 *a3,
        __int64 a4,
        int a5,
        UINT fuLoad,
        int *a7)
{
  HANDLE ImageW; // rbx
  signed int LastError; // eax
  int v10; // edx
  int v12; // [rsp+30h] [rbp-28h] BYREF
  const char *v13[4]; // [rsp+38h] [rbp-20h] BYREF

  v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "Helpers::LoadImageW", &v12);
  ImageW = LoadImageW(hInst, (LPCWSTR)0x1F5, 0, 381, 400, fuLoad);
  if ( ImageW )
    goto LABEL_7;
  LastError = GetLastError();
  v10 = (unsigned __int16)LastError | 0x80070000;
  if ( LastError <= 0 )
    v10 = LastError;
  v12 = v10;
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Du, &stru_4015E0, v10);
LABEL_7:
    v10 = v12;
  }
  if ( a7 )
    *a7 = v10;
  Helpers::CLogBlock::~CLogBlock(v13);
  return ImageW;
}
