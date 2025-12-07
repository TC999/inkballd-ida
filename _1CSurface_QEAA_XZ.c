// Hidden C++ exception states: #wind=1
void __fastcall CSurface::~CSurface(CSurface *this)
{
  _BYTE v2[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CSurface::~CSurface", 0);
  if ( *(_QWORD *)this )
  {
    (*(void (__fastcall **)(_QWORD))(**(_QWORD **)this + 16LL))(*(_QWORD *)this);
    *(_QWORD *)this = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
