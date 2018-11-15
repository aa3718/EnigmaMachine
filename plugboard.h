#include <iostream>
#include <string>
#include <cctype>

#ifndef PLUGBOARD_H
#define PLUGBOARD_H

using namespace std;

class Plugboard {
public:
  int Array[27];
  int pb_counter;
  int Value_NNC_pb;
  int input_array[100];
  int input_counter;
  int pass_value;
  int output_array[27];
  int error_index_5;
  int error_index_13;
  int error_index_16;
  int error_pb_not_number_index;
  int UPLOAD_PLUGBOARD(const char *filename);
  int IMPOSSIBLE_PLUGBOARD_CONFIGURATION();
  int INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS();
  int INVALID_INDEX();
  int UPLOAD_VALUE();
  void ASSIGN(const int letter);
  void SWITCH();
  void UPLOAD_TO_OUTPUT_TEXT_FILE(const char *filename);
};


#endif

