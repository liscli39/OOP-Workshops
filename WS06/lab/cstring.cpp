#include "cstring.h"
#include <string.h>

namespace sdds
{
  void strCpy(char *des, const char *src)
  {
    strcpy(des, src);
  }
  int strLen(const char *s)
  {
    return strlen(s);
  }
  void strCat(char *des, const char *src)
  {
    strcat(des, src);
  }
}