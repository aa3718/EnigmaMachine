#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

#ifndef ROTOR_H
#define ROTOR_H

using namespace std;

class Rotor {
 public:
  int Array[27];
  int rt_counter;
  int notch;
  int pos_array[4];
  int pos_counter;
  int pass_value;
  int first_position_array_index_rotor;
  int rotation_counter;
  int at_notch;
  void UPLOAD_ROTOR_FILE_TO_ARRAY(const char *filename);
  void UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(const char *filename);
  void ASSIGN(const int position);
  void CLICK();
  void REFRAME_FORWARD();
  void GOING_THROUGH_ROTOR();
  void REVERSE_THROUGH_ROTOR();
};

#endif
