__int64 __fastcall WinInit(HINSTANCE a1, __int64 a2, HWND *a3, HACCEL *a4)
{
  unsigned int v6; // ebx
  int *v8; // r9
  int *v9; // r9
  HICON IconW; // rax
  HCURSOR CursorW; // rdi
  signed int LastError; // eax
  unsigned int v13; // r9d
  signed int v14; // eax
  unsigned int v15; // r9d
  HACCEL AcceleratorsW; // rdi
  signed int v17; // eax
  unsigned int v18; // r9d
  HWND Window; // rax
  int *v21; // [rsp+28h] [rbp-320h]
  int *v22; // [rsp+68h] [rbp-2E0h]
  int v23; // [rsp+70h] [rbp-2D8h] BYREF
  int v24; // [rsp+74h] [rbp-2D4h] BYREF
  struct tagRECT Rect; // [rsp+78h] [rbp-2D0h] BYREF
  _BYTE v26[24]; // [rsp+88h] [rbp-2C0h] BYREF
  WNDCLASSEXW v27; // [rsp+A0h] [rbp-2A8h] BYREF
  _BYTE v28[16]; // [rsp+F0h] [rbp-258h] BYREF
  WCHAR Buffer[256]; // [rsp+100h] [rbp-248h] BYREF

  v6 = 0;
  v23 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v26, "WinInit", &v23);
  v27.cbSize = 80;
  v27.lpszClassName = g_szAppName;
  v27.lpfnWndProc = (WNDPROC)MainWndProc;
  v27.style = 3;
  v27.hInstance = a1;
  v27.hIcon = Helpers::LoadIconW(a1, (HINSTANCE)0x65, 0, v8);
  IconW = Helpers::LoadIconW(a1, (HINSTANCE)0x65, 0, v9);
  v24 = 0;
  v27.hIconSm = IconW;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v28, "Helpers::LoadCursorW", &v24);
  CursorW = LoadCursorW(0, (LPCWSTR)0x7F77);
  if ( !CursorW )
  {
    LastError = GetLastError();
    v13 = (unsigned __int16)LastError | 0x80070000;
    if ( LastError <= 0 )
      v13 = LastError;
    v24 = v13;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Fu, &stru_4015E0, v13);
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v28);
  v27.hCursor = CursorW;
  v27.hbrBackground = (HBRUSH)6;
  v27.lpszMenuName = (LPCWSTR)102;
  v27.cbClsExtra = 0;
  v27.cbWndExtra = 0;
  if ( RegisterClassExW(&v27) )
  {
    AcceleratorsW = LoadAcceleratorsW(a1, (LPCWSTR)0x67);
    if ( !AcceleratorsW
      && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v17 = GetLastError();
      v18 = (unsigned __int16)v17 | 0x80070000;
      if ( v17 <= 0 )
        v18 = v17;
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, (const GUID *)qword_4015F0, v18);
    }
    Helpers::LoadStringW(0, (HINSTANCE)0x3A98, Buffer, (unsigned __int16 *)0x100, 0, v21);
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = 544;
    Rect.bottom = 586;
    AdjustWindowRectEx(&Rect, 0xCA0000u, 1, 0);
    Window = Helpers::CreateWindowExW(
               0,
               (unsigned int)g_szAppName,
               Buffer,
               (const unsigned __int16 *)0xCA0000,
               0x80000000,
               0x80000000,
               Rect.right - Rect.left,
               Rect.bottom - Rect.top,
               0,
               0,
               (HMENU)a1,
               0,
               0,
               v22);
    if ( Window )
    {
      *a3 = Window;
      *a4 = AcceleratorsW;
      goto LABEL_22;
    }
  }
  else if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v14 = GetLastError();
    v15 = (unsigned __int16)v14 | 0x80070000;
    if ( v14 <= 0 )
      v15 = v14;
    WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (const GUID *)qword_4015F0, v15);
  }
  v6 = -2147467259;
LABEL_22:
  v23 = v6;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v26);
  return v6;
}
