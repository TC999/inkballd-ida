// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::CreateWindowedDisplay(LPVOID *this, HWND hWnd, int xRight, int yBottom)
{
  HRESULT v8; // eax
  unsigned int v9; // ebx
  int v10; // eax
  LONG WindowLongW; // edi
  BOOL v12; // ebx
  LONG v13; // eax
  signed int LastError; // eax
  unsigned int v15; // r9d
  signed int v16; // eax
  unsigned int v17; // r9d
  unsigned __int64 left; // r8
  LONG top; // r9d
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int *v28; // [rsp+40h] [rbp-128h] BYREF
  tagRECT rc; // [rsp+48h] [rbp-120h] BYREF
  __int64 v30; // [rsp+58h] [rbp-110h] BYREF
  LONG pvParam; // [rsp+60h] [rbp-108h] BYREF
  int Y; // [rsp+64h] [rbp-104h]
  _BYTE v33[16]; // [rsp+70h] [rbp-F8h] BYREF
  _BYTE v34[16]; // [rsp+80h] [rbp-E8h] BYREF
  __int64 v35; // [rsp+90h] [rbp-D8h]
  _DWORD v36[50]; // [rsp+A0h] [rbp-C8h] BYREF
  HRESULT v37; // [rsp+170h] [rbp+8h] BYREF
  int v38; // [rsp+180h] [rbp+18h]

  v38 = xRight;
  v35 = -2;
  v37 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v34, "CDisplay::CreateWindowedDisplay", &v37);
  (*(void (__fastcall **)(LPVOID *))*this)(this);
  v8 = DirectDrawCreateEx(0, this + 1, &IID_IDirectDraw7, 0);
  v9 = v8;
  v37 = v8;
  if ( v8 < 0 )
  {
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x18u, (const GUID *)qword_401610, v8);
      v9 = v37;
    }
  }
  else
  {
    v10 = (*(__int64 (__fastcall **)(LPVOID, HWND, __int64))(*(_QWORD *)this[1] + 160LL))(this[1], hWnd, 8);
    v9 = v10;
    v37 = v10;
    if ( v10 < 0 )
    {
      if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x17u, (const GUID *)qword_401610, v10);
        v9 = v37;
      }
    }
    else
    {
      SetRect(&rc, 0, 0, xRight, yBottom);
      WindowLongW = GetWindowLongW(hWnd, -20);
      v12 = GetMenu(hWnd) != 0;
      v13 = GetWindowLongW(hWnd, -16);
      AdjustWindowRectEx(&rc, v13, v12, WindowLongW);
      Helpers::SetWindowPos(hWnd, 0, 0, 0, rc.right - rc.left, rc.bottom - rc.top, 0x16u, 0, v28);
      Helpers::SetWindowPos(hWnd, (HWND)0xFFFFFFFFFFFFFFFELL, 0, 0, 0, 0, 0x13u, 0, v28);
      LODWORD(v28) = 0;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "Helpers::SystemParametersInfoW", (int *)&v28);
      if ( !SystemParametersInfoW(0x30u, 0, &pvParam, 0) )
      {
        LastError = GetLastError();
        v15 = (unsigned __int16)LastError | 0x80070000;
        if ( LastError <= 0 )
          v15 = LastError;
        LODWORD(v28) = v15;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x4Eu, &stru_4015E0, v15);
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
      LODWORD(v28) = 0;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v33, "Helpers::GetWindowRect", (int *)&v28);
      if ( !GetWindowRect(hWnd, &rc) )
      {
        v16 = GetLastError();
        v17 = (unsigned __int16)v16 | 0x80070000;
        if ( v16 <= 0 )
          v17 = v16;
        LODWORD(v28) = v17;
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x21u, &stru_4015E0, v17);
      }
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v33);
      left = (unsigned int)rc.left;
      if ( rc.left < pvParam )
        left = (unsigned int)pvParam;
      rc.left = left;
      top = rc.top;
      if ( rc.top < Y )
        top = Y;
      rc.top = top;
      Helpers::SetWindowPos(hWnd, 0, (HWND)left, top, 0, 0, 0x15u, 0, v28);
      memset(v36, 0, 0x88u);
      v36[0] = 136;
      v36[1] = 1;
      v36[28] = 512;
      v20 = (*(__int64 (__fastcall **)(LPVOID, _DWORD *, char *, _QWORD))(*(_QWORD *)this[1] + 48LL))(
              this[1],
              v36,
              (char *)this + 16,
              0);
      v9 = v20;
      v37 = v20;
      if ( v20 < 0 )
      {
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x16u, (const GUID *)qword_401610, v20);
          v9 = v37;
        }
      }
      else
      {
        v36[1] = 7;
        v36[28] = 64;
        v36[3] = v38;
        v36[2] = yBottom;
        if ( (unsigned int)fPortraitMode() )
          v36[28] |= 0x800u;
        v21 = (*(__int64 (__fastcall **)(LPVOID, _DWORD *, char *, _QWORD))(*(_QWORD *)this[1] + 48LL))(
                this[1],
                v36,
                (char *)this + 24,
                0);
        v9 = v21;
        v37 = v21;
        if ( v21 < 0 )
        {
          if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x15u, (const GUID *)qword_401610, v21);
            v9 = v37;
          }
        }
        else
        {
          v22 = (*(__int64 (__fastcall **)(LPVOID, _DWORD *, char *, _QWORD))(*(_QWORD *)this[1] + 48LL))(
                  this[1],
                  v36,
                  (char *)this + 40,
                  0);
          v9 = v22;
          v37 = v22;
          if ( v22 < 0 )
          {
            if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x14u, (const GUID *)qword_401610, v22);
              v9 = v37;
            }
          }
          else
          {
            v23 = (*(__int64 (__fastcall **)(LPVOID, _DWORD *, char *, _QWORD))(*(_QWORD *)this[1] + 48LL))(
                    this[1],
                    v36,
                    (char *)this + 48,
                    0);
            v9 = v23;
            v37 = v23;
            if ( v23 < 0 )
            {
              if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x13u, (const GUID *)qword_401610, v23);
                v9 = v37;
              }
            }
            else
            {
              v24 = (*(__int64 (__fastcall **)(LPVOID, _QWORD, __int64 *, _QWORD))(*(_QWORD *)this[1] + 32LL))(
                      this[1],
                      0,
                      &v30,
                      0);
              v9 = v24;
              v37 = v24;
              if ( v24 < 0 )
              {
                if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                  && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                {
                  WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x12u, (const GUID *)qword_401610, v24);
                  v9 = v37;
                }
              }
              else
              {
                v25 = (*(__int64 (__fastcall **)(__int64, _QWORD, HWND))(*(_QWORD *)v30 + 64LL))(v30, 0, hWnd);
                v37 = v25;
                if ( v25 < 0 )
                {
                  if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                    && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  {
                    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x11u, (const GUID *)qword_401610, v25);
                  }
                }
                else
                {
                  v26 = (*(__int64 (__fastcall **)(LPVOID, __int64))(*(_QWORD *)this[2] + 224LL))(this[2], v30);
                  v37 = v26;
                  if ( v26 < 0 )
                  {
                    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    {
                      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x10u, (const GUID *)qword_401610, v26);
                    }
                  }
                  else
                  {
                    this[7] = hWnd;
                    *((_DWORD *)this + 20) = 1;
                    CDisplay::UpdateBounds((CDisplay *)this);
                  }
                }
                (*(void (__fastcall **)(__int64))(*(_QWORD *)v30 + 16LL))(v30);
                v9 = v37;
              }
            }
          }
        }
      }
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v34);
  return v9;
}
