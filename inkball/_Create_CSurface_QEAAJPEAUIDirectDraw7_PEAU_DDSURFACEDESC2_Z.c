// Hidden C++ exception states: #wind=1
__int64 __fastcall CSurface::Create(CSurface *this, struct IDirectDraw7 *a2, struct _DDSURFACEDESC2 *a3)
{
  int v6; // ebx
  _BYTE v8[32]; // [rsp+28h] [rbp-20h] BYREF
  int v9; // [rsp+58h] [rbp+10h] BYREF

  v9 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSurface::Create", &v9);
  v6 = ((__int64 (__fastcall *)(struct IDirectDraw7 *, struct _DDSURFACEDESC2 *, CSurface *, _QWORD, __int64))a2->lpVtbl->CreateSurface)(
         a2,
         a3,
         this,
         0,
         -2);
  v9 = v6;
  if ( v6 < 0 )
  {
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x25u, (const GUID *)qword_401610, v6);
      v6 = v9;
    }
  }
  else
  {
    *((_DWORD *)this + 2) = 136;
    v6 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 176LL))(*(_QWORD *)this);
    v9 = v6;
    if ( v6 < 0
      && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x24u, (const GUID *)qword_401610, v6);
      v6 = v9;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return (unsigned int)v6;
}
