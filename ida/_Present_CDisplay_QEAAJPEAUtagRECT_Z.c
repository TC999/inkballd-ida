// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::Present(CDisplay *this, struct tagRECT *a2)
{
  CDisplay *v3; // rdi
  unsigned int v4; // ebx
  int v5; // eax
  __int64 v7; // [rsp+30h] [rbp-58h]
  int v8; // [rsp+38h] [rbp-50h] BYREF
  int v9; // [rsp+3Ch] [rbp-4Ch]
  int v10; // [rsp+40h] [rbp-48h]
  int v11; // [rsp+44h] [rbp-44h]
  struct tagRECT rcDst; // [rsp+48h] [rbp-40h] BYREF
  RECT rcSrc; // [rsp+58h] [rbp-30h] BYREF
  _BYTE v14[32]; // [rsp+68h] [rbp-20h] BYREF
  int v15; // [rsp+90h] [rbp+8h] BYREF
  int v16; // [rsp+94h] [rbp+Ch]

  v16 = HIDWORD(this);
  v7 = -2;
  v3 = g_pDisplay;
  v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CDisplay::Present", &v15);
  if ( *((_QWORD *)v3 + 2) && *((_QWORD *)v3 + 3) )
  {
    if ( a2 )
    {
      if ( *((_DWORD *)v3 + 20) )
      {
        CopyRect(&rcDst, a2);
        OffsetRect(&rcDst, *((_DWORD *)v3 + 16), *((_DWORD *)v3 + 17));
        IntersectRect(&rcSrc, &rcDst, (const RECT *)v3 + 4);
        CopyRect(&rcDst, &rcSrc);
        OffsetRect(&rcDst, -*((_DWORD *)v3 + 16), -*((_DWORD *)v3 + 17));
        v8 = *((_DWORD *)v3 + 16) + (int)((double)rcDst.left / dSizeFactor);
        v9 = *((_DWORD *)v3 + 17) + (int)((double)rcDst.top / dSizeFactor);
        v10 = v8 + (int)((double)(rcSrc.right - rcSrc.left) / dSizeFactor);
        v11 = v9 + (int)((double)(rcSrc.bottom - rcSrc.top) / dSizeFactor);
        v4 = (*(__int64 (__fastcall **)(_QWORD, int *, _QWORD, struct tagRECT *, int, _QWORD, __int64))(**((_QWORD **)v3 + 2) + 40LL))(
               *((_QWORD *)v3 + 2),
               &v8,
               *((_QWORD *)v3 + 3),
               &rcDst,
               0x1000000,
               0,
               -2);
        v15 = v4;
      }
      else
      {
        v4 = -2147467263;
        v15 = -2147467263;
      }
    }
    else
    {
      while ( 1 )
      {
        if ( *((_DWORD *)v3 + 20) )
        {
          v8 = *((_DWORD *)v3 + 16);
          v9 = *((_DWORD *)v3 + 17);
          v10 = v8 + (int)((double)(*((_DWORD *)v3 + 18) - v8) / dSizeFactor);
          v11 = v9 + (int)((double)(*((_DWORD *)v3 + 19) - v9) / dSizeFactor);
          v5 = (*(__int64 (__fastcall **)(_QWORD, int *, _QWORD, _QWORD, int, _QWORD, __int64))(**((_QWORD **)v3 + 2)
                                                                                              + 40LL))(
                 *((_QWORD *)v3 + 2),
                 &v8,
                 *((_QWORD *)v3 + 3),
                 0,
                 0x1000000,
                 0,
                 v7);
        }
        else
        {
          v5 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))(**((_QWORD **)v3 + 2) + 88LL))(
                 *((_QWORD *)v3 + 2),
                 0,
                 0);
        }
        v4 = v5;
        v15 = v5;
        if ( v5 == -2005532222 )
          break;
        if ( v5 != -2005532132 )
          goto LABEL_15;
      }
      v4 = -2005532222;
    }
  }
  else
  {
    v4 = -2147467261;
    v15 = -2147467261;
  }
LABEL_15:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
  return v4;
}
