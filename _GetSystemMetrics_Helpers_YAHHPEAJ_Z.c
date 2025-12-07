__int64 __fastcall Helpers::GetSystemMetrics(Helpers *this, __int64 a2, int *a3)
{
  int v3; // ebx
  unsigned int SystemMetrics; // ebx
  const char *v6[3]; // [rsp+20h] [rbp-18h] BYREF
  int v7; // [rsp+48h] [rbp+10h] BYREF
  int v8; // [rsp+4Ch] [rbp+14h]

  v8 = HIDWORD(a2);
  v7 = 0;
  v3 = (int)this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "Helpers::GetSystemMetrics", &v7);
  SystemMetrics = GetSystemMetrics(v3);
  if ( !SystemMetrics )
  {
    v7 = -2147467259;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x33u, &stru_4015E0, -2147467259);
  }
  Helpers::CLogBlock::~CLogBlock(v6);
  return SystemMetrics;
}
