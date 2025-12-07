__int64 __fastcall _GSHandlerCheck_EH(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // rbx
  int v9; // r11d
  unsigned int v10; // r8d

  v4 = *(_QWORD *)(a4 + 56);
  _GSHandlerCheckCommon(a2, a4);
  v9 = *(_DWORD *)(v4 + 4) & 2;
  v10 = 1;
  if ( (*(_DWORD *)(a1 + 4) & 0x66) == 0 )
    v9 = *(_DWORD *)(v4 + 4) & 1;
  if ( v9 )
    return (unsigned int)_CxxFrameHandler3(a1, a2, a3, a4);
  return v10;
}
