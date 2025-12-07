HGLOBAL __fastcall Helpers::LoadResource(Helpers *this, HRSRC a2, HRSRC a3, int *a4)
{
  HGLOBAL Resource; // rbx
  signed int LastError; // eax
  unsigned int v7; // r9d
  const char *v9[3]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v10; // [rsp+50h] [rbp+18h] BYREF
  int v11; // [rsp+54h] [rbp+1Ch]

  v11 = HIDWORD(a3);
  v10 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "Helpers::LoadResource", (int *)&v10);
  Resource = LoadResource(0, a2);
  if ( !Resource )
  {
    LastError = GetLastError();
    v7 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v7 = LastError;
    v10 = v7;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x66u, &stru_4015E0, v7);
  }
  Helpers::CLogBlock::~CLogBlock(v9);
  return Resource;
}
