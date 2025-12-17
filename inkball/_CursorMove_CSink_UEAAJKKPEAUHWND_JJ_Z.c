__int64 __fastcall CSink::CursorMove(CSink *this, __int64 a2, __int64 a3, HWND a4)
{
  unsigned int v4; // ebx
  int v6; // [rsp+20h] [rbp-28h] BYREF
  _BYTE v7[32]; // [rsp+28h] [rbp-20h] BYREF

  v6 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CSink::CursorMove", &v6);
  v4 = v6;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v4;
}
