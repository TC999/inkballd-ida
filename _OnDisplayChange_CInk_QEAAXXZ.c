// Hidden C++ exception states: #wind=1
void __fastcall CInk::OnDisplayChange(CInk *this)
{
  __int64 v1; // rdi
  __int64 v2; // rbx
  __int64 v3; // [rsp+20h] [rbp-38h]
  _BYTE v4[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v5[32]; // [rsp+38h] [rbp-20h] BYREF
  int v6; // [rsp+68h] [rbp+10h] BYREF

  v3 = -2;
  v6 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CInk::OnDisplayChange", &v6);
  v1 = dword_4B9ED8;
  if ( dword_4B9ED8 > 0 )
  {
    v2 = 0;
    do
    {
      v6 = (*(__int64 (__fastcall **)(_QWORD, _BYTE *))(**(_QWORD **)((char *)g_arrTCI + v2 + 8) + 112LL))(
             *(_QWORD *)((char *)g_arrTCI + v2 + 8),
             v4);
      if ( v6 >= 0 )
        v6 = (*(__int64 (__fastcall **)(struct IInkObject *, _QWORD, _BYTE *, void *, __int64))(*(_QWORD *)g_pIInkObject
                                                                                              + 264LL))(
               g_pIInkObject,
               *(unsigned int *)((char *)g_arrTCI + v2 + 16),
               v4,
               &g_rcTabletInInk,
               v3);
      v2 += 32;
      --v1;
    }
    while ( v1 );
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
