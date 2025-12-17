__int64 __fastcall CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetSize(int a1)
{
  unsigned int v2; // ebx
  unsigned __int64 v3; // rsi
  char *v4; // rax
  char *v5; // rbp
  int v6; // r12d
  _DWORD *v7; // r11
  int v8; // ebp
  _QWORD *v9; // rsi
  unsigned __int64 v10; // rcx
  int v11; // ecx
  int v12; // ebp
  char *v13; // rax
  char *v14; // r13
  int v15; // r12d
  unsigned __int64 v16; // rcx
  char *v17; // rsi

  v2 = 0;
  if ( !a1 )
  {
    if ( g_arrTCI )
    {
      operator delete[](g_arrTCI);
      g_arrTCI = 0;
    }
    dword_4B9EDC = 0;
    dword_4B9ED8 = 0;
    return v2;
  }
  if ( !g_arrTCI )
  {
    v3 = 32LL * a1;
    v4 = (char *)operator new[](v3);
    v5 = v4;
    if ( v4 )
    {
      g_arrTCI = v4;
      v6 = a1;
      if ( v3 < 0xFFFFFFFF )
      {
        memset(v4, 0, (unsigned int)v3);
        v7 = v5 + 16;
        do
        {
          --v6;
          if ( v7 != (_DWORD *)16 )
          {
            *((_QWORD *)v7 - 2) = 0;
            *((_QWORD *)v7 - 1) = 0;
            *v7 = 0;
            v7[1] = 0;
            v7[2] = 0;
            v7[3] = 0;
          }
          v7 += 8;
        }
        while ( v6 );
      }
      dword_4B9EDC = a1;
LABEL_21:
      dword_4B9ED8 = a1;
      return v2;
    }
    return (unsigned int)-2147024882;
  }
  if ( a1 <= dword_4B9EDC )
  {
    if ( a1 > dword_4B9ED8 )
    {
      v8 = a1 - dword_4B9ED8;
      v9 = (char *)g_arrTCI + 32 * dword_4B9ED8;
      v10 = 32LL * (a1 - dword_4B9ED8);
      if ( v10 < 0xFFFFFFFF )
      {
        memset(v9, 0, (unsigned int)v10);
        while ( v8 )
        {
          --v8;
          if ( v9 )
          {
            *v9 = 0;
            v9[1] = 0;
            *((_DWORD *)v9 + 4) = 0;
            *((_DWORD *)v9 + 5) = 0;
            *((_DWORD *)v9 + 6) = 0;
            *((_DWORD *)v9 + 7) = 0;
          }
          v9 += 4;
        }
      }
    }
    goto LABEL_21;
  }
  v11 = dword_4B9EE0;
  if ( !dword_4B9EE0 )
  {
    v11 = dword_4B9ED8 / 8;
    if ( dword_4B9ED8 / 8 > 1024 )
      v11 = 1024;
    if ( dword_4B9ED8 / 8 < 4 )
      v11 = 4;
  }
  v12 = a1;
  if ( a1 < dword_4B9EDC + v11 )
    v12 = dword_4B9EDC + v11;
  if ( v12 < dword_4B9ED8 )
    return (unsigned int)-2147024882;
  v13 = (char *)operator new[](32LL * v12);
  v14 = v13;
  if ( !v13 )
    return (unsigned int)-2147024882;
  memcpy(v13, g_arrTCI, 32LL * dword_4B9ED8);
  v15 = a1 - dword_4B9ED8;
  v16 = 32LL * (a1 - dword_4B9ED8);
  v17 = &v14[32 * dword_4B9ED8];
  if ( v16 < 0xFFFFFFFF )
  {
    memset(&v14[32 * dword_4B9ED8], 0, (unsigned int)v16);
    while ( v15 )
    {
      --v15;
      if ( v17 )
      {
        *(_QWORD *)v17 = 0;
        *((_QWORD *)v17 + 1) = 0;
        *((_DWORD *)v17 + 4) = 0;
        *((_DWORD *)v17 + 5) = 0;
        *((_DWORD *)v17 + 6) = 0;
        *((_DWORD *)v17 + 7) = 0;
      }
      v17 += 32;
    }
  }
  operator delete[](g_arrTCI);
  g_arrTCI = v14;
  dword_4B9ED8 = a1;
  dword_4B9EDC = v12;
  return v2;
}
