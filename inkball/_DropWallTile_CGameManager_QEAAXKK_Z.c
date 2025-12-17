// Hidden C++ exception states: #wind=2
void __fastcall CGameManager::DropWallTile(CGameManager *this, unsigned int a2, unsigned int a3)
{
  struct CBoardTile *Tile; // rax
  struct CBoardTile *v6; // r13
  _DWORD *v7; // rbx
  int v8; // eax
  CBoardTile *v9; // r12
  int *BitmapRect; // rsi
  int v11; // edi
  int v12; // ebx
  _QWORD *v13; // rdx
  _QWORD v14[5]; // [rsp+0h] [rbp-58h] BYREF
  _BYTE v15[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v16[32]; // [rsp+38h] [rbp-20h] BYREF

  v14[4] = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CGameManager::DropWallTile", 0);
  if ( a2 > *((_DWORD *)g_pCGameBoard + 3766)
    && a2 < *((_DWORD *)g_pCGameBoard + 3764)
    && a3 > *((_DWORD *)g_pCGameBoard + 3767)
    && a3 < *((_DWORD *)g_pCGameBoard + 3765) )
  {
    Tile = CGameBoard::GetTile(g_pCGameBoard, a2, a3);
    v6 = Tile;
    if ( !*((_DWORD *)Tile + 19) && !(unsigned int)CGameBoard::BallOnTile(g_pCGameBoard, Tile) )
    {
      v7 = (_DWORD *)*((_QWORD *)g_pCGameBoard + 1890);
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CTileManager::GetTileCount", 0);
      v8 = v7[10];
      if ( v8 )
      {
        v7[10] = v8 - 1;
        (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v7 + 8LL))(v7);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
        try
        {
          v9 = (CBoardTile *)operator new(0x60u);
          if ( v9 )
          {
            BitmapRect = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, 37);
            v11 = *((_DWORD *)v6 + 22);
            v12 = *((_DWORD *)v6 + 21);
            CBoardTile::CBoardTile(v9);
            *(_QWORD *)v9 = &CBoardTileWall::`vftable';
            Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CBoardTileWall::CBoardTileWall", 0);
            *((_DWORD *)v9 + 19) = 6;
            *((_DWORD *)v9 + 21) = v12;
            *((_DWORD *)v9 + 22) = v11;
            *((_DWORD *)v9 + 20) = 4;
            *((_QWORD *)v9 + 4) = BitmapRect;
            *((_DWORD *)v9 + 12) = 0;
            *((_DWORD *)v9 + 18) = 0;
            Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
          }
          else
          {
            v9 = 0;
          }
        }
        catch ( std::bad_alloc )
        {
          v13 = v14;
          if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            LOWORD(v13) = 23;
            WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v13, qword_401918);
          }
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
          return;
        }
        *((_DWORD *)v9 + 6) = *((_DWORD *)v6 + 6);
        *((_DWORD *)v9 + 7) = *((_DWORD *)v6 + 7);
        *((_QWORD *)v9 + 1) = *((_QWORD *)v6 + 1);
        *((_QWORD *)v9 + 2) = *((_QWORD *)v6 + 2);
        CGameBoard::SetTile(g_pCGameBoard, v9);
        CGameBoard::ShadowizeTile(g_pCGameBoard, v9);
      }
      else
      {
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
      }
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
}
