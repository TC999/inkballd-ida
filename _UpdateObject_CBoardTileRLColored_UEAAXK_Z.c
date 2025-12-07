// Hidden C++ exception states: #wind=1
void __fastcall CBoardTileRLColored::UpdateObject(CBoardTileRLColored *this, int a2)
{
  int v4; // esi
  int v5; // eax
  _BYTE v6[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBoardTileRLColored::UpdateObject", 0);
  v4 = *((_DWORD *)this + 20);
  *((_DWORD *)this + 24) += a2;
  if ( *((_DWORD *)this + 25) )
  {
    if ( *((_DWORD *)this + 25) == 1 )
    {
      if ( !(unsigned int)BallOnTile(this) )
      {
        *((_DWORD *)this + 25) = 2;
        *((_DWORD *)this + 24) = 0;
      }
    }
    else if ( v4 < 4 && *((_DWORD *)this + 24) > 0x32u )
    {
      *((_DWORD *)this + 20) = v4 + 1;
      *((_DWORD *)this + 24) = 0;
    }
  }
  else if ( v4 > 0 && *((_DWORD *)this + 24) > 0x32u )
  {
    *((_DWORD *)this + 20) = v4 - 1;
    *((_DWORD *)this + 24) = 0;
  }
  v5 = *((_DWORD *)this + 20);
  if ( v5 != v4 )
  {
    *((_QWORD *)this + 4) = GetBitmapRect((unsigned int)(5 * v5 + *((_DWORD *)this + 12) + 77));
    UpdateBoardTile(this);
    ShadowizeTile(this);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
}
