__int64 StringCchPrintfExW(
        unsigned __int16 *a1,
        unsigned __int64 a2,
        unsigned __int16 **a3,
        unsigned __int64 *a4,
        unsigned int a5,
        wchar_t *Format,
        ...)
{
  int v6; // edi
  unsigned __int16 *v10; // r13
  unsigned __int64 v11; // rbp
  const wchar_t *v12; // r8
  size_t v13; // r8
  unsigned __int64 v14; // r12
  unsigned __int64 v15; // rbx
  int v16; // eax
  va_list Args; // [rsp+A0h] [rbp+38h] BYREF

  va_start(Args, Format);
  v6 = 0;
  if ( (a5 & 0x100) != 0 )
  {
    if ( a1 || !a2 )
    {
LABEL_6:
      if ( a2 <= 0x7FFFFFFF )
        goto LABEL_8;
    }
  }
  else if ( a2 )
  {
    goto LABEL_6;
  }
  v6 = -2147024809;
LABEL_8:
  if ( v6 < 0 )
    return (unsigned int)v6;
  v10 = a1;
  v11 = a2;
  if ( (a5 & 0x100) != 0 )
  {
    v12 = (const wchar_t *)&qword_401ED8;
    if ( Format )
      v12 = Format;
  }
  else
  {
    v12 = Format;
  }
  v6 = 0;
  if ( (a5 & 0xFFFFE000) != 0 )
  {
    v6 = -2147024809;
    if ( a2 )
      *a1 = 0;
LABEL_17:
    if ( (a5 & 0x1C00) != 0 && a2 )
    {
      v13 = 2 * a2;
      v14 = (2 * a2) >> 1;
      if ( v14 && (a5 & 0x1000) != 0 )
      {
        *a1 = 0;
        v10 = a1;
        v11 = v14;
      }
      if ( (a5 & 0x400) != 0 )
      {
        memset(a1, (unsigned __int8)a5, v13);
        if ( (_BYTE)a5 )
        {
          if ( !v14 )
            goto LABEL_44;
          v10 = &a1[v14 - 1];
          v11 = 1;
          *v10 = 0;
        }
        else
        {
          v10 = a1;
          v11 = v14;
        }
      }
      if ( v14 && (a5 & 0x800) != 0 )
      {
        *a1 = 0;
        v10 = a1;
        v11 = v14;
      }
    }
LABEL_44:
    if ( v6 < 0 && v6 != -2147024774 )
      return (unsigned int)v6;
    goto LABEL_46;
  }
  if ( a2 )
  {
    v15 = a2 - 1;
    v16 = _vsnwprintf(a1, a2 - 1, v12, Args);
    if ( v16 < 0 || v16 > v15 )
    {
      a1[v15] = 0;
      v6 = -2147024774;
    }
    else if ( v16 == v15 )
    {
      a1[v15] = 0;
    }
    else
    {
      v15 = v16;
    }
    v11 -= v15;
    v10 = &a1[v15];
    if ( v6 < 0 )
      goto LABEL_17;
    if ( (a5 & 0x200) != 0 && v11 > 1 && 2 * v11 > 2 )
      memset(v10 + 1, (unsigned __int8)a5, 2 * v11 - 2);
  }
  else if ( *v12 )
  {
    v6 = a1 != 0 ? -2147024774 : -2147024809;
    goto LABEL_17;
  }
LABEL_46:
  if ( a3 )
    *a3 = v10;
  if ( a4 )
    *a4 = v11;
  return (unsigned int)v6;
}
