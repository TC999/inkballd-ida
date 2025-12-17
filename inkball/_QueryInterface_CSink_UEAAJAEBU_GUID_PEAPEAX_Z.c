__int64 __fastcall CSink::QueryInterface(CSink *this, const struct _GUID *a2, void **a3)
{
  bool v6; // cf
  unsigned __int64 v7; // rcx
  int v8; // eax
  bool v9; // cf
  unsigned __int64 v10; // rcx
  int v11; // eax
  unsigned int v12; // ebx
  _BYTE v14[24]; // [rsp+20h] [rbp-18h] BYREF
  unsigned int v15; // [rsp+58h] [rbp+20h] BYREF

  v15 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CSink::QueryInterface", (int *)&v15);
  v6 = *(_QWORD *)&a2->Data1 < *(_QWORD *)&IID_ITabletEventSink.Data1;
  if ( *(_QWORD *)&a2->Data1 == *(_QWORD *)&IID_ITabletEventSink.Data1
    && (v7 = *(_QWORD *)a2->Data4,
        v6 = v7 < *(_QWORD *)IID_ITabletEventSink.Data4,
        v7 == *(_QWORD *)IID_ITabletEventSink.Data4) )
  {
    v8 = 0;
  }
  else
  {
    v8 = -v6 - (v6 - 1);
  }
  if ( v8
    && ((v9 = *(_QWORD *)&a2->Data1 < *(_QWORD *)&IID_IUnknown.Data1,
         *(_QWORD *)&a2->Data1 != *(_QWORD *)&IID_IUnknown.Data1)
     || (v10 = *(_QWORD *)a2->Data4, v9 = v10 < *(_QWORD *)IID_IUnknown.Data4, v10 != *(_QWORD *)IID_IUnknown.Data4)
      ? (v11 = -v9 - (v9 - 1))
      : (v11 = 0),
        v11) )
  {
    *a3 = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
    return 2147500034LL;
  }
  else
  {
    *a3 = this;
    (*(void (__fastcall **)(CSink *))(*(_QWORD *)this + 8LL))(this);
    v12 = v15;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
    return v12;
  }
}
