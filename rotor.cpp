#include "rotor.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

void Rotor::UPLOAD_ROTOR_FILE_TO_ARRAY(const char *filename) {
ifstream in_stream;
  in_stream.open(filename);

  int a = 0;
  rt_counter = 0;
  
  in_stream >> a;
  while (! in_stream.fail()) {
    Array[rt_counter] = a;
    rt_counter++;
    in_stream >> a;
  };

cout << "Rotor\n";
  for (int i = 0; i < rt_counter ; i++) {
    cout << Array[i] << " \n";
  };
  
   if (!in_stream.eof() && !isdigit(a)) {
     //    Value_NNC_rt = "True";
  };


  in_stream.close();
  
};

void Rotor::UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(const char *filename) {

  ifstream in_stream;
  in_stream.open(filename);

  int a = 0;
  pos_counter = 0;
  
  in_stream >> a;
  while (! in_stream.fail()) {
    pos_array[pos_counter] = a;
    pos_counter++;
    in_stream >> a;
  };


 if (!in_stream.eof() && !isdigit(a)) {
   //    Value_NNC_pos = "True";
   //   cout << "There is a character\n";
  };

  in_stream.close();

};

void Rotor::ASSIGN(const int position) {

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

 if (pass_value - rotation_counter >= 0){
   pass_value = pass_value - rotation_counter;
 } else {
   pass_value = 26 + (pass_value - rotation_counter);
 };

};

void Rotor::GOING_THROUGH_ROTOR() {

  if (first_position_array_index_rotor == notch) {
    at_notch = 1;
  };

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
    pass_value = Array[(total-26)];
    return;
  };
 ;
};

void Rotor::REVERSE_THROUGH_ROTOR() {

  for (int i = 0 ; i < rt_counter ; i++) {
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
      }
    };
  };
};

  
