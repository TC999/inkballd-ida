void __fastcall ToggleRLWalls(int a1)
{
  CGameBoard *v2; // rsi
  int v3; // edi
  char *v4; // rbx
  __int64 v5; // rbp
  _BYTE v6[16]; // [rsp+20h] [rbp-38h] BYREF
  _BYTE v7[16]; // [rsp+30h] [rbp-28h] BYREF
  _BYTE v8[24]; // [rsp+40h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "ToggleRLWalls", 0);
  v2 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CGameBoard::ToggleRLWalls", 0);
  v3 = 0;
  if ( *((int *)v2 + 732) > 0 )
  {
    v4 = (char *)v2 + 2936;
    do
    {
      v5 = *(_QWORD *)v4;
      if ( *(_DWORD *)(*(_QWORD *)v4 + 48LL) == a1 )
      {
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBoardTileRLColored::ToggleState", 0);
        *(_DWORD *)(v5 + 100) = *(_DWORD *)(v5 + 100) == 0;
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
      }
      ++v3;
      v4 += 8;
    }
    while ( v3 < *((_DWORD *)v2 + 732) );
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
