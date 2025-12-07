__int64 __fastcall GetGoldVersionOfTile(int a1)
{
  unsigned int v2; // ebx
  _BYTE v4[24]; // [rsp+20h] [rbp-18h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "GetGoldVersionOfTile", 0);
  switch ( a1 )
  {
    case 17:
    case 21:
    case 25:
    case 29:
    case 33:
      v2 = 33;
      break;
    case 18:
    case 22:
    case 26:
    case 30:
    case 34:
      v2 = 34;
      break;
    case 19:
    case 23:
    case 27:
    case 31:
    case 35:
      v2 = 35;
      break;
    case 20:
    case 24:
    case 28:
    case 32:
    case 36:
      v2 = 36;
      break;
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
      v2 = 46;
      break;
    default:
      v2 = 41;
      break;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
