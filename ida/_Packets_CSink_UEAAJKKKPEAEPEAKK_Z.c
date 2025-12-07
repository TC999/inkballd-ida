__int64 __fastcall CSink::Packets(
        CSink *this,
        int a2,
        __int64 a3,
        unsigned int a4,
        unsigned __int8 *a5,
        unsigned int *a6,
        unsigned int a7)
{
  unsigned int v9; // edi
  __int64 v11; // rbx
  int v13; // [rsp+20h] [rbp-38h] BYREF
  HDC v14; // [rsp+28h] [rbp-30h] BYREF
  _BYTE v15[16]; // [rsp+30h] [rbp-28h] BYREF
  _BYTE v16[24]; // [rsp+40h] [rbp-18h] BYREF

  v9 = 0;
  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CSink::Packets", &v13);
  if ( (unsigned int)AcceptInkInput() && g_tcid == a2 && g_cid == a7 && *((_DWORD *)this + 3) )
  {
    v11 = *((_QWORD *)g_pCGameBoard + 1893);
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "CInk::SetInkModifiedFlag", 0);
    *(_DWORD *)(v11 + 16) = 1;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
    v13 = (*(__int64 (__fastcall **)(struct IInkCollect *, _QWORD, _QWORD, unsigned __int8 *))(*(_QWORD *)g_pIInkCollect
                                                                                             + 32LL))(
            g_pIInkCollect,
            a7,
            a4,
            a5);
    if ( v13 >= 0 )
    {
      GetInkBufferHDC(&v14);
      v13 = (*(__int64 (__fastcall **)(struct IRenderingContext *, _QWORD, HDC))(*(_QWORD *)g_pIRenderingContext + 72LL))(
              g_pIRenderingContext,
              a7,
              v14);
      ReleaseInkBufferHDC(v14);
    }
    else
    {
      v9 = -2147467259;
    }
  }
  v13 = v9;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  return v9;
}
