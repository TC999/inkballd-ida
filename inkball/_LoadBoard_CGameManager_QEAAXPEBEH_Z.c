// Hidden C++ exception states: #wind=1
void __fastcall CGameManager::LoadBoard(CGameManager *this, const unsigned __int8 *a2, int a3)
{
  __int64 v3; // rbx
  const unsigned __int8 *v5; // r15
  int v6; // esi
  int v7; // ebx
  const unsigned __int8 *v8; // rdi
  int v9; // ebx
  unsigned __int8 *v10; // rdi
  unsigned int v11; // ebx
  _DWORD *v12; // rbp
  unsigned int v13; // r14d
  unsigned __int8 *v14; // rdi
  int v15; // ebp
  unsigned __int8 *v16; // rdi
  int v17; // ebp
  unsigned __int8 *v18; // rdi
  int v19; // r12d
  unsigned __int8 *v20; // rdi
  int v21; // r12d
  unsigned __int8 *v22; // rdi
  unsigned __int8 *v23; // rdi
  __int64 v24; // r13
  unsigned __int8 *v25; // rdi
  _DWORD *v26; // rbx
  int v27; // r14d
  int i; // ebx
  int v29; // ebp
  CGameBoard *v30; // rcx
  int v31; // ebx
  const unsigned __int8 *v32; // r12
  const unsigned __int8 *v33; // r13
  int v34; // ecx
  unsigned __int8 *v35; // rdi
  int v36; // ecx
  struct CBoardTile *v37; // rax
  int v38; // ecx
  unsigned __int8 *v39; // rdi
  int v40; // ecx
  int v41; // edx
  struct CBoardTile *v42; // r14
  struct CBoardTile *v43; // rax
  _BYTE v44[16]; // [rsp+28h] [rbp-60h] BYREF
  _BYTE v45[80]; // [rsp+38h] [rbp-50h] BYREF
  int v46; // [rsp+98h] [rbp+10h]
  int v47; // [rsp+98h] [rbp+10h]

  v3 = a3;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v45, "CGameManager::LoadBoard", 0);
  v5 = &a2[v3];
  v6 = 0;
  CGameBoard::ResetBoard(g_pCGameBoard);
  if ( (int)v3 > 0 && (__int64)(a2 + 9) > (__int64)v5 )
    goto LABEL_56;
  v7 = *a2 << 8;
  v8 = a2 + 1;
  v9 = *v8 + v7;
  v10 = (unsigned __int8 *)(v8 + 1);
  if ( v9 )
  {
    if ( (unsigned int)(v9 - 1) > 0x3E6 )
      DisplayBoardLoadMsg();
    v11 = 1000 * v9;
  }
  else
  {
    v11 = -1;
  }
  v12 = (_DWORD *)*((_QWORD *)g_pCGameBoard + 1891);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v44, "CTimeManager::InitTime", 0);
  v12[10] = v11;
  if ( v11 != -1 && v11 > 0xF3E58 )
    v12[10] = 999000;
  v12[14] = 0;
  v12[11] = 0;
  v12[13] = 1;
  v12[15] = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v44);
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, *((struct CGameObject **)g_pCGameBoard + 1891));
  v13 = 1000 * *v10;
  v14 = v10 + 1;
  if ( v13 > 0xEA60 )
    DisplayBoardLoadMsg();
  v15 = *v14 << 8;
  v16 = v14 + 1;
  v17 = *v16 + v15;
  v18 = v16 + 1;
  if ( (unsigned int)(v17 - 50) > 0xFA )
    DisplayBoardLoadMsg();
  v19 = *v18 << 8;
  v20 = v18 + 1;
  v21 = *v20 + v19;
  v22 = v20 + 1;
  if ( (unsigned int)(v21 - 50) > 0xFA )
    DisplayBoardLoadMsg();
  if ( v17 > v21 )
    DisplayBoardLoadMsg();
  v46 = *v22;
  v23 = v22 + 1;
  v24 = *v23;
  v25 = v23 + 1;
  if ( (int)v24 > 64 )
    DisplayBoardLoadMsg();
  v26 = (_DWORD *)*((_QWORD *)g_pCGameBoard + 1888);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v44, "CBallManager::Init", 0);
  v26[10] = 0;
  v26[11] = v24;
  v26[12] = v13;
  v26[633] = v17;
  v26[634] = v21;
  v26[28] = 0;
  memset(v26 + 30, 0, 0x960u);
  v26[630] = 1;
  v26[631] = 4000;
  v26[632] = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v44);
  CGameBoard::AddGameObjectToUpdateList(g_pCGameBoard, *((struct CGameObject **)g_pCGameBoard + 1888));
  v27 = a3;
  if ( a3 <= 0 || (__int64)&v25[v24] <= (__int64)v5 )
  {
    for ( i = 0; i < (int)v24; ++i )
    {
      v6 = AddBallToBoard(*v25++);
      if ( v6 < 0 )
        break;
    }
    if ( v46 )
      CGameBoard::RandomizeBallOrder(g_pCGameBoard);
  }
  else
  {
    v6 = -2147418113;
  }
  v29 = 0;
  if ( v6 < 0 )
    goto LABEL_56;
  v30 = g_pCGameBoard;
  do
  {
    if ( v29 >= *((_DWORD *)v30 + 3769) )
      break;
    v31 = 0;
    v32 = v25 + 4;
    v33 = v25 + 2;
    while ( v31 < *((_DWORD *)v30 + 3768) )
    {
      v6 = -2147024882;
      if ( (*v25 & 0xF0) == 0x40 )
      {
        if ( v27 > 0 && (__int64)v32 > (__int64)v5 )
        {
          v6 = -2147418113;
          break;
        }
        v38 = *v25 << 8;
        v39 = v25 + 1;
        v40 = *v39++ + v38;
        v41 = *v39++ << 8;
        v47 = *v39 + v41;
        v25 = v39 + 1;
        v33 += 4;
        v32 += 4;
        v42 = BuildTileObject(v40, v31, v29);
        if ( v42 )
        {
          v43 = BuildTileObject(v47, v31, v29);
          if ( v43 )
          {
            *((_QWORD *)v42 + 12) = v43;
            CGameBoard::SetTile(g_pCGameBoard, v42);
            v6 = 0;
          }
          else
          {
            operator delete(v42);
          }
          v27 = a3;
        }
        else
        {
          v27 = a3;
        }
      }
      else
      {
        if ( v27 > 0 && (__int64)v33 > (__int64)v5 )
        {
          v6 = -2147418113;
          break;
        }
        v34 = *v25 << 8;
        v35 = v25 + 1;
        v36 = *v35 + v34;
        v25 = v35 + 1;
        v33 += 2;
        v32 += 2;
        v37 = BuildTileObject(v36, v31, v29);
        if ( v37 )
        {
          CGameBoard::SetTile(g_pCGameBoard, v37);
          v6 = 0;
        }
      }
      ++v31;
      if ( v6 < 0 )
      {
        v30 = g_pCGameBoard;
        break;
      }
      v30 = g_pCGameBoard;
    }
    ++v29;
  }
  while ( v6 >= 0 );
  if ( v6 < 0 )
LABEL_56:
    DisplayBoardLoadMsg();
  if ( (unsigned int)CGameBoard::BltBoardToInk(v30, 0, 0) == -2005532222 )
    CGameBoard::RestoreSurfaces(g_pCGameBoard);
  if ( (unsigned int)CDisplay::BltInk(g_pDisplay, 0) == -2005532222 )
    CGameBoard::RestoreSurfaces(g_pCGameBoard);
  (*(void (__fastcall **)(_QWORD))(**((_QWORD **)g_pCGameBoard + 1891) + 8LL))(*((_QWORD *)g_pCGameBoard + 1891));
  CGameBoard::PerformUpdate(g_pCGameBoard, 0, 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v45);
}
