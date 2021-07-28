#ifndef SDDS_SEARCH_NLIST_H_
#define SDDS_SEARCH_NLIST_H_

#include "Collection.h"
using namespace std;
namespace sdds {
  template <typename T1, typename T2>
  bool search(Collection<T1>& RO, const T1* arr, int length, const T2& e) {
    bool success = false;
    for (int i = 0; i < length; i ++) {
      if (arr[i] == e) {
        success = true;
        RO.add(arr[i]);
      }
    }

    return success;
  }

  template <typename T>
  void listArrayElements(const char* title, const T* arr, int length) {
    cout << title << endl;
    for (int i = 0; i < length; i++) {
      cout << i + 1 << ": " << arr[i] << endl;
    }
  }
}

#endif // !SDDS_SEARCH_NLIST_H_
