int dynamic_initializer_for__g_CBoardManager__()
{
  HRSRC ResourceW; // rax
  int *v1; // r9
  HRSRC v2; // rbx
  HGLOBAL Resource; // rdi
  size_t v4; // rbx
  const void *v5; // rax
  const char *v7[3]; // [rsp+20h] [rbp-18h] BYREF

  v7[0] = 0;
  v7[1] = "CBoardManager::CBoardManager";
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
    && _bittest((const signed __int32 *)WPP_GLOBAL_Control + 7, 0xAu) )
  {
    WPP_SF_s(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (__int64)&stru_4015E0, "CBoardManager::CBoardManager");
  }
  ResourceW = Helpers::FindResourceW(0, (const WCHAR *)0x4E21, L"IKL", 0);
  v2 = ResourceW;
  if ( ResourceW )
  {
    Resource = Helpers::LoadResource(0, ResourceW, 0, v1);
    if ( Resource )
    {
      v4 = SizeofResource(0, v2);
      v5 = LockResource(Resource);
      if ( (unsigned int)v4 <= 0x51C84 )
      {
        if ( v5 )
          memcpy(&g_BoardData, v5, v4);
      }
    }
  }
  Helpers::CLogBlock::~CLogBlock(v7);
  return atexit((void (__cdecl *)())dynamic_atexit_destructor_for__g_CBoardManager__);
}
