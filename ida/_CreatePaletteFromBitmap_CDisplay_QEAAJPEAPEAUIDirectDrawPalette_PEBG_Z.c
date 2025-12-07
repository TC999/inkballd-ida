// Hidden C++ exception states: #wind=1
__int64 __fastcall CDisplay::CreatePaletteFromBitmap(
        CDisplay *this,
        struct IDirectDrawPalette **a2,
        const unsigned __int16 *a3)
{
  CDisplay *v4; // rbp
  HINSTANCE ResourceW; // rax
  int *v6; // r9
  void *Resource; // rax
  unsigned int *v8; // rax
  unsigned int *v9; // r11
  int v10; // ebx
  __int64 v11; // rax
  char *v12; // r8
  unsigned __int16 v13; // cx
  unsigned int v14; // edx
  unsigned int v15; // ecx
  char *v16; // r10
  _BYTE *v17; // r9
  HANDLE FileW; // rax
  void *v19; // rbx
  signed int LastError; // eax
  unsigned int v21; // r9d
  int *v22; // r8
  unsigned int v23; // edx
  unsigned int v24; // r9d
  _BYTE *v25; // r8
  char v26; // cl
  signed int v28; // eax
  unsigned int v29; // r9d
  signed int v30; // eax
  unsigned int v31; // r9d
  signed int v32; // eax
  unsigned int v33; // r9d
  int *dwCreationDisposition; // [rsp+20h] [rbp-488h]
  _BYTE v35[16]; // [rsp+40h] [rbp-468h] BYREF
  __int64 v36; // [rsp+50h] [rbp-458h]
  int v37[3]; // [rsp+58h] [rbp-450h] BYREF
  unsigned __int16 v38; // [rsp+66h] [rbp-442h]
  unsigned int v39; // [rsp+78h] [rbp-430h]
  char Buffer[16]; // [rsp+80h] [rbp-428h] BYREF
  char v41; // [rsp+90h] [rbp-418h] BYREF
  char v42; // [rsp+91h] [rbp-417h] BYREF
  _BYTE v43[1046]; // [rsp+92h] [rbp-416h] BYREF
  int v44; // [rsp+4B0h] [rbp+8h] BYREF
  int v45; // [rsp+4B4h] [rbp+Ch]
  DWORD NumberOfBytesRead; // [rsp+4C8h] [rbp+20h] BYREF

  v45 = HIDWORD(this);
  v36 = -2;
  v4 = g_pDisplay;
  v44 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v35, "CDisplay::CreatePaletteFromBitmap", &v44);
  if ( *((_QWORD *)v4 + 1) && a2 )
  {
    *a2 = 0;
    ResourceW = (HINSTANCE)Helpers::FindResourceW(
                             0,
                             (HINSTANCE)0x1F5,
                             (const unsigned __int16 *)2,
                             0,
                             dwCreationDisposition);
    if ( ResourceW )
    {
      Resource = Helpers::LoadResource(0, ResourceW, 0, v6);
      v8 = (unsigned int *)LockResource(Resource);
      v9 = v8;
      if ( v8 )
      {
        v11 = *v8;
        v12 = (char *)v9 + v11;
        if ( (unsigned int)v11 < 0x28 )
        {
          v14 = 0;
        }
        else
        {
          v13 = *((_WORD *)v9 + 7);
          if ( v13 <= 8u )
          {
            v14 = v9[8];
            if ( !v14 )
              v14 = 1 << v13;
          }
          else
          {
            v14 = 0;
          }
        }
        v15 = 0;
        if ( v14 )
        {
          v16 = &v41;
          v17 = v12 + 1;
          do
          {
            if ( v15 >= 0x100 )
              break;
            *v16 = v17[1];
            v17[&v41 - v12] = *v17;
            v17[&v42 - v12] = *(v17 - 1);
            v17[v43 - v12] = 0;
            ++v15;
            v16 += 4;
            v17 += 4;
          }
          while ( v15 < v14 );
        }
        v10 = (*(__int64 (__fastcall **)(_QWORD, __int64, char *, struct IDirectDrawPalette **, _QWORD))(**((_QWORD **)v4 + 1) + 40LL))(
                *((_QWORD *)v4 + 1),
                4,
                &v41,
                a2,
                0);
        v44 = v10;
        if ( v10 < 0
          && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Cu, (const GUID *)qword_401610, v10);
          v10 = v44;
        }
      }
      else
      {
        v10 = -2147467259;
        v44 = -2147467259;
      }
    }
    else
    {
      FileW = CreateFileW((LPCWSTR)0x1F5, 0x80000000, 0, 0, 3u, 0, 0);
      v19 = FileW;
      if ( FileW == (HANDLE)-1LL )
      {
        if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          LastError = GetLastError();
          v21 = (unsigned __int16)LastError | 0x80070000;
          if ( LastError <= 0 )
            v21 = LastError;
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Du, (const GUID *)qword_401610, v21);
        }
        v10 = -2147467259;
        v44 = -2147467259;
      }
      else
      {
        if ( ReadFile(FileW, Buffer, 0xEu, &NumberOfBytesRead, 0) && NumberOfBytesRead == 14 )
        {
          if ( ReadFile(v19, v37, 0x28u, &NumberOfBytesRead, 0) && NumberOfBytesRead == 40 )
          {
            if ( ReadFile(v19, &v41, 0x400u, &NumberOfBytesRead, 0) && NumberOfBytesRead == 1024 )
            {
              Helpers::CloseHandle(v19, 0, v22);
              if ( v37[0] == 40 )
              {
                if ( v38 <= 8u )
                {
                  v23 = v39;
                  if ( !v39 )
                    v23 = 1 << v38;
                }
                else
                {
                  v23 = 0;
                }
              }
              else
              {
                v23 = 0;
              }
              v24 = 0;
              if ( v23 )
              {
                v25 = v43;
                do
                {
                  if ( v24 >= 0x100 )
                    break;
                  v26 = *(v25 - 2);
                  *(v25 - 2) = *v25;
                  *v25 = v26;
                  ++v24;
                  v25 += 4;
                }
                while ( v24 < v23 );
              }
              v10 = (*(__int64 (__fastcall **)(_QWORD, __int64, char *, struct IDirectDrawPalette **, _QWORD))(**((_QWORD **)v4 + 1) + 40LL))(
                      *((_QWORD *)v4 + 1),
                      4,
                      &v41,
                      a2,
                      0);
              v44 = v10;
              if ( v10 < 0
                && WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              {
                WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x21u, (const GUID *)qword_401610, v10);
                v10 = v44;
              }
              goto LABEL_48;
            }
            if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            {
              v28 = GetLastError();
              v29 = (unsigned __int16)v28 | 0x80070000;
              if ( v28 <= 0 )
                v29 = v28;
              WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x20u, (const GUID *)qword_401610, v29);
            }
          }
          else if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
                 && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            v30 = GetLastError();
            v31 = (unsigned __int16)v30 | 0x80070000;
            if ( v30 <= 0 )
              v31 = v30;
            WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Fu, (const GUID *)qword_401610, v31);
          }
        }
        else if ( WPP_GLOBAL_Control != (_UNKNOWN *)&WPP_GLOBAL_Control
               && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          v32 = GetLastError();
          v33 = (unsigned __int16)v32 | 0x80070000;
          if ( v32 <= 0 )
            v33 = v32;
          WPP_SF_L(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Eu, (const GUID *)qword_401610, v33);
        }
        Helpers::CloseHandle(v19, 0, v22);
        v10 = -2147467259;
        v44 = -2147467259;
      }
    }
LABEL_48:
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
    return (unsigned int)v10;
  }
  v44 = -2147024809;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
  return 2147942487LL;
}
