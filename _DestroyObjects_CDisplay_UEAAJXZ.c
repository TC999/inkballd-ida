// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::DestroyObjects(CDisplay *this)
{
  __int64 v2; // rcx
  __int64 v3; // rcx
  __int64 v4; // rcx
  __int64 v5; // rcx
  __int64 v6; // rcx
  __int64 v7; // rcx
  int v8; // edi
  __int64 v9; // rcx
  _BYTE v11[32]; // [rsp+28h] [rbp-20h] BYREF
  int v12; // [rsp+50h] [rbp+8h] BYREF

  v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::DestroyObjects", &v12);
  v2 = *((_QWORD *)this + 6);
  if ( v2 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v2 + 16LL))(v2);
    *((_QWORD *)this + 6) = 0;
  }
  v3 = *((_QWORD *)this + 5);
  if ( v3 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v3 + 16LL))(v3);
    *((_QWORD *)this + 5) = 0;
  }
  v4 = *((_QWORD *)this + 4);
  if ( v4 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v4 + 16LL))(v4);
    *((_QWORD *)this + 4) = 0;
  }
  v5 = *((_QWORD *)this + 3);
  if ( v5 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v5 + 16LL))(v5);
    *((_QWORD *)this + 3) = 0;
  }
  v6 = *((_QWORD *)this + 2);
  if ( v6 )
  {
    (*(void (__fastcall **)(__int64))(*(_QWORD *)v6 + 16LL))(v6);
    *((_QWORD *)this + 2) = 0;
  }
  v7 = *((_QWORD *)this + 1);
  if ( v7 )
  {
    v8 = (*(__int64 (__fastcall **)(__int64, _QWORD, __int64))(*(_QWORD *)v7 + 160LL))(v7, *((_QWORD *)this + 7), 8);
    v12 = v8;
    if ( v8 < 0
      && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
      && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, (const GUID *)qword_401610, v8);
      v8 = v12;
    }
    v9 = *((_QWORD *)this + 1);
    if ( v9 )
    {
      (*(void (__fastcall **)(__int64))(*(_QWORD *)v9 + 16LL))(v9);
      *((_QWORD *)this + 1) = 0;
      v8 = v12;
    }
  }
  else
  {
    v8 = v12;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return (unsigned int)v8;
}
