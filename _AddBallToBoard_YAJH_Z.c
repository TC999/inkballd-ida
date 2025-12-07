// Hidden C++ exception states: #wind=2
__int64 __fastcall AddBallToBoard(int a1)
{
  void *v2; // rbx
  int *BitmapRect; // rax
  struct CBall *v4; // rbx
  CGameBoard *v6; // rcx
  _QWORD *v7; // rdx
  _QWORD v8[7]; // [rsp+0h] [rbp-68h] BYREF
  _BYTE v9[16]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v10[32]; // [rsp+48h] [rbp-20h] BYREF
  int v11; // [rsp+78h] [rbp+10h] BYREF
  void *v12; // [rsp+80h] [rbp+18h]

  v8[6] = -2;
  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "AddBallToBoard", &v11);
  try
  {
    v2 = operator new(0x1B8u);
    v12 = v2;
    if ( v2 )
    {
      BitmapRect = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, a1 + 2);
      v4 = (struct CBall *)CBall::CBall((__int64)v2, (__int64)BitmapRect, a1, 1, *((_DWORD *)g_pCGameBoard + 3770));
    }
    else
    {
      v4 = 0;
    }
  }
  catch ( std::bad_alloc )
  {
    v7 = v8;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v7) = 11;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v7, qword_401918);
    }
    v11 = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    return 2147942414LL;
  }
  if ( v4 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBall::AddRef", 0);
    ++*((_DWORD *)v4 + 37);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
    v6 = g_pCGameBoard;
    *((_DWORD *)v4 + 6) = *((_DWORD *)g_pCGameBoard + 3770);
    *((_DWORD *)v4 + 7) = *((_DWORD *)v6 + 3770);
    *((_DWORD *)v4 + 43) = 0;
    *((_DWORD *)v4 + 44) = 0;
    CGameBoard::AddBall(v6, v4);
    v11 = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    return 0;
  }
  else
  {
    v11 = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
    return 2147942414LL;
  }
}
