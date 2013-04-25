
/* File  : wintools/Registry.h
   Author: Chronio

   This header provides various functions for accessing the registry. 
 */

#ifndef REGISTRY_H
#define REGISTRY_H

#include <xstring>
#include <windows.h>

/* Creates an HKEY to access the given path in the registry. */
LONG GetHKEYForRead(PHKEY hKey, HKEY group, LPCWSTR path);

/* Retrieves the value under valueName in the HKEY as a DWORD. 
   The value given by defaultValue will be used when the value could not be found. 
 */
LONG GetDWORDRegKey(HKEY hKey, const std::wstring &valueName, DWORD &value, DWORD defaultValue);

/* Retrieves the value under valueName in the HKEY as a bool. 
   The value given by defaultValue will be used when the value could not be found. 
 */
LONG GetBoolRegKey(HKEY hKey, const std::wstring &valueName, bool &value, bool defaultValue);

/* Retrieves the value under valueName in the HKEY as a wstring. 
   The value given by defaultValue will be used when the value could not be found. 
 */
LONG GetStringRegKey(HKEY hKey, const std::wstring &valueName, std::wstring &value, const std::wstring &defaultValue);

#endif // REGISTRY_H
