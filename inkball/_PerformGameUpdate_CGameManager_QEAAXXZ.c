// Hidden C++ exception states: #wind=1
void __fastcall CGameManager::PerformGameUpdate(CGameManager *this)
{
  CGameManager *v1; // r12
  DWORD Time; // r14d
  unsigned int v3; // ecx
  __int64 v4; // rbx
  unsigned int v5; // ebx
  __int64 v6; // rbx
  __int64 v7; // rbx
  __int64 v8; // rbx
  __int64 v9; // rbx
  __int64 v10; // rbx
  CGameBoard *v11; // rdi
  CBoardObject *v12; // rbx
  CGameBoard *v13; // rbp
  int v14; // esi
  CBoardObject *v15; // rbx
  unsigned int v16; // eax
  struct tagRECT *v17; // rax
  unsigned int v18; // eax
  struct tagRECT *v19; // rax
  __int64 v20; // rdi
  CGameBoard *v21; // rbp
  int v22; // esi
  CBoardObject *v23; // rbx
  CGameBoard *v24; // rdi
  CBoardObject *v25; // rbx
  unsigned int GoldVersionOfTile; // eax
  struct tagRECT *BitmapRect; // rax
  unsigned int v28; // eax
  struct tagRECT *v29; // rax
  _BYTE v30[24]; // [rsp+38h] [rbp-40h] BYREF
  CGameManager *v31; // [rsp+80h] [rbp+8h] BYREF

  v31 = this;
  v1 = g_pCGameManager;
  if ( *((_DWORD *)g_pCGameManager + 1) )
  {
    Time = timeGetTime();
    v3 = (Time - *(_DWORD *)v1) % 0x42;
    if ( v3 )
    {
      if ( *((_DWORD *)v1 + 4) )
      {
        if ( *((_DWORD *)v1 + 4) == 2 )
        {
          dword_4DA6F8 += v3;
          if ( (unsigned int)dword_4DA6F8 > 0x14 )
          {
            v4 = *((_QWORD *)g_pCGameBoard + 1891);
            Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CTimeManager::GetTime", 0);
            v5 = *(_DWORD *)(v4 + 40);
            Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
            if ( !v5 || v5 == -1 )
            {
              qword_4DA700 = 0;
              qword_4DA708 = 0;
              dword_4DA710 = 0;
              dword_4DA714 = 0;
              ++*((_DWORD *)v1 + 3);
              Sleep(0x5DCu);
              *(_DWORD *)v1 = timeGetTime();
              Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "LoadNextLevel", 0);
              if ( *((_DWORD *)g_pCGameManager + 3) == 5 * (*((_DWORD *)g_pCGameManager + 3) / 5) )
                CBoardManager::LoadRandomBonusBoardFromResources(
                  (CBoardManager *)&g_CBoardManager,
                  &byte_4DA740,
                  (int *)&v31);
              else
                CBoardManager::LoadRandomBoardFromResources(
                  (CBoardManager *)&g_CBoardManager,
                  &byte_4DA740,
                  (int *)&v31);
              CGameManager::LoadBoard(g_pCGameManager, &byte_4DA740, (int)v31);
              Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
              *((_DWORD *)v1 + 4) = 0;
            }
            else
            {
              if ( v5 <= 0x3E8 )
                CTimeManager::SetTime(*((CTimeManager **)g_pCGameBoard + 1891), 0);
              else
                CTimeManager::SetTime(*((CTimeManager **)g_pCGameBoard + 1891), v5 - 1000);
              CDisplay::Blt(
                g_pDisplay,
                *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1891) + 8LL),
                *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1891) + 12LL),
                g_pTimeManagerSurface,
                0);
              v6 = *((_QWORD *)g_pCGameBoard + 1891);
              Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CUIBarObject::GetBoundingRect", 0);
              stru_4DA728 = *(struct tagRECT *)(v6 + 24);
              Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
              if ( CDisplay::Present(g_pDisplay, &stru_4DA728) == -2005532222 )
                CGameBoard::RestoreSurfaces(g_pCGameBoard);
              CScoreManager::IncrementScore(*((CScoreManager **)g_pCGameBoard + 1889), 1);
              CDisplay::Blt(
                g_pDisplay,
                *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1889) + 8LL),
                *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1889) + 12LL),
                g_pScoreManagerSurface,
                0);
              v7 = *((_QWORD *)g_pCGameBoard + 1889);
              Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CUIBarObject::GetBoundingRect", 0);
              stru_4DA728 = *(struct tagRECT *)(v7 + 24);
              Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
              if ( CDisplay::Present(g_pDisplay, &stru_4DA728) == -2005532222 )
                CGameBoard::RestoreSurfaces(g_pCGameBoard);
              v8 = *((_QWORD *)g_pCGameBoard + 1889);
              Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CScoreManager::GetScore", 0);
              LODWORD(v8) = *(_DWORD *)(v8 + 44);
              Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
              CTileManager::SetTiles(*((CTileManager **)g_pCGameBoard + 1890), v8);
              CDisplay::Blt(
                g_pDisplay,
                *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1890) + 8LL),
                *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1890) + 12LL),
                g_pTileManagerSurface,
                0);
              v9 = *((_QWORD *)g_pCGameBoard + 1890);
              Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CUIBarObject::GetBoundingRect", 0);
              stru_4DA728 = *(struct tagRECT *)(v9 + 24);
              Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
              if ( CDisplay::Present(g_pDisplay, &stru_4DA728) == -2005532222 )
                CGameBoard::RestoreSurfaces(g_pCGameBoard);
              if ( qword_4DA700 )
              {
                CDisplay::BltInk(g_pDisplay, &stru_4DB750);
                if ( CDisplay::Present(g_pDisplay, &stru_4DB750) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
              }
              if ( qword_4DA708 )
              {
                CDisplay::BltInk(g_pDisplay, &stru_4DB740);
                if ( CDisplay::Present(g_pDisplay, &stru_4DB740) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
              }
              if ( dword_4DA714 )
              {
                if ( dword_4DA714 == 1 )
                {
                  v20 = dword_4DA710;
                  v21 = g_pCGameBoard;
                  v22 = *((_DWORD *)g_pCGameBoard + 3768) - 1;
                  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CGameBoard::GetTileByIndices", 0);
                  v23 = (CBoardObject *)*((_QWORD *)v21 + v22 + v20 * *((int *)v21 + 3768) + 721);
                  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
                  qword_4DA700 = v23;
                  v24 = g_pCGameBoard;
                  LODWORD(v23) = *((_DWORD *)g_pCGameBoard + 3769) - dword_4DA710 - 1;
                  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CGameBoard::GetTileByIndices", 0);
                  v25 = (CBoardObject *)*((_QWORD *)v24 + (int)v23 * (__int64)*((int *)v24 + 3768) + 721);
                  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
                  qword_4DA708 = v25;
                  CBoardObject::GetBoundingRect(qword_4DA700, &stru_4DB750);
                  CBoardObject::GetBoundingRect(qword_4DA708, &stru_4DB740);
                  GoldVersionOfTile = GetGoldVersionOfTile(*((_DWORD *)qword_4DA700 + 10));
                  BitmapRect = (struct tagRECT *)GetBitmapRect(GoldVersionOfTile);
                  CDisplay::Blt(
                    g_pDisplay,
                    (int)*((double *)qword_4DA700 + 1),
                    (int)*((double *)qword_4DA700 + 2),
                    g_pGamePiecesSurface,
                    BitmapRect);
                  if ( CDisplay::Present(g_pDisplay, &stru_4DB750) == -2005532222 )
                    CGameBoard::RestoreSurfaces(g_pCGameBoard);
                  v28 = GetGoldVersionOfTile(*((_DWORD *)qword_4DA708 + 10));
                  v29 = (struct tagRECT *)GetBitmapRect(v28);
                  CDisplay::Blt(
                    g_pDisplay,
                    (int)*((double *)qword_4DA708 + 1),
                    (int)*((double *)qword_4DA708 + 2),
                    g_pGamePiecesSurface,
                    v29);
                  if ( CDisplay::Present(g_pDisplay, &stru_4DB740) == -2005532222 )
                    CGameBoard::RestoreSurfaces(g_pCGameBoard);
                  if ( ++dword_4DA710 >= *((_DWORD *)g_pCGameBoard + 3769) )
                  {
                    dword_4DA710 = 0;
                    dword_4DA714 = 0;
                  }
                }
              }
              else
              {
                v10 = dword_4DA710;
                v11 = g_pCGameBoard;
                Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CGameBoard::GetTileByIndices", 0);
                v12 = (CBoardObject *)*((_QWORD *)v11 + v10 + 721);
                Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
                qword_4DA700 = v12;
                v13 = g_pCGameBoard;
                v14 = *((_DWORD *)g_pCGameBoard + 3769) - 1;
                LODWORD(v11) = *((_DWORD *)g_pCGameBoard + 3768) - dword_4DA710 - 1;
                Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CGameBoard::GetTileByIndices", 0);
                v15 = (CBoardObject *)*((_QWORD *)v13 + (int)v11 + v14 * (__int64)*((int *)v13 + 3768) + 721);
                Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
                qword_4DA708 = v15;
                CBoardObject::GetBoundingRect(qword_4DA700, &stru_4DB750);
                CBoardObject::GetBoundingRect(qword_4DA708, &stru_4DB740);
                v16 = GetGoldVersionOfTile(*((_DWORD *)qword_4DA700 + 10));
                v17 = (struct tagRECT *)GetBitmapRect(v16);
                CDisplay::Blt(
                  g_pDisplay,
                  (int)*((double *)qword_4DA700 + 1),
                  (int)*((double *)qword_4DA700 + 2),
                  g_pGamePiecesSurface,
                  v17);
                if ( CDisplay::Present(g_pDisplay, &stru_4DB750) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
                v18 = GetGoldVersionOfTile(*((_DWORD *)qword_4DA708 + 10));
                v19 = (struct tagRECT *)GetBitmapRect(v18);
                CDisplay::Blt(
                  g_pDisplay,
                  (int)*((double *)qword_4DA708 + 1),
                  (int)*((double *)qword_4DA708 + 2),
                  g_pGamePiecesSurface,
                  v19);
                if ( CDisplay::Present(g_pDisplay, &stru_4DB740) == -2005532222 )
                  CGameBoard::RestoreSurfaces(g_pCGameBoard);
                if ( ++dword_4DA710 >= *((_DWORD *)g_pCGameBoard + 3768) )
                {
                  dword_4DA710 = 0;
                  dword_4DA714 = 1;
                }
              }
            }
            dword_4DA6F8 = 0;
          }
        }
      }
      else
      {
        CGameBoard::PerformUpdate(g_pCGameBoard, v3, 0);
      }
      *(_DWORD *)v1 = Time;
    }
  }
  else
  {
    *(_DWORD *)v1 = timeGetTime();
  }
}
