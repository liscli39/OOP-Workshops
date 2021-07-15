#include <iostream>
#include <string.h>
#include <iomanip>
#include "MotorVehicle.h"
using namespace std;

namespace sdds {
  MotorVehicle::MotorVehicle(const char *licensePlate, int year){
    if (licensePlate != nullptr) {
      strcpy(m_licensePlate, licensePlate);
      strcpy(m_address, "Factory");
      m_year = year;
    }
  }

  void MotorVehicle::moveTo(const char* address){
    if (address != nullptr) {
      cout << "|" << right << setw(8) << m_licensePlate  << "| |";
      cout << right << setw(20) << m_address << " ---> ";
      cout << left << setw(20) << address << "|" << endl;

      strcpy(m_address, address);
    }
  }

  ostream& MotorVehicle::write(ostream& os) const{
    os << "| " << m_year << " | " << m_licensePlate << " | " << m_address << "";
    return os;
  }

  istream& MotorVehicle::read(istream& in){
    cout << "Built year: ";
    in >> m_year;

    cout << "License plate: ";
    string licensePlate;
    in >> licensePlate;
    while (in.get() != '\n') {}
    strcpy(m_licensePlate, licensePlate.c_str());

    cout << "Current location: ";
    string address;
    in >> address;
    while (in.get() != '\n') {}
    strcpy(m_address, address.c_str());

    return in;
  }

  ostream& operator<<(ostream& ostr, const MotorVehicle& vehicle){
    return vehicle.write(ostr);
  }

  istream& operator>>(istream& istr, MotorVehicle& vehicle){
    return vehicle.read(istr);
  }
}
