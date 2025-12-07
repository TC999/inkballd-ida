__int64 __fastcall Helpers::GetClientRect(HWND hWnd, struct tagRECT *lpRect, struct tagRECT *a3, int *a4)
{
  unsigned int ClientRect; // ebx
  signed int LastError; // eax
  unsigned int v8; // r9d
  const char *v10[3]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v11; // [rsp+50h] [rbp+18h] BYREF
  int v12; // [rsp+54h] [rbp+1Ch]

  v12 = HIDWORD(a3);
  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "Helpers::GetClientRect", (int *)&v11);
  ClientRect = GetClientRect(hWnd, lpRect);
  if ( !ClientRect )
  {
    LastError = GetLastError();
    v8 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v8 = LastError;
    v11 = v8;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Du, &stru_4015E0, v8);
  }
  Helpers::CLogBlock::~CLogBlock(v10);
  return ClientRect;
}
