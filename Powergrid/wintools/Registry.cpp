#include "Registry.h"
#include <windows.h>

LONG GetHKEYForRead(PHKEY hKey, HKEY group, LPCWSTR path) {
	return RegOpenKeyExW(group, path, 0, KEY_READ, hKey);
}

LONG GetDWORDRegKey(HKEY hKey, const std::wstring &valueName, DWORD &value, DWORD defaultValue) {
	value = defaultValue;
	DWORD bufferSize(sizeof(DWORD));
	DWORD result(0);
	LONG errNum = ::RegQueryValueExW(hKey, valueName.c_str(), 0, NULL, 
		reinterpret_cast<LPBYTE>(&result), &bufferSize);
	if (ERROR_SUCCESS == errNum) {
		value = result;
	}
	return errNum;
}

LONG GetBoolRegKey(HKEY hKey, const std::wstring &valueName, bool &value, bool defaultValue) {
	DWORD dwDefaultValue(defaultValue ? 1 : 0);
	DWORD result(0);
	LONG errNum = GetDWORDRegKey(hKey, valueName.c_str(), result, dwDefaultValue);
	if (ERROR_SUCCESS == errNum) {
		value = (result != 0) ? true : false;
	}
	return errNum;
}

LONG GetStringRegKey(HKEY hKey, const std::wstring &valueName, std::wstring &value, const std::wstring &defaultValue) {
	value = defaultValue;
	WCHAR buffer[512];
	DWORD bufferSize = sizeof(buffer);
	LONG errNum = RegQueryValueExW(hKey, valueName.c_str(), 0, NULL, (LPBYTE)buffer, &bufferSize);
	if (ERROR_SUCCESS == errNum) {
		value = buffer;
	} 
	return errNum;
}