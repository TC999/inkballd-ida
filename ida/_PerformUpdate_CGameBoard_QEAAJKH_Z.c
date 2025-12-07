// Hidden C++ exception states: #wind=1
__int64 __fastcall CGameBoard::PerformUpdate(CGameBoard *this, unsigned int a2, int a3)
{
  CGameBoard *v5; // rdi
  int v6; // ebp
  _QWORD *v7; // rbx
  int v8; // r12d
  __int64 *v9; // rbp
  __int64 v10; // rbx
  __int64 v11; // xmm5_8
  __int64 v12; // xmm0_8
  unsigned int v13; // ebx
  int v14; // r12d
  _QWORD *v15; // rbp
  __int64 v16; // rbx
  CDisplay *v17; // rbx
  __int64 v18; // rbx
  int v19; // eax
  unsigned int NewSurfaces; // ebx
  int v21; // eax
  _BYTE v23[16]; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v24[24]; // [rsp+38h] [rbp-30h] BYREF
  unsigned int v25; // [rsp+78h] [rbp+10h] BYREF

  v5 = g_pCGameBoard;
  v25 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v24, "CGameBoard::PerformUpdate", (int *)&v25);
  if ( dword_464AD8 )
  {
    (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v5 + 1889) + 8LL))(*((_QWORD *)v5 + 1889));
    (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v5 + 1890) + 8LL))(*((_QWORD *)v5 + 1890));
    (*(void (__fastcall **)(_QWORD))(**((_QWORD **)v5 + 1891) + 8LL))(*((_QWORD *)v5 + 1891));
    dword_464AD8 = 0;
  }
  v6 = 0;
  if ( *(int *)v5 > 0 )
  {
    v7 = (_QWORD *)((char *)v5 + 8);
    do
    {
      (**(void (__fastcall ***)(_QWORD, _QWORD))*v7)(*v7, a2);
      ++v6;
      ++v7;
    }
    while ( v6 < *(_DWORD *)v5 );
  }
  v8 = 0;
  if ( *((int *)v5 + 602) > 0 )
  {
    v9 = (__int64 *)((char *)v5 + 2416);
    do
    {
      v10 = *v9;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v23, "CMovingObject::PrepareToMove", 0);
      v11 = *(_QWORD *)(v10 + 8);
      *(_QWORD *)(v10 + 88) = v11;
      v12 = *(_QWORD *)(v10 + 16);
      *(_QWORD *)(v10 + 96) = v12;
      *(_DWORD *)(v10 + 120) = *(_DWORD *)(v10 + 24);
      *(_DWORD *)(v10 + 124) = *(_DWORD *)(v10 + 28);
      *(_QWORD *)(v10 + 104) = v11;
      *(_QWORD *)(v10 + 112) = v12;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v23);
      ++v8;
      ++v9;
    }
    while ( v8 < *((_DWORD *)v5 + 602) );
  }
  while ( a2 )
  {
    v13 = a2;
    if ( a2 > 4 )
      v13 = 4;
    v14 = 0;
    if ( *((int *)v5 + 602) > 0 )
    {
      v15 = (_QWORD *)((char *)v5 + 2416);
      do
      {
        (**(void (__fastcall ***)(_QWORD, _QWORD))*v15)(*v15, v13);
        ++v14;
        ++v15;
      }
      while ( v14 < *((_DWORD *)v5 + 602) );
    }
    if ( a2 <= 4 )
      a2 = 0;
    else
      a2 -= 4;
  }
  v16 = *((_QWORD *)v5 + 1889);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v23, "CScoreManager::GetScore", 0);
  LODWORD(v16) = *(_DWORD *)(v16 + 44);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v23);
  CTileManager::SetTiles(*((CTileManager **)v5 + 1890), v16);
  v17 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v23, "CDisplay::GetDirectDraw", 0);
  v18 = *((_QWORD *)v17 + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v23);
  v19 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v18 + 208LL))(v18);
  NewSurfaces = v19;
  v25 = v19;
  if ( v19 >= 0 )
  {
    v21 = CGameBoard::DisplayFrame(v5, a3, 0);
    v25 = v21;
    if ( v21 < 0 )
    {
      if ( v21 != -2005532222 )
      {
        NewSurfaces = v21;
        goto LABEL_30;
      }
      CGameBoard::RestoreSurfaces(v5);
      CGameBoard::DisplayFrame(v5, 1, 1);
    }
    *((_DWORD *)v5 + 2028) = 0;
    *((_DWORD *)v5 + 3185) = 0;
    v25 = 0;
    NewSurfaces = 0;
    goto LABEL_30;
  }
  if ( v19 == -2005532091 )
  {
    Sleep(0xAu);
    NewSurfaces = 0;
    v25 = 0;
  }
  else if ( v19 == -2005532085 )
  {
    NewSurfaces = CGameBoard::CreateNewSurfaces(v5);
    v25 = NewSurfaces;
  }
LABEL_30:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v24);
  return NewSurfaces;
}
