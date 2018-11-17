#include <iostream>
#include <string>
#include <cctype>

#ifndef REFLECTOR_H
#define REFLECTOR_H

using namespace std;

class Reflector {
 public:
  int Array[27];
  int rf_counter;
  int Value_NNC_rf;
  int pass_value;
  int error_index;
  int UPLOAD_REFLECTOR(const char *filename);
  int REFLECTOR_ERRORS();
  void SWITCH();
};

#endif
