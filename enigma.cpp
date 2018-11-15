#include "enigma.h"
using namespace std;

int Enigma::ENIGMA_START(int argc, char **argv) {
  error_code = 0;
  number_of_rotors = 0;

  // Determining the number of rotors based on argc length
  if (argc > 3) {
  number_of_rotors = argc - 4;
  } else {
    number_of_rotors = 0;
  };

  cout << number_of_rotors << " Number of rotors\n";
  
 // Retutrning error value if there is an issue with plugboard file
 if (pb.UPLOAD_PLUGBOARD(argv[1]) == 4) {
   error_code = 4;
    return error_code;
 };

 if (pb.IMPOSSIBLE_PLUGBOARD_CONFIGURATION() == 5) {
   error_code = 5;
   return error_code;
 };

  if (pb.INVALID_INDEX() == 13) {
   error_code = 13;
   return error_code;
 };

if (pb.INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS() == 6) {
   error_code = 6;
   return error_code;
 };

 
 // Uploading input text file depending on argc length 
 pb.UPLOAD_VALUE();
 
 // Creating new instances of rotors

  auto rotors = new Rotor[number_of_rotors];

 
  // For loop for each single input character
  for (int letter = 0; letter < (pb.input_counter) ; letter++) {

    pb.ASSIGN((pb.input_array[letter]));
    pb.SWITCH();

    cout << pb.pass_value << " PB pass value after switch\n";

    if (number_of_rotors != 0) {

      for (int rot = 0 ; rot < number_of_rotors; rot++) {

	if (rot == 0) {
	  rotors[rot].pass_value = pb.pass_value;
	} else {
	  rotors[rot].pass_value = rotors[rot - 1].pass_value;
	};

	if (letter == 0) {
	  rotors[rot].UPLOAD_ROTOR_FILE_TO_ARRAY(argv[2 + (number_of_rotors - rot)]);
	  rotors[rot].UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(argv[number_of_rotors + 3]);
	  rotors[rot].ASSIGN(rot);
	  cout << rotor[rot].first_position_array_index_rotor << " position";
	};

	if (rot == 0) {
	  rotors[rot].CLICK();
	};

	if (rot != 0 && rotors[rot - 1].at_notch == 1) {
	  rotors[rot].CLICK();
	  rotors[rot - 1].at_notch = 0;
	};

	rotors[rot].GOING_THROUGH_ROTOR();
	rotors[rot].REFRAME_FORWARD();
      };
    };

// Upload the reflector
    rf.UPLOAD_REFLECTOR(argv[2]);

    if (rf.INVALID_REFLECTOR_MAPPING() == 9) {
      error_code = 9;
      return error_code;
    };

     if (rf.INVALID_REFLECTOR_MAPPING() == 10) {
      error_code = 10;
      return error_code;
    };

    if (rf.INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS() == 8) {
      error_code = 8;
      return error_code;
    };

    if (rf.INVALID_INDEX() == 12) {
      error_code = 12;
      return error_code;
    };

    if (number_of_rotors == 0) {
      rf.pass_value = pb.pass_value;
    } else {
      rf.pass_value = rotors[number_of_rotors - 1].pass_value;
    };

    rf.SWITCH();
    cout << rf.pass_value << " RF pass value after switch\n";

    if (number_of_rotors == 0) {
      pb.pass_value = rf.pass_value;
    } else {

      if (rf.pass_value + rotors[number_of_rotors - 1].rotation_counter > 25) {
	rf.pass_value = (rf.pass_value + rotors[number_of_rotors - 1].rotation_counter) - 26;
      } else {
	rf.pass_value = rf.pass_value + rotors[number_of_rotors - 1].rotation_counter;
      };

      rotors[number_of_rotors - 1].pass_value = rf.pass_value;

      if (number_of_rotors > 1) {
	for (int rot = (number_of_rotors - 1) ; rot > 0; rot--) {
	  rotors[rot].REVERSE_THROUGH_ROTOR();

	  if (rotors[rot].pass_value + rotors[rot - 1].rotation_counter > 25) {
	    rotors[rot].pass_value = (rotors[rot].pass_value + rotors[rot - 1].rotation_counter) - \
 26;
	  } else {
	    rotors[rot].pass_value = rotors[rot].pass_value + rotors[rot - 1].rotation_counter;
	  };

	  rotors[rot - 1].pass_value = rotors[rot].pass_value;
	};
      };

      rotors[0].REVERSE_THROUGH_ROTOR();

      pb.pass_value = rotors[0].pass_value;
    };
    pb.SWITCH();
    pb.output_array[letter] = pb.pass_value;
  };

  pb.UPLOAD_TO_OUTPUT_TEXT_FILE();

  return 0;
};

