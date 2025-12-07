// Hidden C++ exception states: #wind=1
void __fastcall CBallManager::DrawToSurface(CBallManager *this)
{
  struct CSurface *v2; // rbx
  __int64 v3; // rdi
  struct CSurface *v4; // rbx
  __int64 v5; // rbx
  __int64 i; // rsi
  CBoardObject *v7; // rcx
  int v8; // ebx
  int *v9; // rbx
  int v10; // ecx
  struct CSurface *v11; // rbx
  __int64 v12; // rdi
  struct CSurface *v13; // rbx
  __int64 v14; // rbx
  _DWORD v15[2]; // [rsp+38h] [rbp-70h] BYREF
  int v16; // [rsp+40h] [rbp-68h]
  int v17; // [rsp+44h] [rbp-64h]
  struct tagRECT v18; // [rsp+48h] [rbp-60h] BYREF
  _BYTE v19[16]; // [rsp+58h] [rbp-50h] BYREF
  _BYTE v20[16]; // [rsp+68h] [rbp-40h] BYREF
  _BYTE v21[16]; // [rsp+78h] [rbp-30h] BYREF
  _BYTE v22[24]; // [rsp+88h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v22, "CBallManager::DrawToSurface", 0);
  v2 = g_pBallManagerSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v18, "CSurface::GetDDrawSurface", 0);
  v3 = *(_QWORD *)v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v18);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v18, "CBitmapRects::GetBitmapRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v18);
  v4 = g_pGamePiecesSurface;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)&v18, "CSurface::GetDDrawSurface", 0);
  v5 = *(_QWORD *)v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)&v18);
  (*(void (__fastcall **)(__int64, char *, __int64, int *, _DWORD, _QWORD, __int64))(*(_QWORD *)v3 + 40LL))(
    v3,
    (char *)this + 24,
    v5,
    &dword_4B9570,
    0,
    0,
    -2);
  for ( i = 0; i < 6; ++i )
  {
    v7 = (CBoardObject *)*((_QWORD *)this + i + 8);
    if ( *((_DWORD *)v7 + 43) && (i || !*((_DWORD *)this + 14)) )
    {
      CBoardObject::GetBoundingRect(v7, &v18);
      v8 = *(_DWORD *)(*((_QWORD *)this + i + 8) + 48LL) + 12;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v19, "CBitmapRects::GetBitmapRect", 0);
      v9 = &g_CBitmapRects[4 * v8];
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v19);
      v15[0] = *v9;
      v15[1] = v9[1];
      v10 = v9[2];
      v16 = v10;
      v17 = v9[3];
      if ( v18.left < 104 )
      {
        if ( v18.right > 104 )
          v16 = 104 - v18.right + v10;
        v11 = g_pBallManagerSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CSurface::GetDDrawSurface", 0);
        v12 = *(_QWORD *)v11;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
        v13 = g_pGamePiecesSurface;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CSurface::GetDDrawSurface", 0);
        v14 = *(_QWORD *)v13;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
        (*(void (__fastcall **)(__int64, _QWORD, _QWORD, __int64, _DWORD *, _DWORD))(*(_QWORD *)v12 + 56LL))(
          v12,
          (unsigned int)(int)*(double *)(*((_QWORD *)this + i + 8) + 8LL),
          (unsigned int)(int)*(double *)(*((_QWORD *)this + i + 8) + 16LL),
          v14,
          v15,
          0);
      }
    }
  }
  AddDisplayUpdateRect((struct tagRECT *)((char *)this + 24));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v22);
}
