#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <vector>

#ifndef ROTOR_H
#define ROTOR_H

using namespace std;

class Rotor {
 public:
  const int length = 26;
  int Array[100];
  int rt_counter;
  int notch;
  int pos_array[30];
  int pos_counter;
  int pass_value;
  int first_position_array_index_rotor;
  int rotation_counter;
  int at_notch;
  int error_index;
  int UPLOAD_ROTOR_FILE_TO_ARRAY(const char *filename);
  int ROTOR_ERRORS();
  int UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(const char *filename);
  int POSITION_ERRORS(const int number_of_rotors);
  void ASSIGN(const int position);
  void CLICK();
  void REFRAME_FORWARD();
  void GOING_THROUGH_ROTOR();
  void REVERSE_THROUGH_ROTOR();
};

#endif
