#include "reflector.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;


void Reflector::UPLOAD_REFLECTOR(const char *filename) {
ifstream in_stream;
  in_stream.open(filename);

  int a = 0;
  rf_counter = 0;
  
  in_stream >> a;
  while (! in_stream.fail()) {
    Array[rf_counter] = a;
    rf_counter++;
    in_stream >> a;
  }; 
  
   if (!in_stream.eof() && !isdigit(a)) {
     //    Value_NNC_rt = "True";
    cout << "There is a character\n";
  };


  in_stream.close();

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

int Reflector::INVALID_REFLECTOR_MAPPING() {

  for (int i = 0 ; i < rf_counter ; i++) {
  for (int j = i+1; j < rf_counter ; j++) {
    if (Array[i] == Array[j]) {
       return 9;
    };
  };
  };
  
   return 0;
};

int Reflector::INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS() {

  if (rf_counter == 26) {
     return 0;
  } else {
     return 10;
  };
};

int Reflector::INVALID_INDEX() {

for (int i = 0 ; i < rf_counter ; i++) {
  if (Array[i] < 0 || Array[i] > 26) {
    return 12;
  };
 };
  return 0;
  
};
