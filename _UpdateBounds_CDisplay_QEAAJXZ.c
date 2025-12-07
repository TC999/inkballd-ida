__int64 __fastcall CDisplay::UpdateBounds(CDisplay *this)
{
  int *v2; // r8
  int *v3; // r9
  int v4; // r11d
  int v5; // eax
  int yBottom; // ebx
  int *v7; // r8
  int SystemMetrics; // eax
  unsigned int v9; // ebx
  _BYTE v11[24]; // [rsp+30h] [rbp-18h] BYREF
  unsigned int v12; // [rsp+50h] [rbp+8h] BYREF

  v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::UpdateBounds", (int *)&v12);
  if ( *((_DWORD *)this + 20) )
  {
    Helpers::GetClientRect(*((HWND *)this + 7), (HWND)this + 16, 0, v3);
    ClientToScreen(*((HWND *)this + 7), (LPPOINT)this + 8);
    ClientToScreen(*((HWND *)this + 7), (LPPOINT)this + 9);
    v4 = *((_DWORD *)this + 16);
    v5 = *((_DWORD *)this + 18);
    if ( v4 > v5 )
    {
      *((_DWORD *)this + 16) = v5;
      *((_DWORD *)this + 18) = v4;
    }
  }
  else
  {
    yBottom = Helpers::GetSystemMetrics((Helpers *)1, 0, v2);
    SystemMetrics = Helpers::GetSystemMetrics(0, 0, v7);
    SetRect((LPRECT)this + 4, 0, 0, SystemMetrics, yBottom);
  }
  v9 = v12;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v9;
}
