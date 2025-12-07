struct CBoardTile *__fastcall CGameBoard::GetTile(CGameBoard *this, int a2, int a3)
{
  __int64 v6; // rbx
  _BYTE v8[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CGameBoard::GetTile", 0);
  v6 = *((_QWORD *)this
       + (a2 - *((_DWORD *)this + 3766)) / *((_DWORD *)this + 3771)
       + *((int *)this + 3768) * (__int64)((a3 - *((_DWORD *)this + 3767)) / *((_DWORD *)this + 3771))
       + 721);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return (struct CBoardTile *)v6;
}
