void __fastcall CBallManager::UpdateBallList(CBallManager *this)
{
  char *v2; // r12
  __int64 v3; // rbp
  __int64 v4; // r9
  _QWORD *v5; // rdx
  __int64 v6; // r8
  __int64 v7; // rax
  int v8; // edi
  struct CBall *Ball; // rbx
  __int64 v10; // rax
  _BYTE v11[16]; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v12[24]; // [rsp+30h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CBallManager::UpdateBallList", 0);
  v2 = (char *)this + 64;
  v3 = 0;
  v4 = *((_QWORD *)this + 8);
  v5 = (_QWORD *)((char *)this + 64);
  v6 = 5;
  do
  {
    v7 = v5[1];
    *v5++ = v7;
    --v6;
    *(_DWORD *)(v7 + 172) = 0;
  }
  while ( v6 );
  *((_QWORD *)this + 13) = v4;
  *(_DWORD *)(v4 + 172) = 0;
  v8 = *((_DWORD *)this + 10);
  if ( v8 < v8 + *((_DWORD *)this + 11) )
  {
    do
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "GetBall", 0);
      Ball = CGameBoard::GetBall(g_pCGameBoard, v8);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
      ++v3;
      *(_DWORD *)(*(_QWORD *)v2 + 48LL) = *((_DWORD *)Ball + 12);
      v10 = *(_QWORD *)v2;
      v2 += 8;
      *(_DWORD *)(v10 + 172) = 1;
      if ( v3 > 5 )
        break;
      ++v8;
    }
    while ( v8 < *((_DWORD *)this + 10) + *((_DWORD *)this + 11) );
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
}
