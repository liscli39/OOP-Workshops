#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h" // using strLen, strCpy and strCmp
#include "Canister.h"

#define PI 3.14159265

using namespace std;

namespace sdds {
  // Private
  void Canister::setToDefault() {
    m_contentName = nullptr;
    m_height = 13.0;
    m_diameter = 10.0;
    m_contentVolume = 0.0;
    m_usable = true;
  }

  void Canister::setName(const char *Cstr) {
    if (Cstr != nullptr && m_usable) {
      int len = 0;
      while (*(Cstr + len++) != '\0') { }

      m_contentName = new char[len + 1];
      strCpy(m_contentName, Cstr, len);
    }
  }

  bool Canister::isEmpty() const {
    return m_contentVolume < 0.00001;
  }

  bool Canister::hasSameContent(const Canister &C) const {
    return strCmp(m_contentName, C.m_contentName);
  }

  // Public
  Canister::Canister() {
    setToDefault();
  }

  Canister::Canister(const char *contentName) {
    setToDefault();
    if (contentName != nullptr) {
      setName(contentName);
    }
  }

  Canister::Canister(double height, double diameter, const char* contentName) {
    setToDefault();

    bool usable = height >= 10.0 && height <= 40.0
      && diameter >= 10.0 && diameter <= 30.0;

    if (usable) {
      if (contentName != nullptr) {
        int len = 0;
        while (*(contentName + len++) != '\0') { }
        m_contentName = new char[len + 1];
        strCpy(m_contentName, contentName, len);
      }

      m_height = height;
      m_diameter = diameter;
      m_contentVolume = 0.0;
    }

    m_usable = usable;
  }

  Canister::~Canister() {
    delete [] m_contentName;
  }

  Canister &Canister::setContent(const char *contentName) {
    if (contentName == nullptr) {
      m_usable = false;
    } else if (isEmpty()) {
      setName(contentName);
    } else if (!strCmp(m_contentName, contentName)) {
      m_usable = false;
    }

    return *this;
  }

  Canister &Canister::pour(double quantity) {
    if (quantity > 0 && m_contentVolume + quantity <= capacity()) {
      m_contentVolume += quantity;
    } else {
      m_usable = false;
    }

    return *this;
  }

  Canister &Canister::pour(Canister& C) {
    setContent(C.m_contentName);

    if (!hasSameContent(C)) {
      m_usable = false;
    } 
    
    if (C.m_contentVolume > capacity() - m_contentVolume) {
      C.m_contentVolume -= capacity() - m_contentVolume;
      m_contentVolume = capacity();
    } else {
      pour(C.m_contentVolume);
      C.m_contentVolume = 0.0;
    }

    return *this;
  }

  double Canister::volume() const {
    return m_contentVolume;
  }

  std::ostream &Canister::display() const {
    cout << fixed;
    cout << setprecision(1);
    cout << right << setw(7) << capacity() << "cc (";
    cout << m_height << "x" << m_diameter << ") Canister";

    if (!m_usable) {
      cout << " of Unusable content, discard!";
    } else if (m_contentName != nullptr) {
      cout << " of " << right << setw(7) << m_contentVolume << "cc   " << m_contentName;
    }

    return cout;
  }

  double Canister::capacity() const {
    return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
  }

  void Canister::clear() {
    delete [] m_contentName;
    setToDefault();
  }

}
