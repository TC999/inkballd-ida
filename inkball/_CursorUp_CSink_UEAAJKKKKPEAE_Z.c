__int64 __fastcall CSink::CursorUp(
        CSink *this,
        int a2,
        unsigned int a3,
        __int64 a4,
        unsigned int a5,
        unsigned __int8 *a6)
{
  int v9; // eax
  int v10; // eax
  int v11; // eax
  __int64 v12; // rbx
  int v14; // [rsp+20h] [rbp-48h] BYREF
  HDC v15; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v16[16]; // [rsp+30h] [rbp-38h] BYREF
  _BYTE v17[16]; // [rsp+40h] [rbp-28h] BYREF
  _BYTE v18[24]; // [rsp+50h] [rbp-18h] BYREF

  v14 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CSink::CursorUp", &v14);
  if ( (unsigned int)AcceptInkInput() && g_tcid == a2 && g_cid == a3 && *((_DWORD *)this + 3) )
  {
    *((_DWORD *)this + 3) = 0;
    v9 = (*(__int64 (__fastcall **)(struct IInkCollect *, _QWORD, _QWORD, unsigned __int8 *))(*(_QWORD *)g_pIInkCollect
                                                                                            + 32LL))(
           g_pIInkCollect,
           a3,
           a5,
           a6);
    v14 = v9;
    if ( v9 < 0
      && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x18u, (const GUID *)qword_401630, v9);
    }
    v15 = 0;
    GetInkBufferHDC(&v15);
    if ( v15 )
    {
      v10 = (*(__int64 (__fastcall **)(struct IRenderingContext *, _QWORD))(*(_QWORD *)g_pIRenderingContext + 72LL))(
              g_pIRenderingContext,
              a3);
      v14 = v10;
      if ( v10 < 0
        && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
        && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x19u, (const GUID *)qword_401630, v10);
      }
      ReleaseInkBufferHDC(v15);
    }
    v11 = (*(__int64 (__fastcall **)(struct IInkCollect *, _QWORD, _QWORD, _BYTE *, int))(*(_QWORD *)g_pIInkCollect
                                                                                        + 40LL))(
            g_pIInkCollect,
            a3,
            0,
            v18,
            v14);
    v14 = v11;
    if ( v11 < 0
      && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Au, (const GUID *)qword_401630, v11);
    }
    v12 = *((_QWORD *)g_pCGameBoard + 1893);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CInk::SetInkModifiedFlag", 0);
    *(_DWORD *)(v12 + 16) = 1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
    g_tcid = 0;
    g_cid = -1;
  }
  v14 = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
  return 0;
}
