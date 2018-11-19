#include <iostream>
#include <string>
#include <cctype>

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

using namespace std;

class Plugboard {
public:
  static const int alphabet = 26;
  int Array[27];
  int pb_counter;
  int input_array[100];
  int input_counter;
  int pass_value;
  int output_array[27];
  int error_index;
  
  // Uploads the plugboard file values and inputs them into an array if numeric
  int UPLOAD_PLUGBOARD(const char *filename);

  // Goes through plugboard values one by one and checks for error codes
  int PLUGBOARD_ERRORS();

  // Uploads the input values into an array
  int UPLOAD_VALUE();

  // Sets pass value to the first letter
  void ASSIGN(const int letter);

  // Switches the input value to the paired plugboard value
  void SWITCH();

  // Outputs character value of last passing value integer
  void UPLOAD_TO_OUTPUT_TEXT_FILE(int indexed);
};

#endif

