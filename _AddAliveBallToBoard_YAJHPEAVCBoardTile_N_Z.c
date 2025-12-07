// Hidden C++ exception states: #wind=2
__int64 __fastcall AddAliveBallToBoard(int a1, struct CBoardTile *a2, double a3)
{
  CGameBoard *v5; // rbx
  void *v6; // rbx
  int *BitmapRect; // rax
  __int64 v8; // rbx
  CGameBoard *v10; // rcx
  __int64 *v11; // rdx
  __int64 v12; // [rsp+0h] [rbp-78h] BYREF
  struct tagPOINT v13; // [rsp+30h] [rbp-48h] BYREF
  __int64 v14; // [rsp+38h] [rbp-40h]
  _QWORD v15[2]; // [rsp+40h] [rbp-38h] BYREF
  _BYTE v16[16]; // [rsp+50h] [rbp-28h] BYREF
  int v17; // [rsp+98h] [rbp+20h] BYREF

  v14 = -2;
  v17 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "AddAliveBallToBoard", &v17);
  v5 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CGameBoard::NumBallsOnBoard", 0);
  LODWORD(v5) = *((_DWORD *)v5 + 1312);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
  if ( (int)v5 >= 64 )
    DisplayBoardLoadMsg();
  CBoardObject::GetCenterPoint(a2, &v13);
  try
  {
    v6 = operator new(0x1B8u);
    v15[0] = v6;
    if ( v6 )
    {
      BitmapRect = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, a1 + 2);
      v8 = CBall::CBall((__int64)v6, (__int64)BitmapRect, a1, 1, *((_DWORD *)g_pCGameBoard + 3770));
    }
    else
    {
      v8 = 0;
    }
  }
  catch ( std::bad_alloc )
  {
    v11 = &v12;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v11) = 12;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v11, qword_401918);
    }
    v17 = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
    return 2147942414LL;
  }
  if ( v8 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CBall::AddRef", 0);
    ++*(_DWORD *)(v8 + 148);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    v10 = g_pCGameBoard;
    *(_DWORD *)(v8 + 24) = *((_DWORD *)g_pCGameBoard + 3770);
    *(_DWORD *)(v8 + 28) = *((_DWORD *)v10 + 3770);
    *(double *)(v8 + 8) = (double)v13.x - (double)*((int *)v10 + 3770) * 0.5;
    *(double *)(v8 + 16) = (double)v13.y - (double)*((int *)v10 + 3770) * 0.5;
    CBallManager::SetBallSpeed(*((CBallManager **)v10 + 1888), (struct CBall *)v8, a3);
    *(_DWORD *)(v8 + 172) = 1;
    *(_DWORD *)(v8 + 176) = 1;
    CGameBoard::AddBall(g_pCGameBoard, (struct CBall *)v8);
    v17 = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
    return 0;
  }
  else
  {
    v17 = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
    return 2147942414LL;
  }
}
