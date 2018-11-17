#include "reflector.h"
#include "errors.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


int Reflector::UPLOAD_REFLECTOR(const char *filename) {
ifstream in_stream;
  in_stream.open(filename);


 if (!in_stream.is_open()) {
   return ERROR_OPENING_CONFIGURATION_FILE;
 };
  
  int a = 0;
  rf_counter = 0;
  
  in_stream >> a;
    while (! in_stream.fail()) {
      Array[rf_counter] = a;
      rf_counter++;
      in_stream >> a;
    };

  if (in_stream.fail() && !in_stream.eof()) {
    cout << "Reflector\n";
    return NON_NUMERIC_CHARACTER;
  };

  in_stream.close();
  return NO_ERROR;
};

int Reflector::REFLECTOR_ERRORS() {

 for (int value = 0 ; value < rf_counter ; value++) {
    
    // Check if not in bound

    if (Array[value] < 0 || Array[value] >= 26) {
    error_index = value;
    return INVALID_INDEX;
    };

    // Check if has a duplicate
    if (value != 0)  {
    for (int previous = (value - 1) ; previous >= 0 ; previous--) {
      
      if (Array[value] == Array[previous]) {
	error_index = previous;
      return INVALID_REFLECTOR_MAPPING;
  };
    };
    };

  // Check if the right amount of values
  if (rf_counter != 26) {
    return INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS;
  };
 };
 return 0;
}; 


void Reflector::SWITCH() {
 for (int array_index = 0; array_index < rf_counter; array_index++) { 

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

