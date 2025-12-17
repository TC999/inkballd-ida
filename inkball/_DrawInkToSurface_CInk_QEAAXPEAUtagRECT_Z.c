// Hidden C++ exception states: #wind=1
void __fastcall CInk::DrawInkToSurface(CInk *this, struct tagRECT *a2)
{
  _BYTE v2[32]; // [rsp+38h] [rbp-20h] BYREF
  int v3; // [rsp+68h] [rbp+10h] BYREF
  int v4; // [rsp+6Ch] [rbp+14h]
  HDC v5; // [rsp+70h] [rbp+18h] BYREF

  v4 = HIDWORD(a2);
  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CInk::DrawInkToSurface", &v3);
  GetInkBufferHDC(&v5);
  v3 = (*(__int64 (__fastcall **)(struct IRenderInk *, HDC, void *, struct HWND__ *, _QWORD))(*(_QWORD *)g_pIRenderInk
                                                                                            + 32LL))(
         g_pIRenderInk,
         v5,
         &g_rcInkSpace,
         &g_rcClient,
         0);
  ReleaseInkBufferHDC(v5);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
