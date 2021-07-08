#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
  Line::operator const char *() const {
    return (const char *)m_value;
  }
  Line &Line::operator=(const char *lineValue) {
    delete[] m_value;
    m_value = new char[strLen(lineValue) + 1];
    strCpy(m_value, lineValue);
    return *this;
  }
  Line::Line() {
    m_value = nullptr;
  }
  Line::~Line() {
    if (m_value != nullptr) {
      delete[] m_value;
    }
  }

  // TextFile
  void TextFile::setFilename(const char *fname, bool isCopy) {
    if (fname != nullptr) {
      int len = strLen(fname) + 1;

      if (isCopy) {
        m_filename = new char[len + 2];
        strCpy(m_filename, "C_");
        strCat(m_filename, fname);
      }
      else {
        m_filename = new char[len];
        strCpy(m_filename, fname);
      }
    }
  }
  void TextFile::setNoOfLines() {
    int noOfLines = 0;
    char ch = EOF;

    if (m_filename != nullptr) {
      ifstream fin(m_filename);

      while (fin.get(ch)) {
        if (ch == '\n') {
          noOfLines++;
        }
      }
      fin.close();
    }

    if (noOfLines == 0) {
      setEmpty();
    } else {
      noOfLines++;
    }

    m_noOfLines = noOfLines;
  }
  void TextFile::loadText() {
    if (m_filename != nullptr) {
      ifstream fin(m_filename);
      string line;
      int noOfLine = 0;

      m_textLines = new Line[m_noOfLines];
      while (getline(fin, line)) {
        m_textLines[noOfLine++] = line.c_str();
      }

      m_noOfLines = noOfLine;
      fin.close();
    }
  }
  void TextFile::saveAs(const char *fileName) const {
    if (fileName != nullptr) {
      ofstream fout(fileName);
      for (int i = 0; i < (int)m_noOfLines; i++) {
        fout << (const char *)m_textLines[i] << endl;
      }

      fout.close();
    }
  }
  void TextFile::setEmpty() {
    delete[] m_textLines;
    delete[] m_filename;

    m_textLines = nullptr;
    m_filename = nullptr;
    m_noOfLines = 0;
  }

  TextFile::TextFile(unsigned pageSize) {
    m_textLines = nullptr;
    m_filename = nullptr;
    m_pageSize = pageSize;
  }
  TextFile::TextFile(const char *filename, unsigned pageSize) {
    m_textLines = nullptr;
    m_filename = nullptr;
    m_pageSize = pageSize;

    if (filename != nullptr) {
      setFilename(filename);
      setNoOfLines();
      loadText();
    }
  }
  TextFile::TextFile(const TextFile &textFile) {
    m_textLines = nullptr;
    m_filename = nullptr;
    m_pageSize = textFile.m_pageSize;

    setFilename(textFile.m_filename, true);
    textFile.saveAs(m_filename);

    setNoOfLines();
    loadText();
  }
  TextFile &TextFile::operator=(const TextFile &textFile) {
    delete[] m_textLines;
    m_textLines = nullptr;

    textFile.saveAs(m_filename);

    setNoOfLines();
    loadText();

    return *this;
  }
  TextFile::~TextFile() {
    setEmpty();
  }
  ostream &TextFile::view(ostream &ostr) const {
    ostr << m_filename << endl;
    ostr << setfill('=');
    ostr << setw(strLen(m_filename)) << "=" << endl;

    for (int i = 0; i < (int)m_noOfLines; i++) {
      ostr << (const char *)m_textLines[i] << endl;

      if ((i + 1) % m_pageSize == 0) {
        ostr << "Hit ENTER to continue...";
        while (getchar() != '\n') {}
      }
    }

    return ostr;
  }
  istream &TextFile::getFile(istream &istr) {
    string filename;
    istr >> filename;
    while (istr.get() != '\n') {}

    setFilename(filename.c_str());
    setNoOfLines();

    loadText();
    return istr;
  }
  TextFile::operator bool() const {
    return m_textLines != nullptr && m_filename != nullptr;
  }
  unsigned TextFile::lines() const {
    return m_noOfLines;
  }
  const char *TextFile::name() const {
    return m_filename;
  }
  const char *TextFile::operator[](unsigned index) const {
    if (*this) {
      if (index >= m_noOfLines) {
        index -= m_noOfLines;
      }

      return (const char *)m_textLines[index];
    }

    return nullptr;
  }

  //
  ostream &operator<<(ostream &ostr, const TextFile &text) {
    return text ? text.view(ostr) : ostr;
  }
  istream &operator>>(istream &istr, TextFile &text) {
    return text.getFile(istr);
  }
}