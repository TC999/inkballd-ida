// Hidden C++ exception states: #wind=1
__int64 __fastcall CSurface::SetColorKey(CSurface *this)
{
  struct CSurface *v1; // rbx
  unsigned int v2; // ebx
  _BYTE v4[32]; // [rsp+28h] [rbp-20h] BYREF
  unsigned int v5; // [rsp+50h] [rbp+8h] BYREF
  int v6; // [rsp+54h] [rbp+Ch]
  unsigned int v7; // [rsp+60h] [rbp+18h] BYREF
  unsigned int v8; // [rsp+64h] [rbp+1Ch]

  v6 = HIDWORD(this);
  v1 = g_pGamePiecesSurface;
  v5 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CSurface::SetColorKey", (int *)&v5);
  if ( *(_QWORD *)v1 )
  {
    *((_DWORD *)v1 + 36) = 1;
    v7 = CSurface::ConvertGDIColor(v1, 0xFF00FFu);
    v8 = CSurface::ConvertGDIColor(v1, 0xFF00FFu);
    v2 = (*(__int64 (__fastcall **)(_QWORD, __int64, unsigned int *))(**(_QWORD **)v1 + 232LL))(*(_QWORD *)v1, 8, &v7);
    v5 = v2;
  }
  else
  {
    v2 = -2147467261;
    v5 = -2147467261;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
