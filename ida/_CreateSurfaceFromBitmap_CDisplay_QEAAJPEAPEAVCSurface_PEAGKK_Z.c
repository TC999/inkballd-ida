// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::CreateSurfaceFromBitmap(
        CDisplay *this,
        struct CSurface **a2,
        unsigned __int16 *a3,
        __int64 a4,
        unsigned int a5)
{
  struct CSurface **v5; // rdi
  CDisplay *v6; // r12
  unsigned int v7; // esi
  HMODULE ModuleHandleW; // rax
  HBITMAP ImageW; // r13
  CSurface *v11; // rax
  int *v12; // r8
  CSurface *v13; // rax
  struct CSurface *v14; // rsi
  unsigned int v15; // ebx
  __int64 *v16; // rdx
  __int64 v17; // [rsp+0h] [rbp-138h] BYREF
  int *v18; // [rsp+20h] [rbp-118h]
  int *v19; // [rsp+38h] [rbp-100h]
  HBITMAP v20; // [rsp+40h] [rbp-F8h]
  _BYTE v21[16]; // [rsp+48h] [rbp-F0h] BYREF
  __int64 v22; // [rsp+58h] [rbp-E0h]
  int v23[8]; // [rsp+60h] [rbp-D8h] BYREF
  struct _DDSURFACEDESC2 v24; // [rsp+80h] [rbp-B8h] BYREF
  CDisplay *v25; // [rsp+140h] [rbp+8h]
  unsigned int v27; // [rsp+150h] [rbp+18h] BYREF
  int v28; // [rsp+154h] [rbp+1Ch]

  v28 = HIDWORD(a3);
  v22 = -2;
  v5 = a2;
  v6 = g_pDisplay;
  v25 = g_pDisplay;
  v27 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CDisplay::CreateSurfaceFromBitmap", (int *)&v27);
  if ( v5 )
  {
    if ( !*((_QWORD *)v6 + 1) )
    {
      v7 = -2147418113;
      v27 = -2147418113;
LABEL_6:
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
      return v7;
    }
    *v5 = 0;
    ModuleHandleW = GetModuleHandleW(0);
    ImageW = (HBITMAP)Helpers::LoadImageW(ModuleHandleW, (HINSTANCE)0x1F5, 0, 0x17Du, 400, 0x2000, 0, v19);
    v20 = ImageW;
    if ( !ImageW )
    {
      ImageW = (HBITMAP)Helpers::LoadImageW(0, (HINSTANCE)0x1F5, 0, 0x17Du, 400, 8208, (unsigned int)&v27, v19);
      v20 = ImageW;
      v7 = v27;
      if ( (v27 & 0x80000000) != 0 )
        goto LABEL_6;
    }
    Helpers::GetObjectW(ImageW, (void *)0x20, (int)v23, 0, v18);
    memset(&v24, 0, sizeof(v24));
    v24.dwSize = 136;
    v24.dwFlags = 7;
    v24.ddsCaps.dwCaps = 64;
    v24.dwWidth = v23[1];
    v24.dwHeight = v23[2];
    try
    {
      v11 = (CSurface *)operator new(0x98u);
      if ( v11 )
        v13 = CSurface::CSurface(v11);
      else
        v13 = 0;
      *v5 = v13;
    }
    catch ( std::bad_alloc )
    {
      v16 = &v17;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LOWORD(v16) = 26;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v16, qword_401610);
      }
      v27 = -2147024882;
      v6 = v25;
      v5 = a2;
      ImageW = v20;
    }
    if ( (v27 & 0x80000000) != 0
      || (v27 = CSurface::Create(*v5, *((struct IDirectDraw7 **)v6 + 1), &v24), (v27 & 0x80000000) != 0)
      || (v27 = CSurface::DrawBitmap(*v5, ImageW, 0, 0, 0, 0), (v27 & 0x80000000) != 0) )
    {
      v14 = *v5;
      if ( *v5 )
      {
        CSurface::~CSurface(*v5);
        operator delete(v14);
        *v5 = 0;
      }
    }
    Helpers::DeleteObject(ImageW, 0, v12);
    v15 = v27;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
    return v15;
  }
  else
  {
    v27 = -2147024809;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
    return 2147942487LL;
  }
}
