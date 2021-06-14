#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds
{
  double Bill::totalTax() const {
    int i;
    double total = 0;
    for (i = 0; i < m_noOfItems; i++) {
        total += m_items[i].tax();
    }

    return total;
  }

  double Bill::totalPrice() const {
    int i;
    double total = 0;
    for (i = 0; i < m_noOfItems; i++) {
        total += m_items[i].price();
    }

    return total;
  }

  void Bill::Title() const {
    cout << "+--------------------------------------+" << endl;
    if (isValid()) {
      cout << "| " << left << setw(36) <<  m_title << " |" << endl;
    } else {
      cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+----------------------+---------+-----+" << endl;
    cout << "| Item Name            | Price   + Tax |" << endl;
    cout << "+----------------------+---------+-----+" << endl;
  }

  void Bill::footer() const {
    cout << "+----------------------+---------+-----+" << endl;
    if (isValid()) {
      cout << setprecision(2);
      cout << "|                Total Tax: " << right << setw(10) << totalTax() << " |" << endl;
      cout << "|              Total Price: " << right << setw(10) << totalPrice() << " |" << endl;
      cout << "|          Total After Tax: " << right << setw(10) << (totalTax() + totalPrice()) << " |" << endl;
    } else {
      cout << "| Invalid Bill                         |" << endl;
    }

    cout << "+--------------------------------------+" << endl;
  }

  void Bill::setEmpty() {
    m_title[0] = NULL;
    m_items = nullptr;
    m_noOfItems = 0;
    m_itemsAdded = 0;
  }

  bool Bill::isValid() const {
    bool valid = true;

    if (m_title[0] == NULL || m_items == nullptr) {
      valid = false;
    }

    for (int i = 0; i < m_noOfItems; i++) {
        if (!m_items[i].isValid()) {
            valid = false;
        }
    }

    return valid;
  }

  void Bill::init(const char *title, int noOfItems) {
    if (title == nullptr && noOfItems < 1) {
        setEmpty();
    } else {
      strnCpy(m_title, title, 36);
      m_itemsAdded = 0;
      m_noOfItems = noOfItems;

      m_items = new Item[noOfItems];
    }
  }

  bool Bill::add(const char *item_name, double price, bool taxed) {
    bool success = false;

    if (item_name != nullptr && price > 0 && m_itemsAdded < m_noOfItems) {
        m_items[m_itemsAdded].set(item_name, price, taxed);
    }

    m_itemsAdded ++;
    return success;
  }

  void Bill::display() const {
    Title();

    for (int i = 0; i < m_noOfItems; i++) {
        m_items[i].display();
    }

    footer();
  }

  void Bill::deallocate() {
    delete[] m_items;
  }
}
