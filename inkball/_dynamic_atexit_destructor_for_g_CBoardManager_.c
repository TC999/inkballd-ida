void dynamic_atexit_destructor_for__g_CBoardManager__()
{
  const char *v0[3]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v0, "CBoardManager::~CBoardManager", 0);
  CRegistryManager::WriteDifficulty((CRegistryManager *)&g_CRegistryManager, dword_4DA6F4);
  Helpers::CLogBlock::~CLogBlock(v0);
}
