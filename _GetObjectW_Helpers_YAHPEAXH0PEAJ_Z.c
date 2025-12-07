__int64 __fastcall Helpers::GetObjectW(HANDLE h, void *a2, void *a3, void *a4)
{
  unsigned int ObjectW; // ebx
  signed int LastError; // eax
  signed int v8; // r9d
  const char *v10[3]; // [rsp+20h] [rbp-18h] BYREF
  int v11; // [rsp+58h] [rbp+20h] BYREF
  int v12; // [rsp+5Ch] [rbp+24h]

  v12 = HIDWORD(a4);
  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "Helpers::GetObjectW", &v11);
  SetLastError(0);
  ObjectW = GetObjectW(h, 32, a3);
  LastError = GetLastError();
  v8 = (unsigned __int16)LastError | 0x80070000;
  if ( LastError <= 0 )
    v8 = LastError;
  v11 = v8;
  if ( v8 < 0 && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x12u, &stru_4015E0, v8);
  Helpers::CLogBlock::~CLogBlock(v10);
  return ObjectW;
}
