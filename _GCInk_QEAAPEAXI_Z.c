// Hidden C++ exception states: #wind=3
CInk *__fastcall CInk::`scalar deleting destructor'(CInk *this)
{
  _BYTE v3[16]; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v4[16]; // [rsp+38h] [rbp-30h] BYREF
  _BYTE v5[32]; // [rsp+48h] [rbp-20h] BYREF

  *(_QWORD *)this = &CInk::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CInk::~CInk", 0);
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CInk::Cleanup", 0);
  if ( g_pTabletManager )
    (*(void (__fastcall **)(struct ITabletManager *))(*(_QWORD *)g_pTabletManager + 16LL))(g_pTabletManager);
  g_pTabletManager = 0;
  CleanupTabletContexts();
  if ( g_pIInkObject )
    (*(void (__fastcall **)(struct IInkObject *))(*(_QWORD *)g_pIInkObject + 16LL))(g_pIInkObject);
  g_pIInkObject = 0;
  if ( g_pIInkCollect )
    (*(void (__fastcall **)(struct IInkCollect *))(*(_QWORD *)g_pIInkCollect + 16LL))(g_pIInkCollect);
  g_pIInkCollect = 0;
  if ( g_pIRenderInk )
    (*(void (__fastcall **)(struct IRenderInk *))(*(_QWORD *)g_pIRenderInk + 16LL))(g_pIRenderInk);
  g_pIRenderInk = 0;
  if ( g_pIRenderingContext )
    (*(void (__fastcall **)(struct IRenderingContext *))(*(_QWORD *)g_pIRenderingContext + 16LL))(g_pIRenderingContext);
  g_pIRenderingContext = 0;
  if ( g_pIInkManager )
    (*(void (__fastcall **)(LPVOID))(*(_QWORD *)g_pIInkManager + 16LL))(g_pIInkManager);
  g_pIInkManager = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "FreeCursorStroke", 0);
  if ( g_pIStroke )
    (*(void (__fastcall **)(struct IInkStroke *))(*(_QWORD *)g_pIStroke + 16LL))(g_pIStroke);
  g_pIStroke = 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  operator delete(this);
  return this;
}
