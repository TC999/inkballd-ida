// Hidden C++ exception states: #wind=1
__int64 __fastcall CInk::HitCircleTest(CInk *this, struct tagPOINT *a2, __int64 a3, int a4)
{
  unsigned int v7; // ebx
  __int64 v8; // r8
  __int64 v9; // r8
  int v10; // edi
  struct CTabletContextInfo *TabletContextInfo; // rax
  __int64 v13; // [rsp+30h] [rbp-68h] BYREF
  _DWORD v14[2]; // [rsp+38h] [rbp-60h] BYREF
  unsigned int v15; // [rsp+40h] [rbp-58h] BYREF
  __int64 v16; // [rsp+48h] [rbp-50h]
  _BYTE v17[16]; // [rsp+50h] [rbp-48h] BYREF
  _BYTE v18[16]; // [rsp+60h] [rbp-38h] BYREF
  int v19; // [rsp+A8h] [rbp+10h] BYREF
  int v20; // [rsp+B0h] [rbp+18h] BYREF

  v16 = -2;
  v20 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CInk::HitCircleTest", &v20);
  v13 = 0;
  v14[0] = 10 * a2->x;
  v14[1] = 10 * a2->y;
  v7 = 1;
  v20 = (*(__int64 (__fastcall **)(struct IInkObject *, _DWORD *, __int64, __int64 *))(*(_QWORD *)g_pIInkObject + 216LL))(
          g_pIInkObject,
          v14,
          v8,
          &v13);
  if ( v20 )
  {
    v7 = 0;
  }
  else
  {
    if ( a4 )
    {
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "SetBoardActiveState", 0);
      *((_DWORD *)g_pCGameManager + 1) = 0;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
      (*(void (__fastcall **)(struct IInkObject *, int *))(*(_QWORD *)g_pIInkObject + 32LL))(g_pIInkObject, &v19);
      v20 = (*(__int64 (__fastcall **)(__int64, _QWORD, __int64, unsigned int *))(*(_QWORD *)v13 + 32LL))(
              v13,
              0,
              1,
              &v15);
      v10 = v20 >= 0 && v15 == v19 - 1;
    }
    else
    {
      v10 = v20;
    }
    if ( v13 )
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v13 + 16LL))(v13);
      v13 = 0;
    }
    if ( a4 )
    {
      if ( v10 )
      {
        TabletContextInfo = GetTabletContextInfo(g_tcid);
        if ( TabletContextInfo )
        {
          (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD))(**(_QWORD **)TabletContextInfo + 72LL))(
            *(_QWORD *)TabletContextInfo,
            g_tcid,
            g_cid,
            0,
            0,
            0);
          *((_DWORD *)this + 6) = 0;
        }
      }
      v20 = (*(__int64 (__fastcall **)(struct IInkObject *, _DWORD *, __int64, __int64 *))(*(_QWORD *)g_pIInkObject
                                                                                         + 216LL))(
              g_pIInkObject,
              v14,
              v9,
              &v13);
      if ( !v20 )
      {
        if ( (*(int (__fastcall **)(__int64, _QWORD, __int64, unsigned int *))(*(_QWORD *)v13 + 32LL))(v13, 0, 1, &v15) >= 0 )
          (*(void (__fastcall **)(struct IInkObject *, _QWORD, __int64))(*(_QWORD *)g_pIInkObject + 136LL))(
            g_pIInkObject,
            v15,
            1);
        if ( v13 )
        {
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v13 + 16LL))(v13);
          v13 = 0;
        }
      }
      BltBoardToInk(0);
      *((_DWORD *)this + 6) = 1;
      CInk::DrawInkToSurface(this, 0);
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "SetBoardActiveState", 0);
      *((_DWORD *)g_pCGameManager + 1) = 1;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
  return v7;
}
