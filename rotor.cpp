#include "rotor.h"
#include "errors.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int Rotor::UPLOAD_ROTOR_FILE_TO_ARRAY(const char *filename) {
ifstream in_stream;
  in_stream.open(filename);

 if (!in_stream.is_open()) {
   return ERROR_OPENING_CONFIGURATION_FILE;
 };
  
  int a = 0;
  rt_counter = 0;
  
  in_stream >> a;
  while (! in_stream.fail()) {
    Array[rt_counter] = a;
    rt_counter++;
    in_stream >> a;
  };
  
  if (in_stream.fail() && !in_stream.eof()) {
    cout << "Rotor\n";
    return NON_NUMERIC_CHARACTER;
  };

  in_stream.close();
  return NO_ERROR;
};

int Rotor::ROTOR_ERRORS() {

  for (int value = 0 ; value < rt_counter ; value++) {
    
    // Check if not in bound

    if (Array[value] < 0 || Array[value] >= length) {
    error_index = value;
    return INVALID_INDEX;
    };

    // Check if has a duplicate
    if (value < length && value != 0) {
      for (int previous = (value - 1) ; previous >= 0 ; previous--) {
      
      if (Array[value] == Array[previous]) {
	error_index = previous;
      return INVALID_ROTOR_MAPPING;
  };
    };
    };
  };
  
  return NO_ERROR;
};

int Rotor::UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(const char *filename) {

  ifstream in_stream;
  in_stream.open(filename);

 if (!in_stream.is_open()) {
   return ERROR_OPENING_CONFIGURATION_FILE;
 };
  
  int a = 0;
  pos_counter = 0;
  
  in_stream >> a;
  while (! in_stream.fail()) {
    pos_array[pos_counter] = a;
    pos_counter++;
    in_stream >> a;
  };

  if (in_stream.fail() && !in_stream.eof()) {
    cout << "Rotor positions\n";
    return NON_NUMERIC_CHARACTER;
  };

  in_stream.close();
  return NO_ERROR;
};

int Rotor::POSITION_ERRORS(const int number_of_rotors) {

  for (int value = 0 ; value < pos_counter ; value++) {
    
    // Check if not in bound

    if (pos_array[value] < 0 || pos_array[value] >= length) {
      error_index = value;
    return INVALID_INDEX;
    };

    // Check for the right amount of positions
    if (pos_counter < number_of_rotors) {
    return NO_ROTOR_STARTING_POSITION; 
    };

  };
  return NO_ERROR;
};

void Rotor::ASSIGN(const int position) {

  /*
  for (int notch_index = length; notch_index < rt_counter; notch_index++) {
    notch[notch_index] = Array[notch_index];
  };
  
  for (int i = 0; i < (rt_counter - 26) ; i++) {
    cout << notch[i] << "notch \n";
  };
  */

  notch = Array[26];
  first_position_array_index_rotor = pos_array[position];
  rotation_counter = pos_array[position];
  at_notch = 0;
  
};

void Rotor:: CLICK() {
  first_position_array_index_rotor++;
  rotation_counter++;
};

void Rotor::REFRAME_FORWARD() {

 if (pass_value - rotation_counter >= 0) {
   pass_value = pass_value - rotation_counter;
 } else {
   pass_value = 26 + (pass_value - rotation_counter);
 };

};

void Rotor::GOING_THROUGH_ROTOR() {

if (first_position_array_index_rotor == notch) {
    at_notch = 1;
  };
  
  /*
  for (int index = 0; index < (rt_counter - length) ; index++) {
    if (first_position_array_index_rotor == notch[index]) {
      at_notch = 1;
    };
  };
  */  

  if (rotation_counter > 25) {
    rotation_counter = 0;
  };
  
  if (first_position_array_index_rotor > 25) {
    first_position_array_index_rotor = first_position_array_index_rotor - 26;
  };

  int total = first_position_array_index_rotor + pass_value;

  if ((first_position_array_index_rotor + pass_value) < 26) {
    pass_value = Array[first_position_array_index_rotor + pass_value];
    return;
  };

  if ((first_position_array_index_rotor + pass_value) >= 26) {
    pass_value = Array[(total - 26)];
    return;
  };
};


void Rotor::REVERSE_THROUGH_ROTOR() {

  for (int i = 0 ; i < 26 ; i++) {
    if (pass_value == Array[i]) {
      if (i > first_position_array_index_rotor) {
	pass_value = (i - first_position_array_index_rotor);
	return;
      };
      if (i < first_position_array_index_rotor) {
	pass_value = (26 - (first_position_array_index_rotor - i));
	return;
      };
      if (i == first_position_array_index_rotor) {
	pass_value = (first_position_array_index_rotor - i);
        return;
      };
    };
  };
};

  
