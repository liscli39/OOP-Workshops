#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds {
    int CalorieList::totalCals() const {
      int total = 0;
      for (int i = 0; i < m_noOfFoods; i++) {
        total += m_foods[i].cals();
      }

      return total;
    }

    void CalorieList::Title() const {
      cout << "+----------------------------------------------------+" << endl;
      if (isValid()) {
        cout << "|  Daily Calorie Consumption                         |" << endl;
      } else {
        cout << "| Invalid Calorie Consumption list                   |" << endl;
      }

      cout << "+--------------------------------+------+------------+" << endl;
      cout << "| Food name                      | Cals | When       |" << endl;
      cout << "+--------------------------------+------+------------+" << endl;
    }

    void CalorieList::footer() const {
      cout << "+--------------------------------+------+------------+" << endl;
      if (isValid()) {
        cout << "|    Total Calories for today: " << right << setw(8) << totalCals() << " |            |" << endl;
      } else {
        cout << "|    Invalid Calorie Consumption list                |" << endl;
      }

      cout << "+----------------------------------------------------+" << endl;
    }

    void CalorieList::setEmpty() {
      m_foods = nullptr;
      m_noOfFoods = 0;
      m_foodsAdded = 0;
    }

    bool CalorieList::isValid() const {
      bool valid = true;

      if (m_foods == nullptr) {
        valid = false;
      }

      for (int i = 0; i < m_noOfFoods; i++) {
          if (!m_foods[i].isValid()) {
              valid = false;
          }
      }

      return valid;
    }

    void CalorieList::init(int noOfFoods) {
      if (noOfFoods < 1) {
          setEmpty();
      } else {
        m_foodsAdded = 0;
        m_noOfFoods = noOfFoods;

        m_foods = new Food[noOfFoods];
        for (int i = 0; i < m_noOfFoods; i++) {
          m_foods[i].setEmpty();
        }
      }
    }

    bool CalorieList::add(const char* food_name, int cals, int when) {
      bool success = false;

      if (m_foodsAdded < m_noOfFoods && food_name != nullptr && cals > 0 && cals <= 3000 && when > 0 && when <= 4) {
          m_foods[m_foodsAdded].set(food_name, cals, when);
          success = true;
      }

      m_foodsAdded ++;
      return success;
    }

    void CalorieList::display() const {
      Title();

      for (int i = 0; i < m_noOfFoods; i++) {
          m_foods[i].display();
      }

      footer();
    }

    void CalorieList::deallocate() {
      delete[] m_foods;
    }
}