#ifndef SDDS_MOTOR_H__
#define SDDS_MOTOR_H__
#include <iostream>
namespace sdds {
  class MotorVehicle {
    char m_licensePlate[10];
    char m_address[65];
    int m_year;
  public:
    MotorVehicle(char *licensePlate, int m_year);
    void moveTo(const char* address);
    std::ostream& write(std::ostream& os) const;
    std::istream& read(std::istream& in);
  };

  std::ostream& operator<<(std::ostream& ostr, const MotorVehicle& motor);
  std::istream& operator>>(std::istream& istr, MotorVehicle& motor);
}
#endif // !SDDS_MOTOR_H__
