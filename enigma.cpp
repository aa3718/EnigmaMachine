#include "enigma.h"
using namespace std;

int Enigma::ENIGMA_START(int argc, char **argv) {
  error_code = 0;
  number_of_rotors = 0;

  // Determining the number of rotors based on argc length
  if (argc >= 6) {
  number_of_rotors = argc - 6;
  } else {
    number_of_rotors = 0;
  };
 
 // Retutrning error value if there is an issue with plugboard file
 if (pb.UPLOAD_PLUGBOARD(argv[1]) == 4) {
   error_code = 4;
   location = 0;
    return error_code;
 };

 if (pb.IMPOSSIBLE_PLUGBOARD_CONFIGURATION() == 5) {
   error_code = 5;
   location = 0;
   return error_code;
 };

if (pb.IMPOSSIBLE_PLUGBOARD_CONFIGURATION() == 6) {
   error_code = 6;
   location = 0;
   return error_code;
 };

 if (pb.INVALID_INDEX() == 3) {
   error_code = 3;
   location = 0;
   return error_code;
 };
 
 
 // Uploading input text file depending on argc length 
 if (number_of_rotors == 0) {
   if (pb.UPLOAD_VALUE(argv[3]) == 4) {
     error_code = 4;
     location = 0;
   };
 } else {
   if (pb.UPLOAD_VALUE(argv[number_of_rotors + 4]) == 4) {
     error_code = 4;
     location = 0;
   };
 };

 cout << pb.input_array[0] << "/n";
 
 // Creating new instances of rotors
  auto rotors = new Rotor[number_of_rotors];

  // For loop for each single input character
  for (int letter = 0; letter < (pb.input_counter) ; letter++) {

    pb.ASSIGN((pb.input_array[letter]));
    pb.SWITCH();

    if (number_of_rotors != 0) {

      for (int rot = 0 ; rot < number_of_rotors; rot++) {

	if (rot == 0) {
	  rotors[rot].pass_value = pb.pass_value;
	} else {
	  rotors[rot].pass_value = rotors[rot - 1].pass_value;
	};

	cout << rotors[rot].pass_value << "pass value before pass rotor \n";
	rotors[rot].UPLOAD_ROTOR_FILE_TO_ARRAY(argv[2 + (number_of_rotors - rot)]);
	rotors[rot].UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(argv[number_of_rotors + 3]);

	if (letter == 0) {
	  rotors[rot].ASSIGN(rot);
	};

	if (rot == 0) {
	  rotors[rot].CLICK();
	};

	if (rot != 0 && rotors[rot - 1].at_notch == 1) {
	  cout << "clickkk\n";
	  rotors[rot].CLICK();
	  rotors[rot - 1].at_notch = 0;
	};

	rotors[rot].GOING_THROUGH_ROTOR();
	rotors[rot].REFRAME_FORWARD();
	cout << rotors[rot].pass_value << "pass value after rotor\n";
      };
    };

// Upload the reflector
    rf.UPLOAD_REFLECTOR(argv[2]);

    if (rf.INVALID_REFLECTOR_MAPPING() == 9) {
      error_code = 9;
      location = 1;
      return error_code;
    };

    if (rf.INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS() == 8) {
      error_code = 8;
      location = 1;
      return error_code;
    };

    if (rf.INVALID_INDEX() == 3) {
      error_code = 3;
      location = 1;
      return error_code;
    };

    if (number_of_rotors == 0) {
      rf.pass_value = pb.pass_value;
    } else {
      rf.pass_value = rotors[number_of_rotors - 1].pass_value;
      cout << rf.pass_value << "before reverse rotor\n";
    };

    rf.SWITCH();
    cout <<  rf.pass_value << "pass value before reflectorrr\n";

    if (number_of_rotors == 0) {
      pb.pass_value = rf.pass_value;
    } else {
      cout << rotors[number_of_rotors - 1].rotation_counter << "ciounter\n";
      if (rf.pass_value + rotors[number_of_rotors - 1].rotation_counter > 25) {
	rf.pass_value = (rf.pass_value + rotors[number_of_rotors - 1].rotation_counter) - 26;
      } else {
	rf.pass_value = rf.pass_value + rotors[number_of_rotors - 1].rotation_counter;
      };

      cout << rf.pass_value << "value after out reflector and set back\n";
      rotors[number_of_rotors - 1].pass_value = rf.pass_value;

      if (number_of_rotors > 1) {
	for (int rot = (number_of_rotors - 1) ; rot > 0; rot--) {
	  rotors[rot].REVERSE_THROUGH_ROTOR();
	  cout << rotors[rot].pass_value << "before trans for next rot\n";

	  if (rotors[rot].pass_value + rotors[rot - 1].rotation_counter > 25) {
	    rotors[rot].pass_value = (rotors[rot].pass_value + rotors[rot - 1].rotation_counter) - \
 26;
	  } else {
	    rotors[rot].pass_value = rotors[rot].pass_value + rotors[rot - 1].rotation_counter;
	  };

	  rotors[rot - 1].pass_value = rotors[rot].pass_value;
	  cout << rotors[rot - 1].pass_value << "pass value after sub\n";
	};
      };

      cout << rotors[0].pass_value << "pass value after sub\n";
      rotors[0].REVERSE_THROUGH_ROTOR();
      cout << rotors[0].pass_value << "pass value after sub\n";

      pb.pass_value = rotors[0].pass_value;
      pb.SWITCH();
    };

    pb.output_array[letter] = pb.pass_value;
    cout << pb.output_array[letter] << "pass value after sub\n";
  };

  pb.UPLOAD_TO_OUTPUT_TEXT_FILE(argv[argc - 1]);
};

