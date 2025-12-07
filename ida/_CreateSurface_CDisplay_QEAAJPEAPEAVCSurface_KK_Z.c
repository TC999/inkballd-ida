// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::CreateSurface(CDisplay *this, struct CSurface **a2, DWORD a3, DWORD a4)
{
  struct CSurface **v6; // rdi
  CDisplay *v7; // rsi
  int v8; // ebx
  CSurface *v9; // rax
  CSurface *v10; // rax
  CSurface *v11; // rsi
  __int64 *v13; // rdx
  __int64 v14; // [rsp+0h] [rbp-E8h] BYREF
  int v15; // [rsp+20h] [rbp-C8h] BYREF
  __int64 v16; // [rsp+28h] [rbp-C0h]
  _BYTE v17[16]; // [rsp+30h] [rbp-B8h] BYREF
  _DDSURFACEDESC2 v18; // [rsp+40h] [rbp-A8h] BYREF
  CDisplay *v19; // [rsp+F0h] [rbp+8h]

  v16 = -2;
  v6 = a2;
  v7 = g_pDisplay;
  v19 = g_pDisplay;
  v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CDisplay::CreateSurface", &v15);
  if ( v6 )
  {
    if ( *((_QWORD *)v7 + 1) )
    {
      memset(&v18, 0, sizeof(v18));
      v18.dwSize = 136;
      v18.dwFlags = 7;
      v18.ddsCaps.dwCaps = 64;
      v18.dwWidth = a3;
      v18.dwHeight = a4;
      if ( (unsigned int)fPortraitMode() )
        v18.ddsCaps.dwCaps |= 0x800u;
      try
      {
        v9 = (CSurface *)operator new(0x98u);
        if ( v9 )
          v10 = CSurface::CSurface(v9);
        else
          v10 = 0;
        *v6 = v10;
      }
      catch ( std::bad_alloc )
      {
        v13 = &v14;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v13) = 25;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v13, qword_401610);
        }
        v15 = -2147024882;
        v7 = v19;
        v6 = a2;
      }
      v8 = v15;
      if ( v15 >= 0 )
      {
        v8 = CSurface::Create(*v6, *((struct IDirectDraw7 **)v7 + 1), &v18);
        v15 = v8;
        if ( v8 < 0 )
        {
          v11 = *v6;
          if ( *v6 )
          {
            CSurface::~CSurface(*v6);
            operator delete(v11);
            *v6 = 0;
            v8 = v15;
          }
        }
      }
    }
    else
    {
      v8 = -2147418113;
      v15 = -2147418113;
    }
  }
  else
  {
    v8 = -2147024809;
    v15 = -2147024809;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  return (unsigned int)v8;
}
