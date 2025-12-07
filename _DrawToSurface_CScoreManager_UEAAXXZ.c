// Hidden C++ exception states: #wind=1
void __fastcall CScoreManager::DrawToSurface(CScoreManager *this)
{
  struct CSurface *v2; // rbx
  __int64 v3; // rdi
  struct CSurface *v4; // rbx
  __int64 v5; // rbx
  unsigned int v6; // r12d
  unsigned int v7; // ebp
  struct CSurface *v8; // rbx
  __int64 v9; // rdi
  struct CSurface *v10; // rbx
  __int64 v11; // rbx
  unsigned int v12; // edi
  struct CSurface *v13; // rbx
  __int64 v14; // rsi
  struct CSurface *v15; // rbx
  __int64 v16; // rbx
  unsigned int v17; // ebp
  struct CSurface *v18; // rbx
  __int64 v19; // rdi
  struct CSurface *v20; // rbx
  __int64 v21; // rbx
  unsigned int v22; // ebp
  unsigned int v23; // r12d
  struct CSurface *v24; // rbx
  __int64 v25; // rdi
  struct CSurface *v26; // rbx
  __int64 v27; // rbx
  unsigned int v28; // edi
  struct CSurface *v29; // rbx
  __int64 v30; // rsi
  struct CSurface *v31; // rbx
  __int64 v32; // rbx
  struct CSurface *v33; // rbx
  __int64 v34; // rdi
  struct CSurface *v35; // rbx
  __int64 v36; // rbx
  _BYTE v37[16]; // [rsp+38h] [rbp-70h] BYREF
  _BYTE v38[16]; // [rsp+48h] [rbp-60h] BYREF
  _BYTE v39[16]; // [rsp+58h] [rbp-50h] BYREF
  _BYTE v40[24]; // [rsp+68h] [rbp-40h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v40, "CScoreManager::DrawToSurface", 0);
  v2 = g_pScoreManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CSurface::GetDDrawSurface", 0);
  v3 = *(_QWORD *)v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
  v4 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CSurface::GetDDrawSurface", 0);
  v5 = *(_QWORD *)v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD, __int64))(*(_QWORD *)v3 + 56LL))(
    v3,
    0,
    0,
    v5,
    &dword_4B9580,
    0,
    -2);
  v6 = *((_DWORD *)this + 10);
  v7 = *((_DWORD *)this + 4) - 12;
  v8 = g_pScoreManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CSurface::GetDDrawSurface", 0);
  v9 = *(_QWORD *)v8;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
  v10 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CSurface::GetDDrawSurface", 0);
  v11 = *(_QWORD *)v10;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
  (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *, _DWORD))(*(_QWORD *)v9 + 56LL))(
    v9,
    v7,
    13,
    v11,
    &dword_4B9720,
    0);
  do
  {
    v12 = v6 % 0xA;
    v6 /= 0xAu;
    v7 -= 9;
    v13 = g_pScoreManagerSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CSurface::GetDDrawSurface", 0);
    v14 = *(_QWORD *)v13;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CBitmapRects::GetBitmapRect", 0);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
    v15 = g_pGamePiecesSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
    v16 = *(_QWORD *)v15;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
    (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *))(*(_QWORD *)v14 + 56LL))(
      v14,
      v7,
      13,
      v16,
      &g_CBitmapRects[4 * (v12 + 123)]);
  }
  while ( v6 );
  v17 = v7 - 9;
  v18 = g_pScoreManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
  v19 = *(_QWORD *)v18;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  v20 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
  v21 = *(_QWORD *)v20;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *, _DWORD))(*(_QWORD *)v19 + 56LL))(
    v19,
    v17,
    13,
    v21,
    &dword_4B9670,
    0);
  v22 = v17 - 20;
  v23 = *((_DWORD *)this + 11);
  v24 = g_pScoreManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
  v25 = *(_QWORD *)v24;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  v26 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
  v27 = *(_QWORD *)v26;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *, _DWORD))(*(_QWORD *)v25 + 56LL))(
    v25,
    v22,
    13,
    v27,
    &dword_4B9660,
    0);
  do
  {
    v28 = v23 % 0xA;
    v23 /= 0xAu;
    v22 -= 9;
    v29 = g_pScoreManagerSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
    v30 = *(_QWORD *)v29;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CBitmapRects::GetBitmapRect", 0);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
    v31 = g_pGamePiecesSurface;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CSurface::GetDDrawSurface", 0);
    v32 = *(_QWORD *)v31;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
    (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *))(*(_QWORD *)v30 + 56LL))(
      v30,
      v22,
      13,
      v32,
      &g_CBitmapRects[4 * (v28 + 111)]);
  }
  while ( v23 );
  v33 = g_pScoreManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
  v34 = *(_QWORD *)v33;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  v35 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CSurface::GetDDrawSurface", 0);
  v36 = *(_QWORD *)v35;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
  (*(void (__fastcall **)(__int64, _QWORD, __int64, __int64, int *, _DWORD))(*(_QWORD *)v34 + 56LL))(
    v34,
    v22 - 9,
    13,
    v36,
    &dword_4B95B0,
    0);
  AddDisplayUpdateRect((struct tagRECT *)((char *)this + 24));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v40);
}
