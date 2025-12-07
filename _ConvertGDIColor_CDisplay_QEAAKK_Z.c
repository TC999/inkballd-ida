// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::ConvertGDIColor(CDisplay *this, COLORREF a2)
{
  CDisplay *v3; // rdi
  unsigned int v4; // ebx
  int v5; // esi
  int v6; // eax
  COLORREF Pixel; // ebp
  int v8; // eax
  _BYTE v10[16]; // [rsp+30h] [rbp-C8h] BYREF
  __int64 v11; // [rsp+40h] [rbp-B8h]
  int v12[10]; // [rsp+50h] [rbp-A8h] BYREF
  int *v13; // [rsp+78h] [rbp-80h]
  unsigned int v14; // [rsp+ACh] [rbp-4Ch]
  HDC hdc; // [rsp+100h] [rbp+8h] BYREF

  hdc = (HDC)this;
  v11 = -2;
  v3 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CDisplay::ConvertGDIColor", 0);
  v4 = 0;
  if ( *((_QWORD *)v3 + 5) )
  {
    v5 = -1;
    v6 = (*(__int64 (__fastcall **)(_QWORD, HDC *))(**((_QWORD **)v3 + 5) + 136LL))(*((_QWORD *)v3 + 5), &hdc);
    if ( v6 )
    {
      if ( WPP_GLOBAL_Control == (_UNKNOWN *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      {
        Pixel = (unsigned int)hdc;
      }
      else
      {
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x22u, (const GUID *)qword_401610, v6);
        Pixel = (unsigned int)hdc;
      }
    }
    else
    {
      Pixel = GetPixel(hdc, 0, 0);
      SetPixel(hdc, 0, 0, a2);
      (*(void (__fastcall **)(_QWORD, HDC))(**((_QWORD **)v3 + 5) + 208LL))(*((_QWORD *)v3 + 5), hdc);
    }
    v12[0] = 136;
    if ( !(*(unsigned int (__fastcall **)(_QWORD, _QWORD, int *, __int64, _QWORD))(**((_QWORD **)v3 + 5) + 200LL))(
            *((_QWORD *)v3 + 5),
            0,
            v12,
            1,
            0) )
    {
      v5 = *v13;
      if ( v14 < 0x20 )
        v5 &= (1 << v14) - 1;
      (*(void (__fastcall **)(_QWORD, _QWORD))(**((_QWORD **)v3 + 5) + 256LL))(*((_QWORD *)v3 + 5), 0);
    }
    v8 = (*(__int64 (__fastcall **)(_QWORD, HDC *))(**((_QWORD **)v3 + 5) + 136LL))(*((_QWORD *)v3 + 5), &hdc);
    if ( v8 )
    {
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x23u, (const GUID *)qword_401610, v8);
    }
    else
    {
      SetPixel(hdc, 0, 0, Pixel);
      (*(void (__fastcall **)(_QWORD, HDC))(**((_QWORD **)v3 + 5) + 208LL))(*((_QWORD *)v3 + 5), hdc);
    }
    v4 = v5;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return v4;
}
