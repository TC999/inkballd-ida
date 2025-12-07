void __fastcall Helpers::CLogBlock::~CLogBlock(const char **this)
{
  const char *v1; // rax
  __int64 v3; // rdx
  const signed __int32 *v4; // rcx
  char v5[4]; // [rsp+20h] [rbp-18h]

  v1 = *this;
  if ( !*this )
    goto LABEL_6;
  v3 = *(unsigned int *)v1;
  if ( (int)v3 >= 0 )
    goto LABEL_6;
  v4 = (const signed __int32 *)WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == (_UNKNOWN *)&WPP_GLOBAL_Control )
    return;
  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    *(_DWORD *)v5 = *(_DWORD *)v1;
    LOWORD(v3) = 11;
    WPP_SF_sL(*((_QWORD *)WPP_GLOBAL_Control + 2), v3, (__int64)&stru_4015E0, this[1], *(_DWORD *)v5);
LABEL_6:
    v4 = (const signed __int32 *)WPP_GLOBAL_Control;
  }
  if ( v4 != (const signed __int32 *)&WPP_GLOBAL_Control )
  {
    if ( _bittest(v4 + 7, 0xAu) )
      WPP_SF_s(*((_QWORD *)v4 + 2), 0xCu, (__int64)&stru_4015E0, this[1]);
  }
}
