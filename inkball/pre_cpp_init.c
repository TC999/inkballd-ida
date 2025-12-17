__int64 pre_cpp_init()
{
  __int64 result; // rax

  dword_464B0C = newmode;
  result = __wgetmainargs(&unk_464AF0, &unk_464B00, &unk_464AF8, (unsigned int)dowildcard, &dword_464B0C);
  dword_464B08 = result;
  return result;
}
