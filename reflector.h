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
  void UPLOAD_REFLECTOR(const char *filename);
  void SWITCH();
  int INVALID_REFLECTOR_MAPPING();
  int INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS();
  int INVALID_INDEX();

};

#endif
