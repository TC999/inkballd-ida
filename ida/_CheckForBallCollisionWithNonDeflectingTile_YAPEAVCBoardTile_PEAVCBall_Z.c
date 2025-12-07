// Hidden C++ exception states: #wind=1
struct CBoardTile *__fastcall CheckForBallCollisionWithNonDeflectingTile(struct CBall *this)
{
  double v2; // xmm6_8
  int v3; // ebp
  CBoardTile *v4; // rbx
  int v5; // edi
  CBoardTile **v6; // r12
  struct tagPOINT *v7; // r13
  CBoardObject *v8; // rsi
  double v9; // xmm0_8
  struct tagRECT v11; // [rsp+28h] [rbp-A0h] BYREF
  _BYTE v12[16]; // [rsp+38h] [rbp-90h] BYREF
  CBoardTile *v13[4]; // [rsp+48h] [rbp-80h] BYREF
  struct tagPOINT v14[7]; // [rsp+68h] [rbp-60h] BYREF
  struct tagPOINT v15; // [rsp+D8h] [rbp+10h] BYREF
  struct tagPOINT v16; // [rsp+E0h] [rbp+18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CheckForBallCollisionWithNonDeflectingTile", 0);
  v2 = DOUBLE_1_797693134862316e308;
  v3 = -1;
  CBoardObject::GetCenterPoint(this, &v16);
  CBoardObject::GetBoundingRect(this, &v11);
  v13[0] = CGameBoard::GetTile(g_pCGameBoard, v11.left, v11.top);
  v13[1] = CGameBoard::GetTile(g_pCGameBoard, v11.right, v11.top);
  v13[2] = CGameBoard::GetTile(g_pCGameBoard, v11.left, v11.bottom);
  v13[3] = CGameBoard::GetTile(g_pCGameBoard, v11.right, v11.bottom);
  v4 = 0;
  v5 = 0;
  v6 = v13;
  v7 = v14;
  do
  {
    v8 = *v6;
    if ( (*(unsigned int (__fastcall **)(CBoardTile *, struct CBall *, _QWORD))(*(_QWORD *)*v6 + 16LL))(*v6, this, 0) == 1 )
    {
      CBoardObject::GetBoundingRect(v8, &v11);
      if ( (unsigned int)CBall::VerifyCollision(this, &v11, v7) )
      {
        CBoardObject::GetCenterPoint(v8, &v15);
        v9 = sqrt((double)(v15.y - v16.y) * (double)(v15.y - v16.y) + (double)(v15.x - v16.x) * (double)(v15.x - v16.x));
        if ( v2 > v9 )
        {
          v2 = v9;
          v3 = v5;
        }
      }
    }
    ++v5;
    ++v7;
    ++v6;
  }
  while ( v5 < 4 );
  if ( v3 != -1 )
  {
    v4 = v13[v3];
    CBoardTile::SetClosestSide(v4, &v14[v3]);
    (*(void (__fastcall **)(CBoardTile *, struct CBall *))(*(_QWORD *)v4 + 8LL))(v4, this);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
  return v4;
}
