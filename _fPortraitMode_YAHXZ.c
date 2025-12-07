__int64 fPortraitMode(void)
{
  unsigned int v0; // edi
  int *v1; // r8
  int SystemMetrics; // ebx
  int *v3; // r8
  _BYTE v5[16]; // [rsp+20h] [rbp-108h] BYREF
  DEVMODEW DevMode; // [rsp+30h] [rbp-F8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "fPortraitMode", 0);
  v0 = 0;
  memset(&DevMode, 0, sizeof(DevMode));
  DevMode.dmSize = 220;
  if ( EnumDisplaySettingsExW(0, 0xFFFFFFFF, &DevMode, 6u) && (DevMode.dmFields & 0x80) != 0 )
  {
    if ( DevMode.dmDisplayOrientation == 1 || DevMode.dmDisplayOrientation == 3 )
      v0 = 1;
  }
  else
  {
    SystemMetrics = Helpers::GetSystemMetrics((Helpers *)1, 0, v1);
    LOBYTE(v0) = (int)Helpers::GetSystemMetrics(0, 0, v3) < SystemMetrics;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v0;
}
