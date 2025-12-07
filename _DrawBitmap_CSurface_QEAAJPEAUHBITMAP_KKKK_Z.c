// Hidden C++ exception states: #wind=1
__int64 __fastcall CSurface::DrawBitmap(CSurface *this, HDC a2)
{
  int v4; // ebx
  HDC hdcSrc; // rbx
  signed int LastError; // eax
  unsigned int v8; // r9d
  int *v9; // r9
  int wSrc; // esi
  int hSrc; // ebp
  int v12; // eax
  int v13; // eax
  signed int v14; // eax
  unsigned int v15; // r9d
  unsigned int v16; // ebx
  signed int v17; // eax
  int *hDest; // [rsp+20h] [rbp-148h]
  int v19; // [rsp+60h] [rbp-108h] BYREF
  int v20; // [rsp+64h] [rbp-104h] BYREF
  HDC hdcDest; // [rsp+68h] [rbp-100h] BYREF
  _BYTE v22[16]; // [rsp+70h] [rbp-F8h] BYREF
  _BYTE v23[16]; // [rsp+80h] [rbp-E8h] BYREF
  __int64 v24; // [rsp+90h] [rbp-D8h]
  int v25[10]; // [rsp+98h] [rbp-D0h] BYREF
  _DWORD v26[36]; // [rsp+C0h] [rbp-A8h] BYREF
  unsigned int v27; // [rsp+178h] [rbp+10h] BYREF

  v24 = -2;
  v27 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v23, "CSurface::DrawBitmap", (int *)&v27);
  if ( a2 && *(_QWORD *)this )
  {
    v4 = (*(__int64 (__fastcall **)(_QWORD))(**(_QWORD **)this + 216LL))(*(_QWORD *)this);
    v27 = v4;
    if ( v4 < 0 )
    {
LABEL_6:
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v23);
      return (unsigned int)v4;
    }
    v26[0] = 136;
    (*(void (__fastcall **)(_QWORD, _DWORD *))(**(_QWORD **)this + 176LL))(*(_QWORD *)this, v26);
    if ( v26[21] == 4 )
    {
      v4 = -2147467263;
      v27 = -2147467263;
      goto LABEL_6;
    }
    v19 = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v22, "Helpers::CreateCompatibleDC", &v19);
    hdcSrc = CreateCompatibleDC(0);
    if ( !hdcSrc )
    {
      LastError = GetLastError();
      v8 = (unsigned __int16)LastError | 0x80070000;
      if ( LastError <= 0 )
        v8 = LastError;
      v19 = v8;
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x14u, &stru_4015E0, v8);
    }
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v22);
    if ( hdcSrc )
    {
      Helpers::SelectObject(hdcSrc, a2, 0, v9);
      Helpers::GetObjectW(a2, (void *)0x20, (int)v25, 0, hDest);
      wSrc = v25[1];
      hSrc = v25[2];
      v12 = (*(__int64 (__fastcall **)(_QWORD, HDC *))(**(_QWORD **)this + 136LL))(*(_QWORD *)this, &hdcDest);
      v27 = v12;
      if ( v12 < 0 )
      {
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x27u, (const GUID *)qword_401610, v12);
      }
      else
      {
        StretchBlt(hdcDest, 0, 0, v26[3], v26[2], hdcSrc, 0, 0, wSrc, hSrc, 0xCC0020u);
        v13 = (*(__int64 (__fastcall **)(_QWORD, HDC))(**(_QWORD **)this + 208LL))(*(_QWORD *)this, hdcDest);
        v27 = v13;
        if ( v13 < 0
          && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x26u, (const GUID *)qword_401610, v13);
        }
      }
      v20 = 0;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v22, "Helpers::DeleteDC", &v20);
      if ( !DeleteDC(hdcSrc) )
      {
        v14 = GetLastError();
        v15 = (unsigned __int16)v14 | 0x80070000;
        if ( v14 <= 0 )
          v15 = v14;
        v20 = v15;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xFu, &stru_4015E0, v15);
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v22);
      v16 = v27;
    }
    else
    {
      v17 = GetLastError();
      v16 = (unsigned __int16)v17 | 0x80070000;
      if ( v17 <= 0 )
        v16 = v17;
      v27 = v16;
    }
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v23);
    return v16;
  }
  else
  {
    v27 = -2147024809;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v23);
    return 2147942487LL;
  }
}
