__int64 __fastcall fPrevSeen(int a1, struct BOARDHIST *a2, int a3)
{
  int v6; // r9d
  int v7; // edx
  unsigned int v8; // edi
  struct BOARDHIST *v9; // rax
  int v10; // eax
  int v11; // eax
  __int64 i; // rcx
  _BYTE v14[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "fPrevSeen", 0);
  v6 = *((_DWORD *)a2 + 10);
  v7 = 0;
  v8 = 1;
  if ( v6 <= 0 )
  {
LABEL_5:
    if ( (unsigned int)v6 < 0xA && v6 + 1 < a3 )
      *((_DWORD *)a2 + 10) = v6 + 1;
    v10 = *((_DWORD *)a2 + 10);
    if ( v10 > 1 )
    {
      v11 = v10 - 1;
      for ( i = v11; i > 0; --i )
        *((_DWORD *)a2 + i) = *((_DWORD *)a2 + i - 1);
    }
    *(_DWORD *)a2 = a1;
    v8 = 0;
  }
  else
  {
    v9 = a2;
    while ( a1 != *(_DWORD *)v9 )
    {
      ++v7;
      v9 = (struct BOARDHIST *)((char *)v9 + 4);
      if ( v7 >= v6 )
        goto LABEL_5;
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v8;
}
