__int64 __fastcall CSink::SystemEvent(CSink *this, int a2, int a3, __int16 a4)
{
  struct CTabletContextInfo *TabletContextInfo; // rax
  __int64 v8; // rbx
  struct tagRECT *v9; // rbx
  int v11; // [rsp+30h] [rbp-38h] BYREF
  _BYTE v12[16]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v13[32]; // [rsp+48h] [rbp-20h] BYREF
  int v14; // [rsp+88h] [rbp+20h] BYREF

  v14 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CSink::SystemEvent", &v14);
  if ( a4 == 21 && g_tcid == a2 && g_cid == a3 )
  {
    TabletContextInfo = GetTabletContextInfo(g_tcid);
    if ( TabletContextInfo )
      (*(void (__fastcall **)(_QWORD, _QWORD, _QWORD, _QWORD, _DWORD, _QWORD))(**(_QWORD **)TabletContextInfo + 72LL))(
        *(_QWORD *)TabletContextInfo,
        g_tcid,
        g_cid,
        0,
        0,
        0);
    if ( (*(int (__fastcall **)(struct IInkObject *, int *))(*(_QWORD *)g_pIInkObject + 32LL))(g_pIInkObject, &v11) >= 0
      && v11 )
    {
      (*(void (__fastcall **)(struct IInkObject *, _QWORD, __int64))(*(_QWORD *)g_pIInkObject + 136LL))(
        g_pIInkObject,
        (unsigned int)(v11 - 1),
        1);
      BltBoardToInk(0);
      v8 = *((_QWORD *)g_pCGameBoard + 1893);
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CInk::SetInkRedrawFlag", 0);
      *(_DWORD *)(v8 + 20) = 1;
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
      v9 = (struct tagRECT *)g_pCGameBoard;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CGameBoard::GetPlayingAreaRect", 0);
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
      AddDisplayUpdateRect(v9 + 505);
    }
  }
  v14 = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
  return 0;
}
