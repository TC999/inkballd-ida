// Hidden C++ exception states: #wind=1
void __fastcall CGameBoard::QueryNewPallete(CGameBoard *this)
{
  CDisplay *v1; // rbx
  __int64 v2; // rbx
  CDisplay *v3; // rbx
  __int64 v4; // rbx
  _BYTE v5[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v6[32]; // [rsp+38h] [rbp-20h] BYREF
  __int64 v7; // [rsp+68h] [rbp+10h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameBoard::QueryNewPallete", 0);
  v7 = 0;
  v1 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CDisplay::GetFrontBuffer", 0);
  v2 = *((_QWORD *)v1 + 2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  (*(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)v2 + 160LL))(v2, &v7);
  v3 = g_pDisplay;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CDisplay::GetFrontBuffer", 0);
  v4 = *((_QWORD *)v3 + 2);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v4 + 248LL))(v4, v7);
  if ( v7 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v7 + 16LL))(v7);
    v7 = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
