// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::BltToBoard(
        CDisplay *this,
        unsigned int a2,
        unsigned int a3,
        struct CSurface *a4,
        struct tagRECT *a5)
{
  struct CSurface *v7; // rdi
  CDisplay *v8; // r12
  int v9; // eax
  int v10; // ebx
  __int64 v11; // rbx
  unsigned int v12; // ebx
  __int64 v13; // rbx
  _BYTE v15[16]; // [rsp+38h] [rbp-40h] BYREF
  _BYTE v16[24]; // [rsp+48h] [rbp-30h] BYREF
  int v17; // [rsp+98h] [rbp+20h] BYREF
  int v18; // [rsp+9Ch] [rbp+24h]

  v18 = HIDWORD(a4);
  v7 = g_pGamePiecesSurface;
  v8 = g_pDisplay;
  v17 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CDisplay::BltToBoard", &v17);
  v9 = v17;
  if ( !v7 )
    v9 = -2147024809;
  v17 = v9;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CSurface::IsColorKeyed", 0);
  v10 = *((_DWORD *)v7 + 36);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CSurface::GetDDrawSurface", 0);
  if ( v10 )
  {
    v11 = *(_QWORD *)v7;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    v12 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64, struct tagRECT *, int, __int64))(**((_QWORD **)v8 + 6) + 56LL))(
            *((_QWORD *)v8 + 6),
            a2,
            a3,
            v11,
            a5,
            1,
            -2);
  }
  else
  {
    v13 = *(_QWORD *)v7;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    v12 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD, __int64, struct tagRECT *, _DWORD, __int64))(**((_QWORD **)v8 + 6) + 56LL))(
            *((_QWORD *)v8 + 6),
            a2,
            a3,
            v13,
            a5,
            0,
            -2);
  }
  v17 = v12;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  return v12;
}
