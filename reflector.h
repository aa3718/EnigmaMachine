#include <iostream>
#include <string>
#include <cctype>

#ifndef REFLECTOR_H
#define REFLECTOR_H

using namespace std;

class Reflector {
 public:
  static const int alphabet = 26;
  int Array[27];
  int rf_counter;
  int pass_value;

  // Uploads the reflector file values and inputs them into an array if numeric
  int UPLOAD_REFLECTOR(const char *filename);

  // Goes through reflector values one by one and checks for error codes
  int REFLECTOR_ERRORS();

  // Switches the input value to the paired reflector value
  void SWITCH();
};

#endif
