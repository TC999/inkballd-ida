// Hidden C++ exception states: #wind=1
void __fastcall CTimeManager::UpdateObject(CTimeManager *this, unsigned int a2)
{
  int v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax
  _BYTE v7[32]; // [rsp+28h] [rbp-20h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CTimeManager::UpdateObject", 0);
  v4 = 0;
  if ( *((_DWORD *)this + 15) )
  {
    if ( *((_DWORD *)this + 14) )
    {
      KillPlayer(0);
    }
    else
    {
      v5 = *((_DWORD *)this + 10);
      if ( v5 != -1 )
      {
        if ( v5 > a2 )
        {
          v6 = v5 - a2;
          *((_DWORD *)this + 10) = v6;
          if ( v6 < 0x2AF8 )
          {
            *((_DWORD *)this + 11) += a2;
            *((_DWORD *)this + 12) += a2;
            if ( *((_DWORD *)this + 11) >= 0x14Du )
            {
              *((_DWORD *)this + 11) = 0;
              v4 = 1;
              *((_DWORD *)this + 13) = *((_DWORD *)this + 13) == 0;
            }
            if ( *((_DWORD *)this + 12) >= 0x3E8u )
              *((_DWORD *)this + 12) = 0;
          }
        }
        else
        {
          *((_DWORD *)this + 10) = 0;
          *((_DWORD *)this + 13) = 1;
        }
      }
    }
    if ( *((_DWORD *)this + 10) >= 0x3E8u || *((_DWORD *)this + 14) )
    {
      *((_DWORD *)this + 14) = 0;
      if ( v4 != 1 && *((_DWORD *)this + 10) / 0x3E8u == dword_464ADC / 0x3E8u )
        goto LABEL_18;
    }
    else
    {
      *((_DWORD *)this + 13) = 1;
      *((_DWORD *)this + 14) = 1;
    }
    (*(void (__fastcall **)(CTimeManager *))(*(_QWORD *)this + 8LL))(this);
LABEL_18:
    dword_464ADC = *((_DWORD *)this + 10);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
