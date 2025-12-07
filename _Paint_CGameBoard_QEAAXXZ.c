// Hidden C++ exception states: #wind=1
void __fastcall CGameBoard::Paint(CGameBoard *this)
{
  CGameBoard *v1; // rdi
  CDisplay *v2; // rbx
  __int64 v3; // rbx
  _BYTE v4[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v5[32]; // [rsp+38h] [rbp-20h] BYREF

  v1 = g_pCGameBoard;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::Paint", 0);
  v2 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CDisplay::GetDirectDraw", 0);
  v3 = *((_QWORD *)v2 + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  if ( (*(unsigned int (__fastcall **)(__int64))(*(_QWORD *)v3 + 208LL))(v3) == -2005532085 )
  {
    CGameBoard::CreateNewSurfaces(v1);
    CGameBoard::RestoreSurfaces(v1);
  }
  if ( (unsigned int)CGameBoard::DisplayFrame(v1, 1, 1) == -2005532222 )
  {
    CGameBoard::RestoreSurfaces(v1);
    CGameBoard::DisplayFrame(v1, 1, 1);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
