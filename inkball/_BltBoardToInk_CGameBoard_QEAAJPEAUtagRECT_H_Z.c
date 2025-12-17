// Hidden C++ exception states: #wind=1
__int64 __fastcall CGameBoard::BltBoardToInk(CGameBoard *this, struct tagRECT *a2, int a3)
{
  unsigned int v5; // ebx
  _BYTE v7[32]; // [rsp+28h] [rbp-20h] BYREF
  unsigned int v8; // [rsp+68h] [rbp+20h] BYREF

  v8 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CGameBoard::BltBoardToInk", (int *)&v8);
  CDisplay::ClearInk(g_pDisplay, a2, a3);
  v5 = v8;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v5;
}
