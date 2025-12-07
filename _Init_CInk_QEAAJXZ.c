// Hidden C++ exception states: #wind=1
__int64 __fastcall CInk::Init(CInk *this)
{
  CInk *v1; // r15
  HRESULT Instance; // eax
  int v3; // ebx
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  unsigned int v11; // r12d
  int v12; // eax
  _DWORD *v13; // rcx
  int v14; // eax
  int v15; // eax
  unsigned int i; // ecx
  _QWORD *v17; // rax
  bool v18; // cf
  unsigned __int64 v19; // r9
  int v20; // eax
  __int64 v21; // r14
  int v22; // ebx
  __int64 v23; // rcx
  __int64 *v25; // rdx
  __int64 v26; // [rsp+0h] [rbp-E8h] BYREF
  __int64 v27; // [rsp+50h] [rbp-98h] BYREF
  __int64 v28; // [rsp+58h] [rbp-90h] BYREF
  LPVOID pv[2]; // [rsp+60h] [rbp-88h] BYREF
  _BYTE v30[16]; // [rsp+70h] [rbp-78h] BYREF
  _BYTE v31[16]; // [rsp+80h] [rbp-68h] BYREF
  _QWORD Src[11]; // [rsp+90h] [rbp-58h] BYREF
  HRESULT v34; // [rsp+F8h] [rbp+10h] BYREF
  unsigned int v35; // [rsp+100h] [rbp+18h] BYREF
  LPVOID v36; // [rsp+108h] [rbp+20h] BYREF

  pv[1] = (LPVOID)-2LL;
  v1 = this;
  v34 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v31, "CInk::Init", &v34);
  *((_DWORD *)v1 + 6) = 1;
  CleanupTabletContexts();
  Instance = CoCreateInstance(&CLSID_TpcPlatformManager, 0, 1u, &IID_IInkManager, &g_pIInkManager);
  v3 = Instance;
  v34 = Instance;
  if ( Instance < 0 )
  {
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x16u, (const GUID *)qword_401630, Instance);
      v3 = v34;
    }
  }
  else
  {
    v4 = (*(__int64 (__fastcall **)(LPVOID))(*(_QWORD *)g_pIInkManager + 24LL))(g_pIInkManager);
    v3 = v4;
    v34 = v4;
    if ( v4 < 0 )
    {
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x15u, (const GUID *)qword_401630, v4);
        v3 = v34;
      }
    }
    else
    {
      v5 = (*(__int64 (__fastcall **)(LPVOID, struct IInkObject **))(*(_QWORD *)g_pIInkManager + 40LL))(
             g_pIInkManager,
             &g_pIInkObject);
      v3 = v5;
      v34 = v5;
      if ( v5 < 0 )
      {
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x14u, (const GUID *)qword_401630, v5);
          v3 = v34;
        }
      }
      else
      {
        v6 = (**(__int64 (__fastcall ***)(struct IInkObject *, GUID *, struct IRenderInk **))g_pIInkObject)(
               g_pIInkObject,
               &IID_IRenderInk,
               &g_pIRenderInk);
        v3 = v6;
        v34 = v6;
        if ( v6 < 0 )
        {
          if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x13u, (const GUID *)qword_401630, v6);
            v3 = v34;
          }
        }
        else
        {
          v7 = (**(__int64 (__fastcall ***)(struct IInkObject *, GUID *, struct IInkCollect **))g_pIInkObject)(
                 g_pIInkObject,
                 &IID_IInkCollect,
                 &g_pIInkCollect);
          v3 = v7;
          v34 = v7;
          if ( v7 < 0 )
          {
            if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x12u, (const GUID *)qword_401630, v7);
              v3 = v34;
            }
          }
          else
          {
            v34 = (*(__int64 (__fastcall **)(struct IInkObject *, void *))(*(_QWORD *)g_pIInkObject + 104LL))(
                    g_pIInkObject,
                    &g_rcInkSpace);
            v8 = (*(__int64 (__fastcall **)(struct IInkObject *, __int64 *, _QWORD, struct IRenderingContext **))(*(_QWORD *)g_pIInkObject + 272LL))(
                   g_pIInkObject,
                   qword_401900,
                   0,
                   &g_pIRenderingContext);
            v3 = v8;
            v34 = v8;
            if ( v8 < 0 )
            {
              if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x11u, (const GUID *)qword_401630, v8);
                v3 = v34;
              }
            }
            else
            {
              v34 = (*(__int64 (__fastcall **)(struct IRenderingContext *, void *, struct HWND__ *))(*(_QWORD *)g_pIRenderingContext + 48LL))(
                      g_pIRenderingContext,
                      &g_rcInkSpace,
                      &g_rcClient);
              v9 = (**(__int64 (__fastcall ***)(LPVOID, GUID *, struct ITabletManager **))g_pIInkManager)(
                     g_pIInkManager,
                     &IID_ITabletManager,
                     &g_pTabletManager);
              v3 = v9;
              v34 = v9;
              if ( v9 < 0 )
              {
                if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x10u, (const GUID *)qword_401630, v9);
                  v3 = v34;
                }
              }
              else
              {
                v35 = 0;
                v10 = (*(__int64 (__fastcall **)(struct ITabletManager *, unsigned int *))(*(_QWORD *)g_pTabletManager
                                                                                         + 32LL))(
                        g_pTabletManager,
                        &v35);
                v3 = v10;
                v34 = v10;
                if ( v10 >= 0 )
                {
                  v11 = 0;
                  for ( LODWORD(v36) = 0; ; LODWORD(v36) = v11 )
                  {
                    if ( v11 >= v35 || v3 < 0 )
                      goto LABEL_80;
                    v28 = 0;
                    v12 = (*(__int64 (__fastcall **)(struct ITabletManager *, _QWORD, __int64 *))(*(_QWORD *)g_pTabletManager
                                                                                                + 40LL))(
                            g_pTabletManager,
                            v11,
                            &v28);
                    v3 = v12;
                    v34 = v12;
                    if ( v12 >= 0 )
                      break;
                    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xEu, (const GUID *)qword_401630, v12);
                      v3 = v34;
                    }
LABEL_55:
                    ++v11;
                  }
                  memset(Src, 0, 32);
                  v27 = 0;
                  try
                  {
                    v13 = operator new(0x10u);
                    if ( v13 )
                    {
                      *(_QWORD *)v13 = &CSink::`vftable';
                      v13[2] = 0;
                      v13[3] = 0;
                    }
                    else
                    {
                      v13 = 0;
                    }
                    Src[0] = v13;
                  }
                  catch ( std::bad_alloc )
                  {
                    v25 = &v26;
                    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      LOWORD(v25) = 10;
                      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v25, qword_401630);
                    }
                    v34 = -2147024882;
                    v1 = this;
                    v11 = (unsigned int)v36;
                    v13 = (_DWORD *)Src[0];
                  }
                  if ( v13 )
                  {
                    (*(void (__fastcall **)(_DWORD *))(*(_QWORD *)v13 + 8LL))(v13);
                    v14 = (**(__int64 (__fastcall ***)(_QWORD, GUID *, __int64 *))Src[0])(
                            Src[0],
                            &IID_ITabletEventSink,
                            &v27);
                    v34 = v14;
                    if ( v14 >= 0 )
                      goto LABEL_25;
                    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, (const GUID *)qword_401630, v14);
                    }
                    (*(void (__fastcall **)(_QWORD))(*(_QWORD *)Src[0] + 16LL))(Src[0]);
                  }
                  if ( v34 < 0 )
                  {
LABEL_51:
                    (*(void (__fastcall **)(__int64))(*(_QWORD *)v28 + 16LL))(v28);
                    v3 = v34;
                    goto LABEL_55;
                  }
LABEL_25:
                  v36 = 0;
                  v15 = (*(__int64 (__fastcall **)(__int64, HWND, _QWORD, _QWORD, _QWORD, int, _QWORD *, _QWORD *, LPVOID *, __int64))(*(_QWORD *)v28 + 32LL))(
                          v28,
                          g_hWnd,
                          0,
                          0,
                          0,
                          1,
                          &Src[1],
                          &Src[2],
                          &v36,
                          v27);
                  v34 = v15;
                  if ( v15 < 0 )
                  {
                    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xDu, (const GUID *)qword_401630, v15);
                    }
                  }
                  else
                  {
                    v34 = (*(__int64 (__fastcall **)(__int64, LPVOID *))(*(_QWORD *)v28 + 24LL))(v28, pv);
                    if ( v34 >= 0 )
                    {
                      LODWORD(Src[3]) = *(_DWORD *)pv[0];
                      for ( i = 0; i < *((_DWORD *)pv[0] + 4); ++i )
                      {
                        v17 = (_QWORD *)(*((_QWORD *)pv[0] + 3) + 16LL * i);
                        v18 = **(_QWORD **)&GUID_BARRELDOWN.Data1 < *v17;
                        if ( **(_QWORD **)&GUID_BARRELDOWN.Data1 == *v17
                          && (v19 = *(_QWORD *)(*(_QWORD *)&GUID_BARRELDOWN.Data1 + 8LL),
                              v18 = v19 < v17[1],
                              v19 == v17[1]) )
                        {
                          v20 = 0;
                        }
                        else
                        {
                          v20 = -v18 - (v18 - 1);
                        }
                        if ( !v20 )
                          HIDWORD(Src[3]) = 1 << i;
                      }
                      CoTaskMemFree(pv[0]);
                    }
                    HIDWORD(Src[2]) = *(_DWORD *)v36;
                    v34 = (*(__int64 (__fastcall **)(struct IInkObject *, _QWORD))(*(_QWORD *)g_pIInkObject + 120LL))(
                            g_pIInkObject,
                            LODWORD(Src[2]));
                    CoTaskMemFree(v36);
                    v34 = (*(__int64 (__fastcall **)(_QWORD, _BYTE *))(*(_QWORD *)Src[1] + 112LL))(Src[1], v30);
                    v34 = (*(__int64 (__fastcall **)(struct IInkObject *, _QWORD, _BYTE *, void *))(*(_QWORD *)g_pIInkObject
                                                                                                  + 264LL))(
                            g_pIInkObject,
                            LODWORD(Src[2]),
                            v30,
                            &g_rcTabletInInk);
                    *((_DWORD *)v1 + 5) = 0;
                    *((_DWORD *)v1 + 4) = 0;
                    v21 = dword_4B9ED8;
                    if ( dword_4B9ED8 >= 0 )
                    {
                      v23 = (unsigned int)(dword_4B9ED8 + 1);
                      if ( (int)v23 >= 0 )
                      {
                        v22 = CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetSize(v23);
                        if ( v22 >= 0 )
                          memcpy((char *)g_arrTCI + 32 * v21, Src, 0x20u);
                      }
                      else
                      {
                        v22 = -2147024809;
                      }
                    }
                    else
                    {
                      v22 = -2147024809;
                    }
                    v34 = v22;
                    if ( v22 < 0
                      && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xCu, (const GUID *)qword_401630, v22);
                    }
                  }
                  if ( v27 )
                  {
                    (*(void (__fastcall **)(__int64))(*(_QWORD *)v27 + 16LL))(v27);
                    v27 = 0;
                  }
                  goto LABEL_51;
                }
                if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xFu, (const GUID *)qword_401630, v10);
                  v3 = v34;
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_80:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v31);
  return (unsigned int)v3;
}
