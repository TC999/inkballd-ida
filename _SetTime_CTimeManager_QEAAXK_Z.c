// Hidden C++ exception states: #wind=1
void __fastcall CTimeManager::SetTime(CTimeManager *this, int a2)
{
  _BYTE v4[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CTimeManager::SetTime", 0);
  *((_DWORD *)this + 10) = a2;
  *((_DWORD *)this + 14) = 0;
  (*(void (__fastcall **)(CTimeManager *))(*(_QWORD *)this + 8LL))(this);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
