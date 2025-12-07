struct BallPoint *__fastcall CBall::GetNextPoint(CBall *this)
{
  int v2; // r8d
  __int64 v3; // rbx
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::GetNextPoint", 0);
  v2 = *((_DWORD *)this + 35);
  if ( v2 <= 16 )
  {
    v3 = **((_QWORD **)this + 16) + 8LL * ((v2 + *((_DWORD *)this + 34)) % 32);
    *((_DWORD *)this + 35) = v2 + 1;
  }
  else
  {
    v3 = 0;
    *((_DWORD *)this + 35) = 0;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (struct BallPoint *)v3;
}
