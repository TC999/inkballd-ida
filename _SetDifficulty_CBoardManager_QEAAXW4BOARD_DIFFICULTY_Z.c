// Hidden C++ exception states: #wind=1
void __fastcall CBoardManager::SetDifficulty(__int64 a1, unsigned int a2)
{
  _BYTE v3[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardManager::SetDifficulty", 0);
  KillPlayer(2);
  dword_4DA6F4 = a2;
  memset(&g_bhPrevBoards, 0, 0x2Cu);
  memset(&g_bhPrevBonusBoards, 0, 0x2Cu);
  if ( a2 )
  {
    switch ( a2 )
    {
      case 1u:
        paBoardList = (struct BoardCollection *)&g_aNoviceBoards;
        iBoardListCount = 78;
        paBonusBoardList = (struct BoardCollection *)&g_aNoviceBonusBoards;
        iBonusBoardListCount = 28;
        break;
      case 2u:
        paBoardList = (struct BoardCollection *)&g_aIntermediateBoards;
        iBoardListCount = 77;
        paBonusBoardList = (struct BoardCollection *)&g_aIntermediateBonusBoards;
        iBonusBoardListCount = 26;
        break;
      case 3u:
        paBoardList = (struct BoardCollection *)&g_aAdvancedBoards;
        iBoardListCount = 73;
        paBonusBoardList = (struct BoardCollection *)&g_aAdvancedBonusBoards;
        iBonusBoardListCount = 21;
        break;
      case 4u:
        paBoardList = (struct BoardCollection *)&g_aExpertBoards;
        iBoardListCount = 45;
        paBonusBoardList = (struct BoardCollection *)&g_aExpertBonusBoards;
        iBonusBoardListCount = 17;
        break;
      default:
        dword_4DA6F4 = 0;
        paBoardList = (struct BoardCollection *)&g_aBeginnerBoards;
        iBoardListCount = 138;
        paBonusBoardList = (struct BoardCollection *)&g_aBeginnerBonusBoards;
        iBonusBoardListCount = 48;
        break;
    }
  }
  else
  {
    paBoardList = (struct BoardCollection *)&g_aBeginnerBoards;
    iBoardListCount = 138;
    paBonusBoardList = (struct BoardCollection *)&g_aBeginnerBonusBoards;
    iBonusBoardListCount = 48;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
