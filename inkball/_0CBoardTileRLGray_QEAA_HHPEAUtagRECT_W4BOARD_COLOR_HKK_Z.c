__int64 __fastcall CBoardTileRLGray::CBoardTileRLGray(
        __int64 a1,
        int a2,
        int a3,
        __int64 a4,
        __int64 a5,
        int a6,
        int a7,
        int a8)
{
  _BYTE v13[16]; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v14[24]; // [rsp+30h] [rbp-18h] BYREF

  CBoardTile::CBoardTile((CBoardTile *)a1);
  *(_QWORD *)a1 = &CBoardTileRLGray::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CBoardTileRLGray::CBoardTileRLGray", 0);
  *(_DWORD *)(a1 + 108) = a7;
  *(_DWORD *)(a1 + 112) = a8;
  *(_DWORD *)(a1 + 48) = 0;
  *(_DWORD *)(a1 + 80) = a6;
  *(_DWORD *)(a1 + 72) = 0;
  *(_DWORD *)(a1 + 96) = 0;
  *(_DWORD *)(a1 + 100) = 0;
  *(_DWORD *)(a1 + 76) = 7;
  *(_DWORD *)(a1 + 84) = a2;
  *(_DWORD *)(a1 + 104) = a6 != 0 ? 2 : 0;
  *(_DWORD *)(a1 + 88) = a3;
  *(_QWORD *)(a1 + 32) = a4;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "AddGameObjectToUpdateList", 0);
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, (struct CGameObject *)a1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return a1;
}
