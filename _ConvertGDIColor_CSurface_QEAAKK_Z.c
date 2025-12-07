// Hidden C++ exception states: #wind=1
__int64 __fastcall CSurface::ConvertGDIColor(CSurface *this)
{
  unsigned int v2; // ebx
  int v3; // esi
  int v4; // eax
  COLORREF Pixel; // ebp
  int v6; // eax
  _BYTE v8[16]; // [rsp+30h] [rbp-C8h] BYREF
  __int64 v9; // [rsp+40h] [rbp-B8h]
  int v10[10]; // [rsp+50h] [rbp-A8h] BYREF
  int *v11; // [rsp+78h] [rbp-80h]
  unsigned int v12; // [rsp+ACh] [rbp-4Ch]
  HDC hdc; // [rsp+100h] [rbp+8h] BYREF

  v9 = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSurface::ConvertGDIColor", 0);
  v2 = 0;
  if ( *(_QWORD *)this )
  {
    v3 = -1;
    v4 = (*(__int64 (__fastcall **)(_QWORD, HDC *))(**(_QWORD **)this + 136LL))(*(_QWORD *)this, &hdc);
    if ( v4 )
    {
      if ( WPP_GLOBAL_Control == (_UNKNOWN *)&WPP_GLOBAL_Control || (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) == 0 )
      {
        Pixel = (unsigned int)hdc;
      }
      else
      {
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Bu, (const GUID *)qword_401610, v4);
        Pixel = (unsigned int)hdc;
      }
    }
    else
    {
      Pixel = GetPixel(hdc, 0, 0);
      SetPixel(hdc, 0, 0, 0xFF00FFu);
      (*(void (__fastcall **)(_QWORD, HDC))(**(_QWORD **)this + 208LL))(*(_QWORD *)this, hdc);
    }
    v10[0] = 136;
    if ( !(*(unsigned int (__fastcall **)(_QWORD, _QWORD, int *, __int64, _QWORD))(**(_QWORD **)this + 200LL))(
            *(_QWORD *)this,
            0,
            v10,
            1,
            0) )
    {
      v3 = *v11;
      if ( v12 < 0x20 )
        v3 &= (1 << v12) - 1;
      (*(void (__fastcall **)(_QWORD, _QWORD))(**(_QWORD **)this + 256LL))(*(_QWORD *)this, 0);
    }
    v6 = (*(__int64 (__fastcall **)(_QWORD, HDC *))(**(_QWORD **)this + 136LL))(*(_QWORD *)this, &hdc);
    if ( v6 )
    {
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Cu, (const GUID *)qword_401610, v6);
    }
    else
    {
      SetPixel(hdc, 0, 0, Pixel);
      (*(void (__fastcall **)(_QWORD, HDC))(**(_QWORD **)this + 208LL))(*(_QWORD *)this, hdc);
    }
    v2 = v3;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v2;
}
