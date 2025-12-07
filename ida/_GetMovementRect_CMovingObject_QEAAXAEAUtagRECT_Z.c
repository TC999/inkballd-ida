void __fastcall CMovingObject::GetMovementRect(CMovingObject *this, struct tagRECT *a2)
{
  int v4; // eax
  double v5; // xmm0_8
  int v6; // edx
  int v7; // eax
  int v8; // ecx
  int v9; // eax
  double v10; // xmm0_8
  int v11; // eax
  _BYTE v12[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CMovingObject::GetMovementRect", 0);
  v4 = *((_DWORD *)this + 30);
  v5 = *((double *)this + 11);
  if ( *((_DWORD *)this + 6) > v4 )
    v4 = *((_DWORD *)this + 6);
  v6 = v4 + 2;
  v7 = *((_DWORD *)this + 31);
  if ( *((_DWORD *)this + 7) > v7 )
    v7 = *((_DWORD *)this + 7);
  v8 = v7 + 2;
  if ( v5 <= *((double *)this + 1) )
  {
    a2->left = (int)v5;
    v9 = (int)*((double *)this + 1);
  }
  else
  {
    a2->left = (int)*((double *)this + 1);
    v9 = (int)*((double *)this + 11);
  }
  a2->right = v6 + v9;
  v10 = *((double *)this + 12);
  if ( v10 <= *((double *)this + 2) )
  {
    a2->top = (int)v10;
    v11 = (int)*((double *)this + 2);
  }
  else
  {
    a2->top = (int)*((double *)this + 2);
    v11 = (int)*((double *)this + 12);
  }
  a2->bottom = v8 + v11;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
}
