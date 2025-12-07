__int64 __fastcall CSink::CursorDown(
        CSink *this,
        unsigned int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        unsigned __int8 *a6)
{
  struct CTabletContextInfo *TabletContextInfo; // rax
  unsigned int v10; // ebx
  __int64 v11; // rax
  __int64 v12; // rbx
  struct tagRECT *v13; // rbx
  int v14; // eax
  struct IInkStroke *v15; // rbx
  unsigned int v17; // [rsp+20h] [rbp-38h] BYREF
  unsigned int v18; // [rsp+24h] [rbp-34h] BYREF
  struct IInkStroke *v19; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v20[16]; // [rsp+30h] [rbp-28h] BYREF
  _BYTE v21[24]; // [rsp+40h] [rbp-18h] BYREF

  v17 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CSink::CursorDown", (int *)&v17);
  TabletContextInfo = GetTabletContextInfo(a2);
  if ( TabletContextInfo
    && *((_DWORD *)TabletContextInfo + 6) < a5 >> 2
    && (*(_DWORD *)&a6[4 * *((unsigned int *)TabletContextInfo + 6)] & *((_DWORD *)TabletContextInfo + 7)) != 0 )
  {
    v10 = v17;
    goto LABEL_19;
  }
  if ( !(unsigned int)AcceptInkInput() || g_tcid )
  {
LABEL_18:
    v17 = 0;
    v10 = 0;
    goto LABEL_19;
  }
  *((_DWORD *)this + 3) = 1;
  SetCursorAttributes(a3);
  v11 = *(_QWORD *)g_pIInkObject;
  g_tcid = a2;
  g_cid = a3;
  if ( (*(int (__fastcall **)(struct IInkObject *, unsigned int *))(v11 + 32))(g_pIInkObject, &v18) >= 0 && v18 >= 0x14 )
  {
    (*(void (__fastcall **)(struct IInkObject *, _QWORD, _QWORD))(*(_QWORD *)g_pIInkObject + 136LL))(
      g_pIInkObject,
      0,
      v18 - 19);
    BltBoardToInk(0);
    v12 = *((_QWORD *)g_pCGameBoard + 1893);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CInk::SetInkRedrawFlag", 0);
    *(_DWORD *)(v12 + 20) = 1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
    v13 = (struct tagRECT *)g_pCGameBoard;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "CGameBoard::GetPlayingAreaRect", 0);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
    AddDisplayUpdateRect(v13 + 505);
  }
  v19 = 0;
  v14 = (*(__int64 (__fastcall **)(struct IInkCollect *, _QWORD, _QWORD, struct IInkStroke **))(*(_QWORD *)g_pIInkCollect
                                                                                              + 24LL))(
          g_pIInkCollect,
          a2,
          a3,
          &v19);
  v17 = v14;
  if ( v14 >= 0 )
  {
    v15 = v19;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v20, "SetCursorStroke", 0);
    if ( g_pIStroke )
      (*(void (__fastcall **)(struct IInkStroke *))(*(_QWORD *)g_pIStroke + 16LL))(g_pIStroke);
    g_pIStroke = v15;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v20);
    (*(void (__fastcall **)(struct IInkCollect *, _QWORD, _QWORD, unsigned __int8 *, unsigned int))(*(_QWORD *)g_pIInkCollect
                                                                                                  + 32LL))(
      g_pIInkCollect,
      a3,
      a5,
      a6,
      v17);
    goto LABEL_18;
  }
  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x17u, (const GUID *)qword_401630, v14);
  v10 = -2147467259;
  v17 = -2147467259;
LABEL_19:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v21);
  return v10;
}
