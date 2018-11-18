#include "enigma.h"
#include "errors.h"
#include <iostream>
#include <vector>
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

  cout << number_of_rotors << " Number of rotors\n"; ///////////////
  
 // Retutrning error value if there is an issue with plugboard file

  if (pb.UPLOAD_PLUGBOARD(argv[1]) != 0) {
   error_code = pb.UPLOAD_PLUGBOARD(argv[1]);
   return error_code;
  };

  if (pb.PLUGBOARD_ERRORS() != 0) {
    error_code = pb.PLUGBOARD_ERRORS();
      return error_code;
    };

 // Creating new instances of rotors
  for (int number = 0; number < number_of_rotors; number++) {
    Rotor rotor;
    rotors.push_back(rotor);
  };

  // Check all files for errors by uploading before implementation 
  if (number_of_rotors != 0) {
    for (int rot = 0 ; rot < number_of_rotors; rot++) {
      if (rotors[rot].UPLOAD_ROTOR_FILE_TO_ARRAY(argv[2 + (number_of_rotors - rot)])) {
	    error_code = rotors[rot].UPLOAD_ROTOR_FILE_TO_ARRAY(argv[2 + (number_of_rotors - rot)]);
	    return error_code;
	  };
	  
	  if (rotors[rot].UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(argv[number_of_rotors + 3])) {
	    error_code = rotors[rot].UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(argv[number_of_rotors + 3]);
	    return error_code;
	  };

	  if (rotors[rot].ROTOR_ERRORS() != 0) {
	    error_code = rotors[rot].ROTOR_ERRORS();
	    return error_code;
	  };
	  
	  if (rotors[rot].POSITION_ERRORS(number_of_rotors) != 0) {
	      error_code = rotors[rot].POSITION_ERRORS(number_of_rotors);
	      return error_code;
	    };
	  
	  rotors[rot].ASSIGN(number_of_rotors - 1 - rot);

	  if (rf.UPLOAD_REFLECTOR(argv[2]) != 0) {
	    error_code = rf.UPLOAD_REFLECTOR(argv[2]);
	    return error_code;
      };

      if (rf.REFLECTOR_ERRORS() != 0) {
	error_code = rf.REFLECTOR_ERRORS();
	return error_code;
      };
  };
  };
  
 // Uploading input text file depending on argc length
  if (pb.UPLOAD_VALUE() == INVALID_INPUT_CHARACTER) {
    error_code = pb.UPLOAD_VALUE();
    return error_code;
  };
 
  // For loop for each single input character
  for (int letter = 0; letter < pb.input_counter; letter++) {
    cout << pb.input_array[letter] << " input letter.\n"; ///////////
    
    pb.ASSIGN((pb.input_array[letter]));
    pb.SWITCH();

    cout << pb.pass_value << " After plugboard\n"; //////////////////

    if (number_of_rotors != 0) {
      
      for (int rot = 0 ; rot < number_of_rotors; rot++) {
	
	if (rot == 0) {
	  rotors[rot].pass_value = pb.pass_value;
	} else {
	  rotors[rot].pass_value = rotors[rot - 1].pass_value;
	};

	cout << rotors[rot].pass_value << " Rotor pass value\n";
	/*
	if (letter == 0) {
	  
	  if (rotors[rot].UPLOAD_ROTOR_FILE_TO_ARRAY(argv[2 + (number_of_rotors - rot)])) {
	    error_code = rotors[rot].UPLOAD_ROTOR_FILE_TO_ARRAY(argv[2 + (number_of_rotors - rot)]);
	    return error_code;
	  };
	  
	  if (rotors[rot].UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(argv[number_of_rotors + 3])) {
	    error_code = rotors[rot].UPLOAD_ROTOR_POSITION_FILE_TO_ARRAY(argv[number_of_rotors + 3]);
	    return error_code;
	  };

	  if (rotors[rot].ROTOR_ERRORS() != 0) {
	    error_code = rotors[rot].ROTOR_ERRORS();
	    return error_code;
	  };

	  if (rotors[rot].POSITION_ERRORS(number_of_rotors) != 0) {
	      error_code = rotors[rot].POSITION_ERRORS(number_of_rotors);
	      return error_code;
	    };
	  
	  rotors[rot].ASSIGN(number_of_rotors - 1 - rot);
	  cout << "HERE\n";
	};
	*/

	if (rot == 0) {
	  rotors[rot].CLICK();
	};
	
	if (rot != 0 && rotors[rot - 1].at_notch == 1) {
	  rotors[rot].CLICK();
	  rotors[rot - 1].at_notch = 0;
	};

	rotors[rot].GOING_THROUGH_ROTOR();
	rotors[rot].REFRAME_FORWARD();
	cout <<  rotors[rot].pass_value << " pass value after rotor reframe\n";
      };
    };

// Upload the reflector
/*
    if (letter == 0) {
      if (rf.UPLOAD_REFLECTOR(argv[2]) != 0) {
	error_code = rf.UPLOAD_REFLECTOR(argv[2]);
	return error_code;
      };

      if (rf.REFLECTOR_ERRORS() != 0) {
	error_code = rf.REFLECTOR_ERRORS();
	return error_code;
      };
    };
*/
    
    if (number_of_rotors == 0) {
      rf.pass_value = pb.pass_value;
    } else {
      rf.pass_value = rotors[number_of_rotors - 1].pass_value;
    };

    rf.SWITCH();

    if (number_of_rotors == 0) {
      pb.pass_value = rf.pass_value;
    } else {
      if (rf.pass_value + rotors[number_of_rotors - 1].rotation_counter > 25) {
	rf.pass_value = (rf.pass_value + rotors[number_of_rotors - 1].rotation_counter) - 26;
      } else {
	rf.pass_value = rf.pass_value + rotors[number_of_rotors - 1].rotation_counter;
      };

      cout << rf.pass_value << " RF pass value after switch and reframe\n";
      rotors[number_of_rotors - 1].pass_value = rf.pass_value;

      if (number_of_rotors > 1) {
	for (int rot = (number_of_rotors - 1) ; rot > 0; rot--) {
	  rotors[rot].REVERSE_THROUGH_ROTOR();

	  if (rotors[rot].pass_value + rotors[rot - 1].rotation_counter > 25) {
	    rotors[rot].pass_value = (rotors[rot].pass_value + rotors[rot - 1].rotation_counter) - 26;
	  } else {
	    rotors[rot].pass_value = rotors[rot].pass_value + rotors[rot - 1].rotation_counter;
	  };

	  rotors[rot - 1].pass_value = rotors[rot].pass_value;
	};
      };

      rotors[0].REVERSE_THROUGH_ROTOR();

      pb.pass_value = rotors[0].pass_value;
      cout << pb.pass_value << " Value going in PB \n";
    };
    pb.SWITCH();
    pb.output_array[letter] = pb.pass_value;
    cout << pb.pass_value << " Final value.\n";
  };

  pb.UPLOAD_TO_OUTPUT_TEXT_FILE();

  return 0;
};
