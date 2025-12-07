__int64 __fastcall Helpers::SetWindowPos(
        HWND hWnd,
        HWND hWndInsertAfter,
        HWND X,
        int Y,
        int a5,
        int cy,
        UINT uFlags,
        unsigned int a8)
{
  int v8; // edi
  unsigned int v12; // ebx
  signed int LastError; // eax
  unsigned int v14; // r9d
  const char *v16[3]; // [rsp+40h] [rbp-18h] BYREF

  a8 = 0;
  v8 = (int)X;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "Helpers::SetWindowPos", (int *)&a8);
  v12 = SetWindowPos(hWnd, hWndInsertAfter, v8, Y, a5, cy, uFlags);
  if ( !v12 )
  {
    LastError = GetLastError();
    v14 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v14 = LastError;
    a8 = v14;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x5Bu, &stru_4015E0, v14);
  }
  Helpers::CLogBlock::~CLogBlock(v16);
  return v12;
}
