// Hidden C++ exception states: #wind=1
void __fastcall CBoardTileRLGray::UpdateObject(CBoardTileRLGray *this, int a2)
{
  int v4; // esi
  unsigned int v5; // eax
  int v6; // eax
  _BYTE v7[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBoardTileRLGray::UpdateObject", 0);
  v4 = *((_DWORD *)this + 20);
  *((_DWORD *)this + 24) += a2;
  v5 = *((_DWORD *)this + 24);
  *((_DWORD *)this + 25) += a2;
  if ( *((_DWORD *)this + 26) )
  {
    if ( *((_DWORD *)this + 26) == 1 )
    {
      if ( v5 <= *((_DWORD *)this + 27) )
      {
        if ( !(unsigned int)BallOnTile(this) )
        {
          *((_DWORD *)this + 26) = 2;
          *((_DWORD *)this + 24) = 0;
          *((_DWORD *)this + 25) = 0;
        }
      }
      else
      {
        *((_DWORD *)this + 26) = 0;
        *((_DWORD *)this + 24) = 0;
      }
    }
    else if ( v5 >= *((_DWORD *)this + 27) )
    {
      *((_DWORD *)this + 26) = 0;
      *((_DWORD *)this + 24) = 0;
      *((_DWORD *)this + 25) = 0;
    }
    else if ( v4 < 4 && *((_DWORD *)this + 25) > 0x32u )
    {
      *((_DWORD *)this + 20) = v4 + 1;
      *((_DWORD *)this + 25) = 0;
    }
  }
  else if ( v5 >= *((_DWORD *)this + 28) )
  {
    *((_DWORD *)this + 26) = 1;
    *((_DWORD *)this + 24) = 0;
  }
  else if ( v4 > 0 && *((_DWORD *)this + 25) > 0x32u )
  {
    *((_DWORD *)this + 20) = v4 - 1;
    *((_DWORD *)this + 25) = 0;
  }
  v6 = *((_DWORD *)this + 20);
  if ( v6 != v4 )
  {
    *((_QWORD *)this + 4) = GetBitmapRect((unsigned int)(5 * v6 + 77));
    UpdateBoardTile(this);
    ShadowizeTile(this);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
