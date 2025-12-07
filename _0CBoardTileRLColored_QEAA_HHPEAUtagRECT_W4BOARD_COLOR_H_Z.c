__int64 __fastcall CBoardTileRLColored::CBoardTileRLColored(__int64 a1, int a2, int a3, __int64 a4, int a5, int a6)
{
  CGameBoard *v10; // rbx
  __int64 v11; // rax
  _BYTE v13[16]; // [rsp+20h] [rbp-38h] BYREF
  _BYTE v14[16]; // [rsp+30h] [rbp-28h] BYREF
  _BYTE v15[24]; // [rsp+40h] [rbp-18h] BYREF

  CBoardTile::CBoardTile((CBoardTile *)a1);
  *(_QWORD *)a1 = &CBoardTileRLColored::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CBoardTileRLColored::CBoardTileRLColored", 0);
  *(_DWORD *)(a1 + 48) = a5;
  *(_DWORD *)(a1 + 80) = a6;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 76) = 7;
  *(_DWORD *)(a1 + 84) = a2;
  *(_DWORD *)(a1 + 88) = a3;
  *(_QWORD *)(a1 + 32) = a4;
  *(_DWORD *)(a1 + 100) = a6 != 0 ? 2 : 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "AddGameObjectToUpdateList", 0);
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, (struct CGameObject *)a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "AddRLColoredWallToList", 0);
  v10 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CGameBoard::AddRLColoredWallToList", 0);
  v11 = *((int *)v10 + 732);
  if ( (int)v11 < 289 )
  {
    *((_QWORD *)v10 + v11 + 367) = a1;
    ++*((_DWORD *)v10 + 732);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
  return a1;
}
