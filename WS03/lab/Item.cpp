#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {
    void Item::setName(const char* name) {
        int len = 0;
        while (*(name + len++) != '\0') { }
        strnCpy(m_itemName, name, len);
    }

    void Item::setEmpty() {
        m_itemName[0] = NULL;
        m_price = 0.0;
    }

    void Item::set(const char* name, double price, bool taxed) {
        int len = 0;
        while (*(name + len++) != '\0') { }
        len = len > 20 ? 20 : len;

        strnCpy(m_itemName, name, len);
        m_price = price;
        m_taxed = taxed;
    }

    void Item::display() const {
      if (isValid()) {
        cout << fixed;
        cout << setprecision(2);
        cout << setfill('.');
        cout << "| " << left << setw(20) <<  m_itemName;
        cout << setfill(' ');
        cout << " | " << right << setw(7)  <<  m_price;
        cout << " | " << left << setw(3)  <<  (m_taxed ? "Yes" : "No");
        cout << " |" << endl;
      } else {
        cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
      }
    }

    bool Item::isValid() const {
        bool valid = false;
        if (m_itemName[0] != NULL && m_price != 0.0)  {
          valid = true;
        }
        
        return valid;
    }

    double Item::price() const {
        return m_price;
    }

    double Item::tax() const {
        double tax = 0.0;
        if (m_taxed) {
            tax = m_price * 0.13;
        }

        return tax;
    }
}
