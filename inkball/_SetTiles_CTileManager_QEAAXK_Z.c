// Hidden C++ exception states: #wind=1
void __fastcall CTileManager::SetTiles(CTileManager *this, unsigned int a2)
{
  unsigned int v4; // eax
  unsigned int v5; // ecx
  _BYTE v6[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CTileManager::SetTiles", 0);
  if ( a2 )
  {
    v4 = a2 - *((_DWORD *)this + 11);
    v5 = *((_DWORD *)this + 12);
    if ( v4 >= v5 )
    {
      *((_DWORD *)this + 10) += v4 / v5;
      *((_DWORD *)this + 11) = v5 * (a2 / v5);
      (*(void (__fastcall **)(CTileManager *, _QWORD))(*(_QWORD *)this + 8LL))(this, a2 % v5);
    }
  }
  else
  {
    *((_DWORD *)this + 11) = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
