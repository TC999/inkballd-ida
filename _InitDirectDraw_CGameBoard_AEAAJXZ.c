// Hidden C++ exception states: #wind=2
__int64 __fastcall CGameBoard::InitDirectDraw(CGameBoard *this)
{
  CGameBoard *v1; // rsi
  unsigned int v2; // edi
  CDisplay *v3; // rax
  CDisplay *v4; // rcx
  int v5; // eax
  int WindowedDisplay; // eax
  CDisplay *v7; // rbx
  CDisplay *v8; // rbx
  __int64 v9; // rbx
  __int64 *v11; // rdx
  __int64 v12; // [rsp+0h] [rbp-308h] BYREF
  int *v13; // [rsp+28h] [rbp-2E0h]
  int v14; // [rsp+30h] [rbp-2D8h] BYREF
  int v15[2]; // [rsp+38h] [rbp-2D0h] BYREF
  _DWORD v16[2]; // [rsp+40h] [rbp-2C8h] BYREF
  _BYTE v17[16]; // [rsp+48h] [rbp-2C0h] BYREF
  __int64 v18; // [rsp+58h] [rbp-2B0h]
  _BYTE v19[16]; // [rsp+60h] [rbp-2A8h] BYREF
  WCHAR Caption[64]; // [rsp+70h] [rbp-298h] BYREF
  WCHAR Text[256]; // [rsp+F0h] [rbp-218h] BYREF

  v18 = -2;
  v1 = this;
  *(_QWORD *)v15 = this;
  v2 = 0;
  v14 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v19, "CGameBoard::InitDirectDraw", &v14);
  try
  {
    v3 = (CDisplay *)operator new(0x58u);
    if ( v3 )
      v4 = CDisplay::CDisplay(v3);
    else
      v4 = 0;
    g_pDisplay = v4;
  }
  catch ( std::bad_alloc )
  {
    v11 = &v12;
    if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LOWORD(v11) = 15;
      WPP_SF_(*((_QWORD *)WPP_GLOBAL_Control + 2), v11, qword_401928);
    }
    v14 = -2147024882;
    v2 = 0;
    v1 = *(CGameBoard **)v15;
    v4 = g_pDisplay;
  }
  v5 = v14;
  if ( !v4 )
    v5 = -2147024882;
  v14 = v5;
  if ( v5 < 0 )
    goto LABEL_16;
  WindowedDisplay = CDisplay::CreateWindowedDisplay(
                      v4,
                      *((HWND *)v1 + 1892),
                      *((_DWORD *)v1 + 3764),
                      *((_DWORD *)v1 + 3765));
  v14 = WindowedDisplay;
  if ( WindowedDisplay >= 0 )
  {
    v7 = g_pDisplay;
LABEL_15:
    v16[0] = CDisplay::ConvertGDIColor(v7, 0x10101u);
    v16[1] = CDisplay::ConvertGDIColor(g_pDisplay, 0xFFFFFFu);
    v8 = g_pDisplay;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CDisplay::GetInkBuffer", 0);
    v9 = *((_QWORD *)v8 + 5);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
    (*(void (__fastcall **)(__int64, __int64, _DWORD *))(*(_QWORD *)v9 + 232LL))(v9, 2, v16);
    v14 = 0;
    goto LABEL_20;
  }
  v7 = g_pDisplay;
  if ( g_pDisplay )
  {
    *(_QWORD *)g_pDisplay = &CDisplay::`vftable';
    v15[0] = 0;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v17, "CDisplay::~CDisplay", v15);
    v15[0] = CDisplay::DestroyObjects(v7);
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v17);
    operator delete(v7);
    v7 = 0;
    g_pDisplay = 0;
    WindowedDisplay = v14;
  }
  if ( WindowedDisplay >= 0 )
    goto LABEL_15;
LABEL_16:
  memset(Caption, 0, sizeof(Caption));
  memset(Text, 0, sizeof(Text));
  Helpers::LoadStringW(0, (HINSTANCE)0x3AA3, Caption, (unsigned __int16 *)0x40, 0, v13);
  if ( GetSystemMetrics(4096) == 1 )
    Helpers::LoadStringW(0, (HINSTANCE)0x3AAB, Text, (unsigned __int16 *)0x100, 0, v13);
  else
    Helpers::LoadStringW(0, (HINSTANCE)0x3AA5, Text, (unsigned __int16 *)0x100, 0, v13);
  MessageBoxW(*((HWND *)v1 + 1892), Text, Caption, 0x10u);
  v2 = v14;
LABEL_20:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v19);
  return v2;
}
