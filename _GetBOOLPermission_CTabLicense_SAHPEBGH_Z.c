void __fastcall CTabLicense::GetBOOLPermission(const unsigned __int16 *a1)
{
  int v1; // ebx
  HRESULT v2; // eax
  __int64 v3; // rdx
  DWORD v4; // ecx
  int v5; // [rsp+20h] [rbp-28h]
  const char *v6[3]; // [rsp+30h] [rbp-18h] BYREF
  DWORD pdwValue; // [rsp+60h] [rbp+18h] BYREF
  int v8; // [rsp+68h] [rbp+20h] BYREF

  v1 = 0;
  v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CTabLicense::GetBOOLPermission", &v8);
  pdwValue = 0;
  v2 = SLGetWindowsInformationDWORD(L"TabletPCInkBall-EnableGame", &pdwValue);
  v4 = pdwValue;
  v8 = v2;
  if ( v2 < 0 )
    v4 = 0;
  pdwValue = v4;
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 0x10) != 0 )
  {
    LOWORD(v3) = 10;
    LOBYTE(v1) = v4 == 1;
    v5 = v1;
    WPP_SF_Sd(
      *((_QWORD *)WPP_GLOBAL_Control + 2),
      v3,
      (__int64)&stru_4015D0,
      (__int64)L"TabletPCInkBall-EnableGame",
      v5);
  }
  Helpers::CLogBlock::~CLogBlock(v6);
  JUMPOUT(0x41965C);
}
