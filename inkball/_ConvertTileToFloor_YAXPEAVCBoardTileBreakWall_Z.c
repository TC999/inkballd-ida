// Hidden C++ exception states: #wind=1
void __fastcall ConvertTileToFloor(struct CBoardTileBreakWall *a1)
{
  __int64 v2; // rbx
  void *v3; // rbx
  int *BitmapRect; // rax
  CGameBoard *v5; // rcx
  _QWORD *v6; // rdx
  _QWORD v7[7]; // [rsp+0h] [rbp-58h] BYREF
  _BYTE v8[32]; // [rsp+38h] [rbp-20h] BYREF

  v7[6] = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "ConvertTileToFloor", 0);
  v2 = *((_QWORD *)a1 + 12);
  if ( !v2 )
  {
    try
    {
      v3 = operator new(0x60u);
      if ( v3 )
      {
        BitmapRect = CGameBoard::GetBitmapRect((__int64)g_pCGameBoard, 0);
        v2 = CBoardTile::CBoardTile((__int64)v3, 0, *((_DWORD *)a1 + 21), *((_DWORD *)a1 + 22), (__int64)BitmapRect);
      }
      else
      {
        v2 = 0;
      }
    }
    catch ( std::bad_alloc )
    {
      v6 = v7;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LOWORD(v6) = 10;
        WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v6, qword_401600);
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
      return;
    }
    if ( !v2 )
    {
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
      return;
    }
    v5 = g_pCGameBoard;
    *(_DWORD *)(v2 + 24) = *((_DWORD *)g_pCGameBoard + 3771);
    *(_DWORD *)(v2 + 28) = *((_DWORD *)v5 + 3771);
    *(_QWORD *)(v2 + 8) = *((_QWORD *)a1 + 1);
    *(_QWORD *)(v2 + 16) = *((_QWORD *)a1 + 2);
  }
  operator delete(a1);
  CGameBoard::SetTile(g_pCGameBoard, (struct CBoardTile *)v2);
  CGameBoard::ShadowizeTile(g_pCGameBoard, (struct CBoardTile *)v2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
