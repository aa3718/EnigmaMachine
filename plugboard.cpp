#include "plugboard.h"
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
  while (! in_stream.fail()) {
    Array[pb_counter] = a;
    pb_counter++;
    in_stream >> a; 
  };

  if (!in_stream.eof() && !isdigit(a)) {
    cout << "There is a character\n";
    error_pb_not_digit_index = pb_counter;
    return 4;
  };
    
  in_stream.close();

    return 0;
};

int Plugboard::IMPOSSIBLE_PLUGBOARD_CONFIGURATION() {
  
for (int i = 0 ; i < pb_counter ; i++) {
  for (int j = i+1; j < pb_counter ; j++) {
    if (Array[i] == Array[j]) {
      cout << "Error, duplicates present(PB)\n";
      error_pb_duplicate_index= j;
      return 5;
    };
  };
  };
 return 0;  
};

int Plugboard::INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS() {

  if (pb_counter % 2 == 0) {
    return 0;
  } else { 
    cout << "Odd number of values(PB)\n";
    return 6;
  };
};

int Plugboard::INVALID_INDEX() {
  
for (int i = 0 ; i < pb_counter ; i++) {
  if (Array[i] < 0 || Array[i] > 26) {
    error_pb_not_number_index = i;
    return 3;
  };
 };
  return 0;
};

int Plugboard::UPLOAD_VALUE(const char *filename) {
  
  ifstream in_stream;
  in_stream.open(filename);
  
  input_counter = 0;
  char character = 0;
  int integer = 0;

  in_stream.get(character);
  
  while (! in_stream.fail()) {
    if (character<= 90 && character >= 65) {
      integer = character - 65;
      input_array[input_counter] = integer;
      input_counter++;
    } else {
      return 4;
    };
    in_stream.get(character);
  };
  in_stream.close();
  return 0; 
};

void Plugboard::ASSIGN(const int letter) {

  pass_value = letter;
  cout << pass_value << "The first letter input\n";

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

void Plugboard::UPLOAD_TO_OUTPUT_TEXT_FILE(const char *filename) {

  ofstream out_stream;
  out_stream.open(filename);

  for (int i = 0; i < input_counter ; i++) {
    char output_letter = output_array[i] + 65;
    out_stream.put(output_letter);
  };

  out_stream.close();
};
