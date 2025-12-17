struct BallPoint *__fastcall CBall::GetPoint(CBall *this, int a2)
{
  __int64 v2; // rdi
  __int64 v4; // rbx
  _BYTE v6[24]; // [rsp+20h] [rbp-18h] BYREF

  v2 = a2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBall::GetPoint", 0);
  v4 = **((_QWORD **)this + 16) + 8 * v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return (struct BallPoint *)v4;
}
