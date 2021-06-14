#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_

namespace sdds {
  class Food {
    char m_foodName[31];
    int m_cals;
    int m_when;

  public:
    void setEmpty();
    void set(const char *name, int cals, int when);
    void display() const;
    bool isValid() const;
    int cals() const;
  };
}

#endif // !SDDS_SUBJECT_H
