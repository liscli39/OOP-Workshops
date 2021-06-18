#include "cstring.h"

namespace sdds {
  void strCpy(char* des, const char* src, const int len) {
    for (int i = 0; i < len; i++) {
      des[i] = src[i];
    }

    des[len] = '\0';
  }

  bool strCmp(const char* des, const char* src) {
    bool equal = true;
    int len = 0;

    while (*(src + len++) != '\0') { }

    for (int i = 0; i < len; i++) {
      if (des[i] != src[i]) {
        equal = false;
      }
    }

    return equal;
  }
}
