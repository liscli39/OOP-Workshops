#ifndef SDDS_CALORIE_LIST_H_
#define SDDS_CALORIE_LIST_H_
#include "Food.h"

namespace sdds {
   class CalorieList {
      Food* m_foods;
      int m_noOfFoods;
      int m_foodsAdded;
      int totalCals()const;
      void Title()const;
      void footer()const;
      void setEmpty();
      bool isValid()const;

   public:
      void init(int noOfFoods);
      bool add(const char* food_name, int cals, int when);
      void display() const;
      void deallocate();
   };
}
#endif // !SDDS_TRANSCRIPT_H
