// Hidden C++ exception states: #wind=1
void __fastcall CScoreManager::IncrementScore(CScoreManager *this, int a2)
{
  unsigned int v4; // eax
  _BYTE v5[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CScoreManager::IncrementScore", 0);
  *((_DWORD *)this + 11) += a2;
  v4 = *((_DWORD *)this + 11);
  if ( v4 >= *((_DWORD *)this + 10) )
    *((_DWORD *)this + 10) = v4;
  (*(void (__fastcall **)(CScoreManager *))(*(_QWORD *)this + 8LL))(this);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
