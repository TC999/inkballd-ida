void __fastcall CBoardTileChevron::DeflectBall(CBoardTileChevron *this, struct CBall *a2)
{
  int v4; // r11d
  double v5; // xmm6_8
  double v6; // xmm6_8
  _BYTE v7[16]; // [rsp+20h] [rbp-38h] BYREF
  _BYTE v8[16]; // [rsp+30h] [rbp-28h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBoardTileChevron::DeflectBall", 0);
  v4 = *((_DWORD *)this + 24);
  switch ( v4 )
  {
    case 0:
      v5 = *((double *)a2 + 10) - 3.0;
      goto LABEL_3;
    case 1:
      v5 = *((double *)a2 + 10) + 3.0;
LABEL_3:
      *((double *)a2 + 10) = v5;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBall::SetYVel", 0);
      if ( COERCE_DOUBLE(*(_QWORD *)&v5 & _mask__AbsDouble_) > 400.0 )
        *((double *)a2 + 10) = *((double *)a2 + 10) / COERCE_DOUBLE(*((_QWORD *)a2 + 10) & _mask__AbsDouble_) * 400.0;
      else
        *((double *)a2 + 10) = v5;
LABEL_15:
      Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
      break;
    case 2:
      v6 = *((double *)a2 + 9) - 3.0;
      goto LABEL_12;
    case 3:
      v6 = *((double *)a2 + 9) + 3.0;
LABEL_12:
      *((double *)a2 + 9) = v6;
      Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBall::SetXVel", 0);
      if ( COERCE_DOUBLE(*(_QWORD *)&v6 & _mask__AbsDouble_) > 400.0 )
        *((double *)a2 + 9) = *((double *)a2 + 9) / COERCE_DOUBLE(*((_QWORD *)a2 + 9) & _mask__AbsDouble_) * 400.0;
      else
        *((double *)a2 + 9) = v6;
      goto LABEL_15;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
