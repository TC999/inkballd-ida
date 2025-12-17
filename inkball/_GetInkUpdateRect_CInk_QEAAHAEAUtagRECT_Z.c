// Hidden C++ exception states: #wind=1
__int64 __fastcall CInk::GetInkUpdateRect(CInk *this, struct tagRECT *a2)
{
  unsigned int v4; // ebx
  _BYTE v6[16]; // [rsp+28h] [rbp-40h] BYREF
  _BYTE v7[16]; // [rsp+38h] [rbp-30h] BYREF
  float v8[3]; // [rsp+48h] [rbp-20h] BYREF
  float v9; // [rsp+54h] [rbp-14h]
  int v10; // [rsp+70h] [rbp+8h] BYREF

  v4 = 0;
  v10 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CInk::GetInkUpdateRect", &v10);
  if ( *((_DWORD *)this + 5) )
  {
    *((_DWORD *)this + 5) = 0;
    CInk::DrawInkToSurface(this, 0);
  }
  if ( *((_DWORD *)this + 4) )
  {
    *((_DWORD *)this + 4) = 0;
    v10 = (*(__int64 (__fastcall **)(struct IRenderingContext *, float *))(*(_QWORD *)g_pIRenderingContext + 40LL))(
            g_pIRenderingContext,
            v8);
    if ( v10 >= 0 )
    {
      if ( g_pIStroke )
      {
        v10 = (*(__int64 (__fastcall **)(struct IInkStroke *, _QWORD, struct tagRECT *))(*(_QWORD *)g_pIStroke + 32LL))(
                g_pIStroke,
                0,
                a2);
        if ( v10 >= 0 )
        {
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "ExpandRect", 0);
          a2->top -= 200;
          a2->bottom += 200;
          a2->left -= 200;
          a2->right += 200;
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
          Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "ConvertInkRectToDisplayRect", 0);
          a2->left = (int)(float)((float)a2->left * v8[0]);
          a2->right = (int)(float)((float)a2->right * v8[0]);
          a2->top = (int)(float)((float)a2->top * v9);
          a2->bottom = (int)(float)((float)a2->bottom * v9);
          Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
          v4 = 1;
        }
      }
    }
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v4;
}
