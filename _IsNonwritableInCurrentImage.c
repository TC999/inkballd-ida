_BOOL8 __fastcall IsNonwritableInCurrentImage(__int64 a1, __int64 a2)
{
  __int64 v2; // rcx
  __int64 v3; // r8
  __int64 PESection; // rax

  if ( !(unsigned int)ValidateImageBase(0x400000, a2, a1) )
    return 0;
  PESection = FindPESection(v2, v3 - v2);
  return PESection && *(int *)(PESection + 36) >= 0;
}
