#ifndef SDDS_TRUCK_H__
#define SDDS_TRUCK_H__
#include <iostream>
#include "MotorVehicle.h"

namespace sdds {
  class Truck : public MotorVehicle {
    double m_capacity;
    double m_cargoLoad;

  public:
    Truck(char *licensePlate, int year, double capacity, char* addres);
    bool addCargo(double cargo);
    bool unloadCargo();
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in);
  };

  std::ostream& operator<<(std::ostream& ostr, const Truck& truck);
  std::istream& operator>>(std::istream& istr, Truck& truck);
}
#endif // !SDDS_TRUCK_H__
