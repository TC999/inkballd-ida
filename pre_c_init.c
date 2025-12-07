// write access to const memory has been detected, the output may be wrong!
__int64 pre_c_init()
{
  int v0; // eax
  int v1; // eax
  bool v2; // zf
  _crt_app_type image_app_type; // eax

  if ( LOWORD(MEMORY[0x400000].unused) != 23117 || *(_DWORD *)(MEMORY[0x40003C] + 0x400000LL) != 17744 )
    goto LABEL_2;
  v1 = *(unsigned __int16 *)(MEMORY[0x40003C] + 0x400018LL);
  if ( v1 != 267 )
  {
    if ( v1 == 523 )
    {
      v0 = 0;
      if ( *(_DWORD *)(MEMORY[0x40003C] + 0x400084LL) <= 0xEu )
        goto LABEL_11;
      v2 = *(_DWORD *)(MEMORY[0x40003C] + 0x4000F8LL) == 0;
      goto LABEL_10;
    }
LABEL_2:
    v0 = 0;
    goto LABEL_11;
  }
  v0 = 0;
  if ( *(_DWORD *)(MEMORY[0x40003C] + 0x400074LL) <= 0xEu )
    goto LABEL_11;
  v2 = *(_DWORD *)(MEMORY[0x40003C] + 0x4000E8LL) == 0;
LABEL_10:
  LOBYTE(v0) = !v2;
LABEL_11:
  dword_464AF4 = v0;
  image_app_type = (unsigned int)get_image_app_type(2);
  __set_app_type(image_app_type);
  _onexitend = -1;
  _onexitbegin = -1;
  _fmode = fmode;
  _commode = commode;
  matherr(*(struct _exception **)&_commode);
  if ( !_defaultmatherr )
    __setusermatherr(matherr);
  return 0;
}
