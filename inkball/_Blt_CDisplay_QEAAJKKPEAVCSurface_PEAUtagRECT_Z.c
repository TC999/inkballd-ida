// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::Blt(
        CDisplay *this,
        unsigned int a2,
        unsigned int a3,
        struct CSurface *a4,
        struct tagRECT *a5)
{
  CDisplay *v8; // r12
  int v9; // eax
  int v10; // ebx
  struct IDirectDrawSurface7 *v11; // rbx
  unsigned int v12; // ebx
  struct IDirectDrawSurface7 *v13; // rbx
  _BYTE v15[16]; // [rsp+38h] [rbp-40h] BYREF
  _BYTE v16[24]; // [rsp+48h] [rbp-30h] BYREF
  int v17; // [rsp+98h] [rbp+20h] BYREF

  v8 = g_pDisplay;
  v17 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CDisplay::Blt", &v17);
  v9 = v17;
  if ( !a4 )
    v9 = -2147024809;
  v17 = v9;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CSurface::IsColorKeyed", 0);
  v10 = *((_DWORD *)a4 + 36);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CSurface::GetDDrawSurface", 0);
  if ( v10 )
  {
    v11 = *(struct IDirectDrawSurface7 **)a4;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    v12 = CDisplay::Blt(v8, a2, a3, v11, a5, 1u);
  }
  else
  {
    v13 = *(struct IDirectDrawSurface7 **)a4;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    v12 = CDisplay::Blt(v8, a2, a3, v13, a5, 0);
  }
  v17 = v12;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  return v12;
}
