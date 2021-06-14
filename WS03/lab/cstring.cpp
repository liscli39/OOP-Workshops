#include "cstring.h"
namespace sdds {
  void strnCpy(char* des, const char* src, int len) {
    int i;
    for (i = 0; i < len; i++) {
        des[i] = src[i];
    }
  }
}
