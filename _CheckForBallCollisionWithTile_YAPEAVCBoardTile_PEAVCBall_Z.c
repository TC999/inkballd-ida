// Hidden C++ exception states: #wind=1
struct CBoardTile *__fastcall CheckForBallCollisionWithTile(struct CBall *this)
{
  double v2; // xmm6_8
  int v3; // r12d
  LONG top; // ebx
  LONG left; // esi
  LONG right; // edi
  LONG bottom; // ebx
  CBoardTile *v8; // rbx
  int v9; // edi
  CBoardTile **v10; // r13
  unsigned __int64 v11; // rbp
  CBoardObject *v12; // rsi
  double v13; // xmm0_8
  struct tagRECT v15; // [rsp+20h] [rbp-C8h] BYREF
  _DWORD v16[8]; // [rsp+30h] [rbp-B8h] BYREF
  CBoardTile *v17[4]; // [rsp+50h] [rbp-98h] BYREF
  _BYTE v18[16]; // [rsp+70h] [rbp-78h] BYREF
  __int64 v19; // [rsp+80h] [rbp-68h]
  struct tagPOINT v20[7]; // [rsp+88h] [rbp-60h] BYREF
  struct tagPOINT v21; // [rsp+F8h] [rbp+10h] BYREF
  struct tagPOINT v22; // [rsp+100h] [rbp+18h] BYREF

  v19 = -2;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CheckForBallCollisionWithTile", 0);
  v2 = DOUBLE_1_797693134862316e308;
  v3 = -1;
  CBoardObject::GetCenterPoint(this, &v22);
  CBoardObject::GetBoundingRect(this, &v15);
  top = v15.top;
  left = v15.left;
  v17[0] = CGameBoard::GetTile(g_pCGameBoard, v15.left, v15.top);
  v16[0] = left;
  v16[1] = top;
  right = v15.right;
  v17[1] = CGameBoard::GetTile(g_pCGameBoard, v15.right, top);
  v16[2] = right;
  v16[3] = top;
  bottom = v15.bottom;
  v17[2] = CGameBoard::GetTile(g_pCGameBoard, left, v15.bottom);
  v16[4] = left;
  v16[5] = bottom;
  v17[3] = CGameBoard::GetTile(g_pCGameBoard, right, bottom);
  v16[6] = right;
  v16[7] = bottom;
  v8 = 0;
  v9 = 0;
  v10 = v17;
  v11 = 0;
  do
  {
    v12 = *v10;
    if ( (*(unsigned int (__fastcall **)(CBoardTile *, struct CBall *, _DWORD *))(*(_QWORD *)*v10 + 16LL))(
           *v10,
           this,
           &v16[v11]) == 2 )
    {
      CBoardObject::GetBoundingRect(v12, &v15);
      if ( (unsigned int)CBall::VerifyCollision(this, &v15, &v20[v11 / 2]) )
      {
        CBoardObject::GetCenterPoint(v12, &v21);
        v13 = sqrt((double)(v21.y - v22.y) * (double)(v21.y - v22.y) + (double)(v21.x - v22.x) * (double)(v21.x - v22.x));
        if ( v2 > v13 )
        {
          v2 = v13;
          v3 = v9;
        }
      }
    }
    ++v9;
    v11 += 2LL;
    ++v10;
  }
  while ( v9 < 4 );
  if ( v3 != -1 )
  {
    v8 = v17[v3];
    CBoardTile::SetClosestSide(v8, &v20[v3]);
    (*(void (__fastcall **)(CBoardTile *, struct CBall *))(*(_QWORD *)v8 + 8LL))(v8, this);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
  return v8;
}
