#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"

using namespace std;

namespace sdds {
    void Food::setEmpty() {
      m_foodName[0] = '\0';
      m_cals = 0;
    }

    void Food::set(const char *name, int cals, int when) {
      int len = 0;
      while (*(name + len++) != '\0') { }
      len = len > 30 ? 30 : len;

      strnCpy(m_foodName, name, len);
      m_cals = cals;
      m_when = when;
    }

    void Food::display() const {
      if (isValid()) {
        cout << fixed;
        cout << setfill('.');
        cout << "| " << left << setw(30) <<  m_foodName;
        cout << setfill(' ');
        cout << " | " << right << setw(4)  <<  m_cals;

        cout << " | " << left << setw(10);
        cout << (
          m_when == 1 ? "Breakfast" : 
          m_when == 2 ? "Lunch" :
          m_when == 3 ? "Dinner" :
          m_when == 4 ? "Snack" : ""
        );
        cout << " |" << endl;
      } else {
        cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
      }
    }

    bool Food::isValid() const {
      bool valid = false;
      if (m_foodName[0] != '\0' && m_cals != 0)  {
        valid = true;
      }

      return valid;
    }

    int Food::cals() const {
      return m_cals;
    }
}