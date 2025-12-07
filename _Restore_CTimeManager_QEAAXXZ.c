// Hidden C++ exception states: #wind=1
void __fastcall CTimeManager::Restore(CTimeManager *this)
{
  struct CSurface *v2; // rbx
  __int64 v3; // rbx
  struct CSurface *v4; // rbx
  __int64 v5; // rdi
  struct CSurface *v6; // rbx
  __int64 v7; // rbx
  unsigned int v8; // r13d
  unsigned int v9; // r14d
  unsigned int v10; // ebp
  struct CSurface *v11; // rbx
  __int64 v12; // rdi
  struct CSurface *v13; // rbx
  __int64 v14; // rbx
  __int64 v15; // r12
  unsigned int v16; // edi
  struct CSurface *v17; // rbx
  __int64 v18; // rdi
  struct CSurface *v19; // rbx
  __int64 v20; // rbx
  __int64 v21; // rsi
  struct CSurface *v22; // rbx
  __int64 v23; // rbx
  __int64 v24; // r12
  struct CSurface *v25; // rbx
  __int64 v26; // rdi
  struct CSurface *v27; // rbx
  __int64 v28; // rbx
  struct CSurface *v29; // rbx
  __int64 v30; // rdi
  struct CSurface *v31; // rbx
  __int64 v32; // rbx
  _BYTE v33[16]; // [rsp+38h] [rbp-A0h] BYREF
  _BYTE v34[16]; // [rsp+48h] [rbp-90h] BYREF
  _BYTE v35[16]; // [rsp+58h] [rbp-80h] BYREF
  _BYTE v36[16]; // [rsp+68h] [rbp-70h] BYREF
  _BYTE v37[16]; // [rsp+78h] [rbp-60h] BYREF
  _BYTE v38[16]; // [rsp+88h] [rbp-50h] BYREF
  _BYTE v39[24]; // [rsp+98h] [rbp-40h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CTimeManager::Restore", 0);
  v2 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
  v3 = *(_QWORD *)v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 216LL))(v3);
  v4 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
  v5 = *(_QWORD *)v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  v6 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
  v7 = *(_QWORD *)v6;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD, __int64))(*(_QWORD *)v5 + 56LL))(
    v5,
    0,
    0,
    v7,
    &dword_4B95A0,
    0,
    -2);
  v8 = *((_DWORD *)this + 10) / 0x3E8u;
  v9 = dwTopDrawLoc;
  v10 = *((_DWORD *)this + 4) - dwLeftDrawDif - 9;
  v11 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
  v12 = *(_QWORD *)v11;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  v13 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
  v14 = *(_QWORD *)v13;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v12 + 56LL))(
    v12,
    v10,
    v9,
    v14,
    &dword_4B98B0,
    0);
  if ( v8 > 0x3E7 )
  {
    v24 = 3;
    do
    {
      v10 -= 9;
      v25 = g_pTimeManagerSurface;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CSurface::GetDDrawSurface", 0);
      v26 = *(_QWORD *)v25;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CBitmapRects::GetBitmapRect", 0);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
      v27 = g_pGamePiecesSurface;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v36, "CSurface::GetDDrawSurface", 0);
      v28 = *(_QWORD *)v27;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v36);
      (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v26 + 56LL))(
        v26,
        v10,
        v9,
        v28,
        &dword_4B9890,
        0);
      --v24;
    }
    while ( v24 );
  }
  else
  {
    v15 = 3;
    do
    {
      v16 = v8 % 0xA;
      v8 /= 0xAu;
      v10 -= dwTimeDigitWidth;
      v17 = g_pTimeManagerSurface;
      if ( *((_DWORD *)this + 13) )
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v36, "CSurface::GetDDrawSurface", 0);
        v21 = *(_QWORD *)v17;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v36);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
        v22 = g_pGamePiecesSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CSurface::GetDDrawSurface", 0);
        v23 = *(_QWORD *)v22;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v21 + 56LL))(
          v21,
          v10,
          v9,
          v23,
          &g_CBitmapRects[4 * (v16 + 146)],
          0);
      }
      else
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
        v18 = *(_QWORD *)v17;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v34, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v34);
        v19 = g_pGamePiecesSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v35, "CSurface::GetDDrawSurface", 0);
        v20 = *(_QWORD *)v19;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v18 + 56LL))(
          v18,
          v10,
          v9,
          v20,
          &dword_4B98A0,
          0);
      }
      --v15;
    }
    while ( v15 );
  }
  v29 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CSurface::GetDDrawSurface", 0);
  v30 = *(_QWORD *)v29;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
  v31 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CSurface::GetDDrawSurface", 0);
  v32 = *(_QWORD *)v31;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v30 + 56LL))(
    v30,
    v10 - 9,
    v9,
    v32,
    &dword_4B97E0,
    0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
}
