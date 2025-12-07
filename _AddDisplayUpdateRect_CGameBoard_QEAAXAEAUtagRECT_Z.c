void __fastcall CGameBoard::AddDisplayUpdateRect(CGameBoard *this, struct tagRECT *a2)
{
  __int64 v4; // rax
  _BYTE v5[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::AddDisplayUpdateRect", 0);
  v4 = *((int *)this + 2028);
  if ( (unsigned int)v4 < 0x121 )
  {
    *((_DWORD *)this + 4 * v4 + 2029) = a2->left;
    *((_DWORD *)this + 4 * *((int *)this + 2028) + 2031) = a2->right;
    *((_DWORD *)this + 4 * *((int *)this + 2028) + 2030) = a2->top;
    *((_DWORD *)this + 4 * (*((_DWORD *)this + 2028))++ + 2032) = a2->bottom;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
