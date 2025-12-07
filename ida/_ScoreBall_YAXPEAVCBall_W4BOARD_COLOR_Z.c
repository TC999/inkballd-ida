// Hidden C++ exception states: #wind=1
void __fastcall ScoreBall(__int64 a1, int a2)
{
  int v4; // ebx
  CGameBoard *v5; // rax
  _BYTE v6[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v7[32]; // [rsp+38h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "ScoreBall", 0);
  if ( a2 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBall::GetDrainPoints", 0);
    v4 = DrainPoints[*(int *)(a1 + 48)];
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
    CScoreManager::IncrementScore(*((CScoreManager **)g_pCGameBoard + 1889), v4);
  }
  v5 = g_pCGameBoard;
  --*((_DWORD *)g_pCGameBoard + 3772);
  if ( *((int *)v5 + 3772) <= 0 )
    *((_DWORD *)g_pCGameManager + 4) = 2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
