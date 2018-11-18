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
  int Array[80];
  int rt_counter;
  int notch[27];
  int pos_array[30];
  int pos_counter;
  int pass_value;
  int first_position_array_index_rotor;
  int rotation_counter;
  int at_notch;
  int error_index;

  // Uploads rotor file values into array   
  int UPLOAD_ROTOR_FILE_TO_ARRAY(const char *filename);

  // Checks for error codes
  int ROTOR_ERRORS();

  // Uploads rotor positions into array
  int UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(const char *filename);

  // Checks for error codes 
  int POSITION_ERRORS(const int number_of_rotors);

  // Assigns notch values, rotation counters and notch boolean false 
  void ASSIGN(const int position);

  // Increments the first value holder and rotation counter
  void CLICK();

  // Reframes the pass value and resets the pass value if rotation counter too big of a value
  void REFRAME_FORWARD();

  // Goes throught the rotor and outputs new pass value
  void GOING_THROUGH_ROTOR();

  // Takes the pass value and goes through the rotors in reverse and sets the new pass_value
  void REVERSE_THROUGH_ROTOR();
};

#endif
