#ifndef STRINGMAP_H
#define STRINGMAP_H

#include "stdafx.h"
#include <vector>

namespace cache {

  template<typename T> class StringMapEntry {
    private:
      cstring key;
      T *value;
    public:
      StringMapEntry(cstring key, T *value);

      cstring GetKey();
      T GetValue();
  };

  template<typename T> class StringMap {
    private:
      uint GetHash(cstring key);
      std::vector<StringMapEntry<T>> entries;
      uint reserved_size;
    public:
      StringMap();
      StringMap(uint init_size);

      void ensureCapacity(uint minLength);
      void shrink(uint minLength);

      T Get(cstring key);

      T Set(cstring key, T elem);
      T Remove(cstring key);

      bool contains(cstring key);

      std::vector<cstring> GetKeys();
      std::vector<StringMapEntry<T>> GetEntries();

  };


  template<typename T> uint StringMap<T>::GetHash(cstring key) {
    uint h = 0;
    for (uint i = 0; key[i] != 0;) {
      h = 31 * h + key[i++];
    }
    return h;
  }
}

#endif // STRINGMAP_H
