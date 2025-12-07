// Hidden C++ exception states: #wind=1
__int64 __fastcall CSurface::Clear(CSurface *this)
{
  struct CSurface *v1; // rbx
  unsigned int v2; // ebx
  _BYTE v4[16]; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v5; // [rsp+40h] [rbp-98h]
  _DWORD v6[34]; // [rsp+50h] [rbp-88h] BYREF
  unsigned int v7; // [rsp+E0h] [rbp+8h] BYREF
  int v8; // [rsp+E4h] [rbp+Ch]

  v8 = HIDWORD(this);
  v5 = -2;
  v1 = g_pScoreManagerSurface;
  v7 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CSurface::Clear", (int *)&v7);
  if ( *(_QWORD *)v1 )
  {
    memset(v6, 0, 0x80u);
    v6[0] = 128;
    v6[26] = 0;
    v2 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, int, _DWORD *))(**(_QWORD **)v1 + 40LL))(
           *(_QWORD *)v1,
           0,
           0,
           0,
           1024,
           v6);
    v7 = v2;
  }
  else
  {
    v2 = -2147467261;
    v7 = -2147467261;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
