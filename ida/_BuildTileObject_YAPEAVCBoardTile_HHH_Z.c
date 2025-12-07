// Hidden C++ exception states: #wind=1
struct CBoardTile *__fastcall BuildTileObject(int a1, int a2, int a3)
{
  unsigned int v6; // r12d
  __int64 v7; // rdi
  void *v8; // rbx
  int *v9; // rax
  CGameBoard *v10; // rbx
  __int64 v11; // rbx
  unsigned int v12; // r15d
  unsigned int v13; // esi
  CBoardTile *v14; // r12
  int *v15; // rbx
  CGameBoard *v16; // rcx
  unsigned int v17; // esi
  CBoardTile *v18; // r12
  int *v19; // rbx
  CGameBoard *v20; // rcx
  unsigned int v21; // esi
  CBoardTile *v22; // r12
  int *v23; // rbx
  CGameBoard *v24; // rcx
  unsigned int v25; // r15d
  unsigned int v26; // esi
  CBoardTile *v27; // r12
  int *v28; // rbx
  CGameBoard *v29; // rcx
  unsigned int v30; // r15d
  int v31; // r12d
  int v32; // esi
  int v33; // ebx
  void *v34; // rcx
  CGameBoard *v35; // rcx
  unsigned int v36; // r12d
  unsigned int v37; // esi
  int *v38; // r15
  void *v39; // rax
  unsigned int v40; // esi
  CBoardTile *v41; // r12
  int *v42; // rbx
  CGameBoard *v43; // rcx
  unsigned int v44; // r15d
  unsigned int v45; // esi
  CBoardTile *v46; // r12
  int *v47; // rbx
  CGameBoard *v48; // rcx
  void *v49; // r15
  int *BitmapRect; // rax
  __int64 v51; // r15
  CGameBoard *v52; // rcx
  double v53; // xmm2_8
  double v54; // xmm2_8
  _BYTE *v56; // rdx
  _BYTE *v57; // rdx
  _BYTE *v58; // rdx
  _BYTE *v59; // rdx
  _BYTE *v60; // rdx
  _BYTE *v61; // rdx
  _BYTE *v62; // rdx
  _BYTE *v63; // rdx
  _BYTE *v64; // rdx
  _BYTE *v65; // rdx
  _BYTE v66[32]; // [rsp+0h] [rbp-98h] BYREF
  __int64 v67; // [rsp+20h] [rbp-78h]
  __int64 v68; // [rsp+40h] [rbp-58h]
  _BYTE v69[16]; // [rsp+48h] [rbp-50h] BYREF
  _BYTE v70[24]; // [rsp+58h] [rbp-40h] BYREF
  int *v71; // [rsp+B8h] [rbp+20h]

  v68 = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v70, "BuildTileObject", 0);
  v6 = (a1 >> 12) & 0xF;
  if ( v6 > 0xA )
    DisplayBoardLoadMsg();
  v7 = 0;
  switch ( v6 )
  {
    case 0u:
    case 9u:
      try
      {
        v49 = operator new(0x60u);
        if ( v49 )
        {
          BitmapRect = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, 0);
          v51 = CBoardTile::CBoardTile((__int64)v49, 0, a2, a3, (__int64)BitmapRect);
        }
        else
        {
          v51 = 0;
        }
      }
      catch ( std::bad_alloc )
      {
        v65 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v65) = 13;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v65, qword_401918);
        }
        v7 = 0;
        break;
      }
      *(_DWORD *)(v51 + 40) = 0;
      v52 = g_pCGameBoard;
      *(_DWORD *)(v51 + 24) = *((_DWORD *)g_pCGameBoard + 3771);
      *(_DWORD *)(v51 + 28) = *((_DWORD *)v52 + 3771);
      *(double *)(v51 + 8) = (double)(*((_DWORD *)v52 + 3766) + a2 * *((_DWORD *)v52 + 3771));
      *(double *)(v51 + 16) = (double)(*((_DWORD *)v52 + 3767) + a3 * *((_DWORD *)v52 + 3771));
      if ( v6 == 9 )
      {
        if ( (a1 & 0xFu) > 4 )
          DisplayBoardLoadMsg();
        v53 = (double)(((a1 >> 4) & 0xF) + 16 * ((a1 >> 8) & 0xF));
        if ( v53 == 255.0 )
        {
          v54 = DOUBLE_N1_0;
        }
        else
        {
          if ( v53 < 0.0 || v53 > 31.0 )
            DisplayBoardLoadMsg();
          v54 = v53 * 11.25;
        }
        AddAliveBallToBoard(a1 & 0xF, (struct CBoardTile *)v51, v54);
      }
      v7 = v51;
      break;
    case 1u:
      try
      {
        v8 = operator new(0x60u);
        if ( v8 )
        {
          v9 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, 1);
          v7 = CBoardTile::CBoardTile((__int64)v8, 1, a2, a3, (__int64)v9);
        }
      }
      catch ( std::bad_alloc )
      {
        v56 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v56) = 14;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v56, qword_401918);
        }
        v7 = 0;
        break;
      }
      *(_DWORD *)(v7 + 40) = 1;
      v10 = g_pCGameBoard;
      *(_DWORD *)(v7 + 24) = *((_DWORD *)g_pCGameBoard + 3771);
      *(_DWORD *)(v7 + 28) = *((_DWORD *)v10 + 3771);
      *(double *)(v7 + 8) = (double)(*((_DWORD *)v10 + 3766) + a2 * *((_DWORD *)v10 + 3771));
      *(double *)(v7 + 16) = (double)(*((_DWORD *)v10 + 3767) + a3 * *((_DWORD *)v10 + 3771));
      v11 = *((_QWORD *)v10 + 1888);
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBallManager::AddBallGenerator", 0);
      *(_QWORD *)(v11 + 8LL * (int)(*(_DWORD *)(v11 + 112))++ + 120) = v7;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
      break;
    case 2u:
      v12 = a1 & 0xF;
      if ( v12 > 4 )
        DisplayBoardLoadMsg();
      v13 = (a1 >> 4) & 0xF;
      if ( v13 > 3 )
        DisplayBoardLoadMsg();
      try
      {
        v14 = (CBoardTile *)operator new(0x60u);
        if ( v14 )
        {
          v15 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v13 + 4 * v12 + 17);
          CBoardTile::CBoardTile(v14);
          *(_QWORD *)v14 = &CBoardTileDrain::`vftable';
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBoardTileDrain::CBoardTileDrain", 0);
          *((_DWORD *)v14 + 19) = v13 + 2;
          *((_DWORD *)v14 + 21) = a2;
          *((_DWORD *)v14 + 22) = a3;
          *((_QWORD *)v14 + 4) = v15;
          *((_DWORD *)v14 + 12) = v12;
          *((_DWORD *)v14 + 20) = 0;
          *((_DWORD *)v14 + 18) = 0;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
        }
        else
        {
          v14 = 0;
        }
      }
      catch ( std::bad_alloc )
      {
        v57 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v57) = 15;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v57, qword_401918);
        }
        v7 = 0;
        break;
      }
      *((_DWORD *)v14 + 10) = v13 + 4 * v12 + 17;
      v16 = g_pCGameBoard;
      *((_DWORD *)v14 + 6) = *((_DWORD *)g_pCGameBoard + 3771);
      *((_DWORD *)v14 + 7) = *((_DWORD *)v16 + 3771);
      *((double *)v14 + 1) = (double)(*((_DWORD *)v16 + 3766) + a2 * *((_DWORD *)v16 + 3771));
      *((double *)v14 + 2) = (double)(*((_DWORD *)v16 + 3767) + a3 * *((_DWORD *)v16 + 3771));
      v7 = (__int64)v14;
      break;
    case 3u:
      v17 = a1 & 0xF;
      if ( v17 > 4 )
        DisplayBoardLoadMsg();
      try
      {
        v18 = (CBoardTile *)operator new(0x60u);
        if ( v18 )
        {
          v19 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v17 + 37);
          CBoardTile::CBoardTile(v18);
          *(_QWORD *)v18 = &CBoardTileWall::`vftable';
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBoardTileWall::CBoardTileWall", 0);
          *((_DWORD *)v18 + 19) = 6;
          *((_DWORD *)v18 + 21) = a2;
          *((_DWORD *)v18 + 22) = a3;
          *((_DWORD *)v18 + 20) = 4;
          *((_QWORD *)v18 + 4) = v19;
          *((_DWORD *)v18 + 12) = v17;
          *((_DWORD *)v18 + 18) = 0;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
        }
        else
        {
          v18 = 0;
        }
      }
      catch ( std::bad_alloc )
      {
        v58 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v58) = 16;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v58, qword_401918);
        }
        v7 = 0;
        break;
      }
      *((_DWORD *)v18 + 10) = v17 + 37;
      v20 = g_pCGameBoard;
      *((_DWORD *)v18 + 6) = *((_DWORD *)g_pCGameBoard + 3771);
      *((_DWORD *)v18 + 7) = *((_DWORD *)v20 + 3771);
      *((double *)v18 + 1) = (double)(*((_DWORD *)v20 + 3766) + a2 * *((_DWORD *)v20 + 3771));
      *((double *)v18 + 2) = (double)(*((_DWORD *)v20 + 3767) + a3 * *((_DWORD *)v20 + 3771));
      v7 = (__int64)v18;
      break;
    case 4u:
      v21 = a1 & 0xF;
      if ( v21 > 4 )
        DisplayBoardLoadMsg();
      try
      {
        v22 = (CBoardTile *)operator new(0x68u);
        if ( v22 )
        {
          v23 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v21 + 42);
          CBoardTile::CBoardTile(v22);
          *(_QWORD *)v22 = &CBoardTileBreakWall::`vftable';
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBoardTileBreakWall::CBoardTileBreakWall", 0);
          *((_DWORD *)v22 + 19) = 9;
          *((_DWORD *)v22 + 21) = a2;
          *((_DWORD *)v22 + 22) = a3;
          *((_DWORD *)v22 + 20) = 4;
          *((_QWORD *)v22 + 4) = v23;
          *((_DWORD *)v22 + 12) = v21;
          *((_QWORD *)v22 + 12) = 0;
          *((_DWORD *)v22 + 18) = 0;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
        }
        else
        {
          v22 = 0;
        }
      }
      catch ( std::bad_alloc )
      {
        v59 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v59) = 17;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v59, qword_401918);
        }
        v7 = 0;
        break;
      }
      *((_DWORD *)v22 + 10) = v21 + 42;
      v24 = g_pCGameBoard;
      *((_DWORD *)v22 + 6) = *((_DWORD *)g_pCGameBoard + 3771);
      *((_DWORD *)v22 + 7) = *((_DWORD *)v24 + 3771);
      *((double *)v22 + 1) = (double)(*((_DWORD *)v24 + 3766) + a2 * *((_DWORD *)v24 + 3771));
      *((double *)v22 + 2) = (double)(*((_DWORD *)v24 + 3767) + a3 * *((_DWORD *)v24 + 3771));
      v7 = (__int64)v22;
      break;
    case 5u:
      v25 = a1 & 0xF;
      if ( v25 > 4 )
        DisplayBoardLoadMsg();
      v26 = (a1 >> 4) & 0xF;
      if ( v26 > 3 )
        DisplayBoardLoadMsg();
      try
      {
        v27 = (CBoardTile *)operator new(0x68u);
        if ( v27 )
        {
          v28 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v26 + v25 + 4 * v26 + 47);
          CBoardTile::CBoardTile(v27);
          *(_QWORD *)v27 = &CBoardTileOWF::`vftable';
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBoardTileOWF::CBoardTileOWF", 0);
          *((_DWORD *)v27 + 19) = 10;
          *((_DWORD *)v27 + 21) = a2;
          *((_DWORD *)v27 + 22) = a3;
          *((_DWORD *)v27 + 20) = 0;
          *((_QWORD *)v27 + 4) = v28;
          *((_DWORD *)v27 + 12) = v25;
          *((_DWORD *)v27 + 24) = v26;
          *((_DWORD *)v27 + 18) = 0;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
        }
        else
        {
          v27 = 0;
        }
      }
      catch ( std::bad_alloc )
      {
        v60 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v60) = 18;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v60, qword_401918);
        }
        v7 = 0;
        break;
      }
      *((_DWORD *)v27 + 10) = v26 + v25 + 4 * v26 + 47;
      v29 = g_pCGameBoard;
      *((_DWORD *)v27 + 6) = *((_DWORD *)g_pCGameBoard + 3771);
      *((_DWORD *)v27 + 7) = *((_DWORD *)v29 + 3771);
      *((double *)v27 + 1) = (double)(*((_DWORD *)v29 + 3766) + a2 * *((_DWORD *)v29 + 3771));
      *((double *)v27 + 2) = (double)(*((_DWORD *)v29 + 3767) + a3 * *((_DWORD *)v29 + 3771));
      v7 = (__int64)v27;
      break;
    case 6u:
      v30 = a1 & 0xF;
      if ( v30 > 4 )
        DisplayBoardLoadMsg();
      v31 = (a1 >> 8) & 0xF;
      v32 = (a1 >> 4) & 0xF;
      v33 = 5 * v30 + 77;
      v71 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v33);
      try
      {
        v34 = operator new(0x78u);
        if ( v34 )
        {
          LODWORD(v67) = 0;
          v7 = CBoardTileRLGray::CBoardTileRLGray(
                 (__int64)v34,
                 a2,
                 a3,
                 (__int64)v71,
                 v67,
                 v30,
                 1000 * (v31 + 1) / 2,
                 1000 * (v32 + 1) / 2);
        }
      }
      catch ( std::bad_alloc )
      {
        v61 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v61) = 19;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v61, qword_401918);
        }
        v7 = 0;
        break;
      }
LABEL_50:
      *(_DWORD *)(v7 + 40) = v33;
      v35 = g_pCGameBoard;
      *(_DWORD *)(v7 + 24) = *((_DWORD *)g_pCGameBoard + 3771);
      *(_DWORD *)(v7 + 28) = *((_DWORD *)v35 + 3771);
      *(double *)(v7 + 8) = (double)(*((_DWORD *)v35 + 3766) + a2 * *((_DWORD *)v35 + 3771));
      *(double *)(v7 + 16) = (double)(*((_DWORD *)v35 + 3767) + a3 * *((_DWORD *)v35 + 3771));
      break;
    case 7u:
      v36 = a1 & 0xF;
      if ( v36 > 4 )
        DisplayBoardLoadMsg();
      v37 = (a1 >> 4) & 0xF;
      if ( v37 > 4 )
        DisplayBoardLoadMsg();
      v33 = v37 + v36 + 4 * v37 + 77;
      v38 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v33);
      try
      {
        v39 = operator new(0x68u);
        if ( v39 )
          v7 = CBoardTileRLColored::CBoardTileRLColored((__int64)v39, a2, a3, (__int64)v38, v36, v37);
      }
      catch ( std::bad_alloc )
      {
        v62 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v62) = 20;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v62, qword_401918);
        }
        v7 = 0;
        break;
      }
      goto LABEL_50;
    case 8u:
      v40 = (a1 >> 4) & 0xF;
      if ( v40 > 3 )
        DisplayBoardLoadMsg();
      try
      {
        v41 = (CBoardTile *)operator new(0x68u);
        if ( v41 )
        {
          v42 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v40 + 102);
          CBoardTile::CBoardTile(v41);
          *(_QWORD *)v41 = &CBoardTileChevron::`vftable';
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBoardTileChevron::CBoardTileChevron", 0);
          *((_DWORD *)v41 + 21) = a2;
          *((_DWORD *)v41 + 22) = a3;
          *((_DWORD *)v41 + 24) = v40;
          *((_DWORD *)v41 + 20) = 0;
          *((_QWORD *)v41 + 4) = v42;
          *((_DWORD *)v41 + 18) = 0;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
          v7 = (__int64)v41;
        }
      }
      catch ( std::bad_alloc )
      {
        v63 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v63) = 21;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v63, qword_401918);
        }
        v7 = 0;
        break;
      }
      *(_DWORD *)(v7 + 40) = v40 + 102;
      v43 = g_pCGameBoard;
      *(_DWORD *)(v7 + 24) = *((_DWORD *)g_pCGameBoard + 3771);
      *(_DWORD *)(v7 + 28) = *((_DWORD *)v43 + 3771);
      *(double *)(v7 + 8) = (double)(*((_DWORD *)v43 + 3766) + a2 * *((_DWORD *)v43 + 3771));
      *(double *)(v7 + 16) = (double)(*((_DWORD *)v43 + 3767) + a3 * *((_DWORD *)v43 + 3771));
      break;
    default:
      v44 = a1 & 0xF;
      if ( v44 > 4 )
        DisplayBoardLoadMsg();
      v45 = (a1 >> 4) & 0xF;
      if ( v45 > 1 )
        DisplayBoardLoadMsg();
      try
      {
        v46 = (CBoardTile *)operator new(0x68u);
        if ( v46 )
        {
          v47 = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, v45 + v44 + 4 * v45 + 67);
          CBoardTile::CBoardTile(v46);
          *(_QWORD *)v46 = &CBoardTileBumper::`vftable';
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v69, "CBoardTileBumper::CBoardTileBumper", 0);
          *((_DWORD *)v46 + 19) = 11;
          *((_DWORD *)v46 + 21) = a2;
          *((_DWORD *)v46 + 22) = a3;
          *((_DWORD *)v46 + 20) = 0;
          *((_QWORD *)v46 + 4) = v47;
          *((_DWORD *)v46 + 12) = v44;
          *((_DWORD *)v46 + 24) = 2 * v45;
          *((_DWORD *)v46 + 18) = 0;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v69);
          v7 = (__int64)v46;
        }
      }
      catch ( std::bad_alloc )
      {
        v64 = v66;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LOWORD(v64) = 22;
          WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v64, qword_401918);
        }
        v7 = 0;
        break;
      }
      *(_DWORD *)(v7 + 40) = v45 + v44 + 4 * v45 + 67;
      v48 = g_pCGameBoard;
      *(_DWORD *)(v7 + 24) = *((_DWORD *)g_pCGameBoard + 3771);
      *(_DWORD *)(v7 + 28) = *((_DWORD *)v48 + 3771);
      *(double *)(v7 + 8) = (double)(*((_DWORD *)v48 + 3766) + a2 * *((_DWORD *)v48 + 3771));
      *(double *)(v7 + 16) = (double)(*((_DWORD *)v48 + 3767) + a3 * *((_DWORD *)v48 + 3771));
      break;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v70);
  return (struct CBoardTile *)v7;
}
