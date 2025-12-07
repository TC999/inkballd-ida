void __fastcall CGameBoard::RandomizeBallOrder(CGameBoard *this)
{
  CGameBoard *v1; // rsi
  int v2; // ebx
  int v3; // edi
  int v4; // r12d
  __int64 *v5; // rbp
  __int64 v6; // rbx
  __int64 v7; // r11
  __int64 *v8; // rcx
  __int64 v9; // rax
  _BYTE v10[16]; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v11[24]; // [rsp+30h] [rbp-18h] BYREF

  v1 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CGameBoard::RandomizeBallOrder", 0);
  v2 = *((_DWORD *)v1 + 1312);
  v3 = 0;
  v4 = 0;
  if ( v2 > 0 )
  {
    v5 = (__int64 *)((char *)v1 + 5256);
    do
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::GetRandomNumber", 0);
      v6 = rand() % v2;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
      v7 = *v5;
      *v5 = *((_QWORD *)v1 + v6 + 657);
      ++v4;
      *((_QWORD *)v1 + v6 + 657) = v7;
      v2 = *((_DWORD *)v1 + 1312);
      ++v5;
    }
    while ( v4 < v2 );
  }
  if ( *((int *)v1 + 1312) > 0 )
  {
    v8 = (__int64 *)((char *)v1 + 5256);
    do
    {
      v9 = *v8++;
      *(_DWORD *)(v9 + 180) = v3++;
    }
    while ( v3 < *((_DWORD *)v1 + 1312) );
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
}
