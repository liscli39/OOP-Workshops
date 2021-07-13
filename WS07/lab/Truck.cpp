#include <iostream>
#include <string.h>
#include <iomanip>
#include "Truck.h"
using namespace std;

namespace sdds {
  Truck::Truck(char *licensePlate, int year, double capacity, char* addres) : MotorVehicle(licensePlate, year) {
    moveTo(addres);
    m_capacity = capacity;
    m_cargoLoad = 0;
  }

  bool Truck::addCargo(double cargo){
    bool success = false;
    if (m_cargoLoad < m_capacity) {
      m_cargoLoad += cargo;
      m_cargoLoad = m_cargoLoad > m_capacity ? m_capacity : m_cargoLoad;
      success = true;
    }

    return success;
  }

  bool Truck::unloadCargo(){
    bool success = false;

    if (m_cargoLoad != 0) {
      m_cargoLoad = 0;
      success = true;
    }

    return success;
  }

  ostream& Truck::write(ostream& os) const{
    MotorVehicle::write(os);
    os << " | " << m_cargoLoad << "/" << m_capacity << "";
    return os;
  }

  istream& Truck::read(istream& in){
    MotorVehicle::read(in);

    cout << "Capacity: ";
    in >> m_capacity;

    cout << "Cargo: ";
    in >> m_cargoLoad;

    return in;
  }

  ostream& operator<<(ostream& ostr, const Truck& truck){
    return truck.write(ostr);
  }

  istream& operator>>(istream& istr, Truck& truck){
    return truck.read(istr);
  }
}
