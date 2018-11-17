#include "plugboard.h"
#include "errors.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

int Plugboard::UPLOAD_PLUGBOARD(const char *filename) {

 ifstream in_stream;
 in_stream.open(filename);
 
  pb_counter = 0;
  int a = 0;
  Value_NNC_pb = 0;

  in_stream >> a;

  if (!in_stream.is_open()) {
    return ERROR_OPENING_CONFIGURATION_FILE;
  } else {  
  while (! in_stream.fail()) {
    Array[pb_counter] = a;
    pb_counter++;
    in_stream >> a; 
  };
  };
  
  if (in_stream.fail() && !in_stream.eof()) {
    cout << "Plugboard\n";
    return NON_NUMERIC_CHARACTER;
  };
  
  in_stream.close();

    return NO_ERROR;
};

int Plugboard::PLUGBOARD_ERRORS() {

  for (int value = 0 ; value < pb_counter ; value++) {
    
    // Check if not in bound
    if (Array[value] < 0 || Array[value] > 26) {
    error_index = value;
    return INVALID_INDEX;
    };

    // Check if has a duplicate
    if (value != 0) {
      for (int previous = (value - 1) ; previous >= 0 ; previous--) {
      
      if (Array[value] == Array[previous]) {
	error_index = previous;
      return IMPOSSIBLE_PLUGBOARD_CONFIGURATION;
  };
    };
    };
    
  // Check if the right amount of values
  if (pb_counter % 2 != 0) {
    return INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS;
  };
  };
  return NO_ERROR;
};

int Plugboard::UPLOAD_VALUE() {
  
  input_counter = 0;
  int integer = 0;

  while ((integer = cin.get()) !=EOF) {
    cin >> ws;
    integer = integer - 65;
    input_array[input_counter] = integer;
    input_counter++;
  };
   
return NO_ERROR; 
};

void Plugboard::ASSIGN(const int letter) {

  pass_value = letter;

};

void Plugboard::SWITCH() {
  
   for (int array_index = 0; array_index < pb_counter; array_index++) { 

     if (pass_value == Array[array_index]) {

	if (array_index % 2 == 0) {
	  int y = array_index + 1;
	  pass_value = Array[y];
	  return;
	};

	if (array_index % 2 == 1) {
	  int x = array_index - 1;
	  pass_value = Array[x];
	  return;
	};
     };
   };
};

void Plugboard::UPLOAD_TO_OUTPUT_TEXT_FILE() {

  for (int i = 0; i < input_counter ; i++) {
    char output_letter = output_array[i] + 65;
    cout << output_letter;
  };
  cout << "\n";
};
