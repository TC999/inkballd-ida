struct CTabletContextInfo *__fastcall GetTabletContextInfo(int a1)
{
  char *v2; // rbx
  int v3; // eax
  _DWORD *v4; // rdx
  _BYTE v6[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "GetTabletContextInfo", 0);
  v2 = 0;
  v3 = 0;
  if ( dword_4B9ED8 > 0 )
  {
    v4 = (char *)g_arrTCI + 16;
    while ( *v4 != a1 )
    {
      ++v3;
      v4 += 8;
      if ( v3 >= dword_4B9ED8 )
        goto LABEL_7;
    }
    v2 = (char *)g_arrTCI + 32 * v3;
  }
LABEL_7:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (struct CTabletContextInfo *)v2;
}
