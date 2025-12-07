// Hidden C++ exception states: #wind=1
void __fastcall CBallManager::UpdateObject(CBallManager *this, int a2)
{
  char *v4; // rcx
  __int64 v5; // rdx
  int v6; // ecx
  CBoardObject *v7; // rsi
  int v8; // ebx
  struct CBall *Ball; // rbx
  int v10; // eax
  _BYTE v11[16]; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v12[32]; // [rsp+38h] [rbp-20h] BYREF
  struct tagPOINT v13; // [rsp+60h] [rbp+8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CBallManager::UpdateObject", 0);
  if ( *((_DWORD *)this + 630) )
  {
    CBallManager::UpdateBallList(this);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBallManager::InitBallPositions", 0);
    *(_QWORD *)(*((_QWORD *)this + 8) + 8LL) = 0x405A000000000000LL;
    *(_QWORD *)(*((_QWORD *)this + 8) + 16LL) = 0x402C000000000000LL;
    v4 = (char *)this + 72;
    v5 = 5;
    do
    {
      *(double *)(*(_QWORD *)v4 + 8LL) = (double)*(int *)(*((_QWORD *)v4 - 1) + 24LL)
                                       + *(double *)(*((_QWORD *)v4 - 1) + 8LL)
                                       + 0.0;
      *(_QWORD *)(*(_QWORD *)v4 + 16LL) = 0x402C000000000000LL;
      *((_DWORD *)this + 14) = 0;
      v4 += 8;
      --v5;
    }
    while ( v5 );
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
    *((_DWORD *)this + 630) = 0;
  }
  if ( *((int *)this + 11) <= 0 )
  {
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "StartTimer", 0);
    *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1891) + 60LL) = 1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  }
  else
  {
    CBallManager::UpdateBallPositions(this, a2);
    *((_DWORD *)this + 631) -= a2;
    v6 = *((_DWORD *)this + 631);
    if ( v6 <= 800 )
    {
      *((_DWORD *)this + 13) += a2;
      if ( *((_DWORD *)this + 13) >= 0x64u )
      {
        *((_DWORD *)this + 14) = *((_DWORD *)this + 14) == 0;
        *((_DWORD *)this + 13) = 0;
      }
    }
    if ( v6 <= 0 && *((int *)this + 28) > 0 )
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBallManager::GetRandomBallLauncher", 0);
      v7 = (CBoardObject *)*((_QWORD *)this + (int)GetRandomNumber(*((_DWORD *)this + 28)) + 15);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
      if ( (unsigned int)BallOnTile(v7) )
      {
        *((_DWORD *)this + 631) = 0;
      }
      else
      {
        v8 = *((_DWORD *)this + 10);
        *((_DWORD *)this + 10) = v8 + 1;
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "GetBall", 0);
        Ball = CGameBoard::GetBall(g_pCGameBoard, v8);
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
        Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBallManager::SetBallOnLauncher", 0);
        if ( *((_DWORD *)this + 28) )
        {
          CBoardObject::GetCenterPoint(v7, &v13);
          v10 = *((_DWORD *)Ball + 6) / 2;
          *((double *)Ball + 1) = (double)(v13.x - v10);
          *((double *)Ball + 2) = (double)(v13.y - v10);
        }
        Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
        CBallManager::SetBallSpeed(this, Ball, -1.0);
        *((_DWORD *)Ball + 44) = 1;
        *((_DWORD *)Ball + 43) = 1;
        --*((_DWORD *)this + 11);
        *((_DWORD *)this + 631) = *((_DWORD *)this + 12);
        *((_DWORD *)this + 14) = 0;
        CBallManager::UpdateBallList(this);
        if ( !*((_DWORD *)this + 632) )
        {
          *((_DWORD *)this + 632) = 1;
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "StartTimer", 0);
          *(_DWORD *)(*((_QWORD *)g_pCGameBoard + 1891) + 60LL) = 1;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
        }
      }
    }
  }
  (*(void (__fastcall **)(CBallManager *))(*(_QWORD *)this + 8LL))(this);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
}
