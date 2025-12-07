__int64 __fastcall TabUtils::TabQueryPolicyValue(TabUtils *this, const unsigned __int16 *a2, _DWORD *a3, int *a4)
{
  int v5; // ebx
  LSTATUS ValueW; // eax
  unsigned int v7; // r9d
  _QWORD *v8; // rcx
  USHORT v9; // dx
  LSTATUS v10; // eax
  unsigned int v11; // ebx
  unsigned int v13; // [rsp+40h] [rbp-28h] BYREF
  DWORD pcbData; // [rsp+44h] [rbp-24h] BYREF
  const char *v15[4]; // [rsp+48h] [rbp-20h] BYREF
  TabUtils *pvData; // [rsp+70h] [rbp+8h] BYREF

  pvData = this;
  v5 = 0;
  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "TabUtils::TabQueryPolicyValue", (int *)&v13);
  if ( !a3 )
  {
    v13 = -2147467261;
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v7 = -2147467261;
      v9 = 10;
      goto LABEL_20;
    }
    goto LABEL_21;
  }
  *a3 = 0;
  pcbData = 4;
  LODWORD(pvData) = 0;
  ValueW = SHRegGetValueW(
             HKEY_LOCAL_MACHINE,
             L"SOFTWARE\\Policies\\Microsoft\\TabletPC",
             L"DisableInkball",
             536870936,
             0,
             &pvData,
             &pcbData);
  if ( !ValueW )
    goto LABEL_16;
  if ( ValueW != 2 )
  {
    v7 = (unsigned __int16)ValueW | 0x80070000;
    if ( ValueW <= 0 )
      v7 = ValueW;
    v13 = v7;
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v9 = 11;
LABEL_20:
      WPP_SF_L(v8[2], v9, (const GUID *)qword_4015C0, v7);
      goto LABEL_21;
    }
    goto LABEL_21;
  }
  pcbData = 4;
  LODWORD(pvData) = 0;
  v10 = SHRegGetValueW(
          HKEY_CURRENT_USER,
          L"SOFTWARE\\Policies\\Microsoft\\TabletPC",
          L"DisableInkball",
          536870936,
          0,
          &pvData,
          &pcbData);
  if ( !v10 )
  {
LABEL_16:
    LOBYTE(v5) = (_DWORD)pvData != 0;
    *a3 = v5;
    goto LABEL_21;
  }
  if ( v10 != 2 )
  {
    v7 = (unsigned __int16)v10 | 0x80070000;
    if ( v10 <= 0 )
      v7 = v10;
    v13 = v7;
    v8 = WPP_GLOBAL_Control;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v9 = 12;
      goto LABEL_20;
    }
  }
LABEL_21:
  v11 = v13;
  Helpers::CLogBlock::~CLogBlock(v15);
  return v11;
}
