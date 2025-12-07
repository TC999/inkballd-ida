__int64 __fastcall Helpers::CloseHandle(HANDLE hObject, void *a2, int *a3)
{
  unsigned int v4; // ebx
  signed int LastError; // eax
  unsigned int v6; // r9d
  const char *v8[3]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v9; // [rsp+48h] [rbp+10h] BYREF
  int v10; // [rsp+4Ch] [rbp+14h]

  v10 = HIDWORD(a2);
  v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "Helpers::CloseHandle", (int *)&v9);
  v4 = CloseHandle(hObject);
  if ( !v4 )
  {
    LastError = GetLastError();
    v6 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v6 = LastError;
    v9 = v6;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x46u, &stru_4015E0, v6);
  }
  Helpers::CLogBlock::~CLogBlock(v8);
  return v4;
}
