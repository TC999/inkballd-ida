// Hidden C++ exception states: #wind=1
void __fastcall CTileManager::DrawToSurface(CTileManager *this)
{
  struct CSurface *v2; // rbx
  __int64 v3; // rdi
  struct CSurface *v4; // rbx
  __int64 v5; // rbx
  unsigned int v6; // r13d
  struct CSurface *v7; // rbx
  __int64 v8; // rdi
  struct CSurface *v9; // rbx
  __int64 v10; // rbx
  unsigned int v11; // ebp
  unsigned int v12; // edi
  struct CSurface *v13; // rbx
  __int64 v14; // rsi
  struct CSurface *v15; // rbx
  __int64 v16; // rbx
  _BYTE v17[16]; // [rsp+38h] [rbp-60h] BYREF
  _BYTE v18[16]; // [rsp+48h] [rbp-50h] BYREF
  _BYTE v19[16]; // [rsp+58h] [rbp-40h] BYREF
  _BYTE v20[24]; // [rsp+68h] [rbp-30h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CTileManager::DrawToSurface", 0);
  v2 = g_pTileManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CSurface::GetDDrawSurface", 0);
  v3 = *(_QWORD *)v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  v4 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CSurface::GetDDrawSurface", 0);
  v5 = *(_QWORD *)v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD, __int64))(*(_QWORD *)v3 + 56LL))(
    v3,
    0,
    0,
    v5,
    &dword_4B9590,
    0,
    -2);
  v6 = *((_DWORD *)this + 10);
  if ( v6 <= 0x63 )
  {
    v11 = 14;
    do
    {
      v12 = v6 % 0xA;
      v6 /= 0xAu;
      v13 = g_pTileManagerSurface;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CSurface::GetDDrawSurface", 0);
      v14 = *(_QWORD *)v13;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CBitmapRects::GetBitmapRect", 0);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
      v15 = g_pGamePiecesSurface;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v19, "CSurface::GetDDrawSurface", 0);
      v16 = *(_QWORD *)v15;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v19);
      (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *, _DWORD))(*(_QWORD *)v14 + 56LL))(
        v14,
        v11,
        18,
        v16,
        &g_CBitmapRects[4 * (v12 + 134)],
        0);
      v11 -= 9;
    }
    while ( v6 );
  }
  else
  {
    v7 = g_pTileManagerSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CSurface::GetDDrawSurface", 0);
    v8 = *(_QWORD *)v7;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CBitmapRects::GetBitmapRect", 0);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
    v9 = g_pGamePiecesSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CSurface::GetDDrawSurface", 0);
    v10 = *(_QWORD *)v9;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
    (*(void (__fastcall **)(__int64, __int64, __int64, __int64, int *, _DWORD))(*(_QWORD *)v8 + 56LL))(
      v8,
      14,
      18,
      v10,
      &dword_4B97D0,
      0);
  }
  AddDisplayUpdateRect((struct tagRECT *)((char *)this + 24));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
}
