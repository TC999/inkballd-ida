// Hidden C++ exception states: #wind=1
__int64 __fastcall BltBoardToInk(struct tagRECT *a1)
{
  unsigned int v2; // ebx
  _BYTE v4[32]; // [rsp+28h] [rbp-20h] BYREF
  int v5; // [rsp+58h] [rbp+10h] BYREF

  v5 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "BltBoardToInk", &v5);
  v2 = CGameBoard::BltBoardToInk(g_pCGameBoard, a1, 0);
  v5 = v2;
  if ( v2 == -2005532222 )
  {
    CGameBoard::RestoreSurfaces(g_pCGameBoard);
    v2 = v5;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
