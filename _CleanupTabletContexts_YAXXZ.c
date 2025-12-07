// Hidden C++ exception states: #wind=1
void CleanupTabletContexts(void)
{
  int v0; // edi
  __int64 v1; // rbx
  __int64 v2; // rcx
  __int64 v3; // rcx
  _BYTE v4[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CleanupTabletContexts", 0);
  v0 = 0;
  if ( dword_4B9ED8 > 0 )
  {
    v1 = 0;
    do
    {
      v2 = *(_QWORD *)((char *)g_arrTCI + v1 + 8);
      if ( v2 )
      {
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
        *(_QWORD *)((char *)g_arrTCI + v1 + 8) = 0;
      }
      v3 = *(_QWORD *)((char *)g_arrTCI + v1);
      if ( v3 )
      {
        (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
        *(_QWORD *)((char *)g_arrTCI + v1) = 0;
      }
      ++v0;
      v1 += 32;
    }
    while ( v0 < dword_4B9ED8 );
  }
  CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetSize(0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
