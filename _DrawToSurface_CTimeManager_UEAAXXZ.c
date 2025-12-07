// Hidden C++ exception states: #wind=1
void __fastcall CTimeManager::DrawToSurface(CTimeManager *this)
{
  unsigned int v2; // r13d
  unsigned int v3; // esi
  unsigned int v4; // r12d
  struct CSurface *v5; // rbx
  __int64 v6; // rdi
  struct CSurface *v7; // rbx
  __int64 v8; // rbx
  _DWORD *v9; // rbp
  unsigned int v10; // eax
  struct CSurface *v11; // rbx
  __int64 v12; // rdi
  struct CSurface *v13; // rbx
  __int64 v14; // rbx
  struct CSurface *v15; // rbx
  __int64 v16; // rdi
  int *v17; // rsi
  struct CSurface *v18; // rbx
  __int64 v19; // rbx
  _DWORD *v20; // rbp
  struct CSurface *v21; // rbx
  __int64 v22; // rdi
  struct CSurface *v23; // rbx
  __int64 v24; // rbx
  struct CSurface *v25; // rbx
  __int64 v26; // rdi
  struct CSurface *v27; // rbx
  __int64 v28; // rbx
  struct tagRECT v29; // [rsp+30h] [rbp-148h] BYREF
  _BYTE v30[16]; // [rsp+40h] [rbp-138h] BYREF
  _BYTE v31[16]; // [rsp+50h] [rbp-128h] BYREF
  _BYTE v32[16]; // [rsp+60h] [rbp-118h] BYREF
  _BYTE v33[16]; // [rsp+70h] [rbp-108h] BYREF
  _BYTE v34[16]; // [rsp+80h] [rbp-F8h] BYREF
  _BYTE v35[16]; // [rsp+90h] [rbp-E8h] BYREF
  _BYTE v36[16]; // [rsp+A0h] [rbp-D8h] BYREF
  _BYTE v37[16]; // [rsp+B0h] [rbp-C8h] BYREF
  _BYTE v38[16]; // [rsp+C0h] [rbp-B8h] BYREF
  _BYTE v39[16]; // [rsp+D0h] [rbp-A8h] BYREF
  _BYTE v40[16]; // [rsp+E0h] [rbp-98h] BYREF
  _BYTE v41[16]; // [rsp+F0h] [rbp-88h] BYREF
  _BYTE v42[16]; // [rsp+100h] [rbp-78h] BYREF
  __int64 v43; // [rsp+110h] [rbp-68h]
  _BYTE v44[16]; // [rsp+118h] [rbp-60h] BYREF
  _BYTE v45[80]; // [rsp+128h] [rbp-50h] BYREF
  unsigned int v46; // [rsp+180h] [rbp+8h]
  unsigned int v47; // [rsp+188h] [rbp+10h]

  v43 = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "CTimeManager::DrawToSurface", 0);
  v2 = *((_DWORD *)this + 10) / 0x3E8u;
  v3 = dwTopDrawLoc;
  v46 = dwTopDrawLoc;
  v4 = *((_DWORD *)this + 4) - dwLeftDrawDif - 9;
  v5 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v29, "CSurface::GetDDrawSurface", 0);
  v6 = *(_QWORD *)v5;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v29);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v29, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v29);
  v7 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v29, "CSurface::GetDDrawSurface", 0);
  v8 = *(_QWORD *)v7;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v29);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v6 + 56LL))(
    v6,
    v4,
    v3,
    v8,
    &dword_4B98B0,
    0);
  if ( v2 > 0x3E7 )
  {
    v20 = &unk_4DA718;
    do
    {
      v4 -= 9;
      if ( *v20 != 156 )
      {
        v21 = g_pTimeManagerSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CSurface::GetDDrawSurface", 0);
        v22 = *(_QWORD *)v21;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v36, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v36);
        v23 = g_pGamePiecesSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v34, "CSurface::GetDDrawSurface", 0);
        v24 = *(_QWORD *)v23;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v34);
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v22 + 56LL))(
          v22,
          v4,
          v3,
          v24,
          &dword_4B9890,
          0);
        *v20 = 156;
        v29.left = v4 + *((_DWORD *)this + 2);
        LODWORD(v24) = v29.left;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v32, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v32);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v35, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
        v29.right = v24 + dword_4B9898 - dword_4B9890;
        v29.top = v3 + *((_DWORD *)this + 3);
        LODWORD(v24) = v29.top;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v31, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v31);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
        v29.bottom = v24 + dword_4B989C - dword_4B9894;
        AddDisplayUpdateRect(&v29);
      }
      ++v20;
    }
    while ( (__int64)v20 < (__int64)&dword_4DA724 );
  }
  else
  {
    v9 = &unk_4DA718;
    do
    {
      v10 = v2 % 0xA;
      v47 = v2 % 0xA;
      v2 /= 0xAu;
      v4 -= dwTimeDigitWidth;
      if ( *((_DWORD *)this + 13) )
      {
        if ( *v9 != v10 + 146 )
        {
          v15 = g_pTimeManagerSurface;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "CSurface::GetDDrawSurface", 0);
          v16 = *(_QWORD *)v15;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v31, "CBitmapRects::GetBitmapRect", 0);
          v17 = &g_CBitmapRects[4 * (v47 + 146)];
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v31);
          v18 = g_pGamePiecesSurface;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v35, "CSurface::GetDDrawSurface", 0);
          v19 = *(_QWORD *)v18;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
          (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v16 + 56LL))(
            v16,
            v4,
            v46,
            v19,
            v17,
            0);
          *v9 = v47 + 146;
          v29.left = v4 + *((_DWORD *)this + 2);
          LODWORD(v19) = v29.left;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v32, "CBitmapRects::GetBitmapRect", 0);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v32);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v34, "CBitmapRects::GetBitmapRect", 0);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v34);
          v29.right = v19 + v17[2] - *v17;
          v29.top = *((_DWORD *)this + 3) + v46;
          LODWORD(v19) = v29.top;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v36, "CBitmapRects::GetBitmapRect", 0);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v36);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CBitmapRects::GetBitmapRect", 0);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
          v29.bottom = v19 + v17[3] - v17[1];
          AddDisplayUpdateRect(&v29);
          v3 = v46;
        }
      }
      else if ( *v9 != 157 )
      {
        v11 = g_pTimeManagerSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v42, "CSurface::GetDDrawSurface", 0);
        v12 = *(_QWORD *)v11;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v42);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v40, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v40);
        v13 = g_pGamePiecesSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v44, "CSurface::GetDDrawSurface", 0);
        v14 = *(_QWORD *)v13;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v44);
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v12 + 56LL))(
          v12,
          v4,
          v3,
          v14,
          &dword_4B98A0,
          0);
        *v9 = 157;
        v29.left = v4 + *((_DWORD *)this + 2);
        LODWORD(v14) = v29.left;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v39, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v39);
        v29.right = v14 + dword_4B98A8 - dword_4B98A0;
        v29.top = v3 + *((_DWORD *)this + 3);
        LODWORD(v14) = v29.top;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v41, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v41);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v37, "CBitmapRects::GetBitmapRect", 0);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v37);
        v29.bottom = v14 + dword_4B98AC - dword_4B98A4;
        AddDisplayUpdateRect(&v29);
      }
      ++v9;
    }
    while ( (__int64)v9 < (__int64)&dword_4DA724 );
  }
  v25 = g_pTimeManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CSurface::GetDDrawSurface", 0);
  v26 = *(_QWORD *)v25;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
  v27 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CSurface::GetDDrawSurface", 0);
  v28 = *(_QWORD *)v27;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
  (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, int *, _DWORD))(*(_QWORD *)v26 + 56LL))(
    v26,
    v4 - 9,
    v3,
    v28,
    &dword_4B97E0,
    0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
}
