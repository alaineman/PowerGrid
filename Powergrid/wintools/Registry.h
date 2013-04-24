
#ifndef REGISTRY_H
#define REGISTRY_H

#include <xstring>
#include <windows.h>

LONG GetHKEYForRead(PHKEY hKey, HKEY group, LPCWSTR path);

LONG GetDWORDRegKey(HKEY hKey, const std::wstring &valueName, DWORD &value, DWORD defaultValue);

LONG GetBoolRegKey(HKEY hKey, const std::wstring &valueName, bool &value, bool defaultValue);

LONG GetStringRegKey(HKEY hKey, const std::wstring &valueName, std::wstring &value, const std::wstring &defaultValue);

#endif // REGISTRY_H
