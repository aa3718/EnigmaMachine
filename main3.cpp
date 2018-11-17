#include "plugboard.h"
#include "rotor.h"
#include "reflector.h"
#include "errors.h"
#include "enigma.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


int main(int argc, char **argv) {
  
  if (argc < 3) {
    cout << "INSUFFICIENT_NUMBER_OF_PARAMETERS: There are no files in the command line.\n";
    return 1;
  };

 
  Enigma enigma;
  enigma.ENIGMA_START(argc, argv);

  
   if (enigma.error_code == 2) {
     cout << "INVALID_INPUT_CHARACTER: Input is not a character.\n";
      return enigma.error_code;
     };

   if (enigma.error_code == 3) {
     cout << "INVALID_INDEX: Input out of bounds.\n";
     return enigma.error_code;
   };

     if (enigma.error_code == 4) {
       cout << "NON_NUMERIC_CHARACTER: There is an non numeric character in one of the file.\n";
      return enigma.error_code;
     };

      if (enigma.error_code == 5) {
	cout << "IMPOSSIBLE_PLUGBOARD_CONFIRGURATION: There is a duplicate value present in plugboard file.\n";
      return enigma.error_code;
     };

       if (enigma.error_code == 6) {
	 cout << "INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS: There are not an even number of pairs in plugboard file.\n";
      return enigma.error_code;
     };

        if (enigma.error_code == 7) {
	  cout << "INVALID_ROTOR_MAPPING: There are duplicates in the rotor file.\n";  
      return enigma.error_code;
     };

	 if (enigma.error_code == 8) {
	   cout << "NO_ROTOR_STARTING_POSITION: There are not enough starting positions for your rotors.\n";
      return enigma.error_code;
     };

	  if (enigma.error_code == 9) {
	    cout << "INVALID_REFLECTOR_MAPPING: There are duplicates in the reflector file.\n";
      return enigma.error_code;
     };

	  if (enigma.error_code == 10) {
	    cout << "INVALID_REFLECTOR_MAPPING: There are duplicates in the reflector file.\n";
      return enigma.error_code;
     };

	  if (enigma.error_code == 11) {
	    cout << "ERROR_OPENING_CONFIGURATION_FILE: Unable to open one of the files .\n";
      return enigma.error_code;
     };
	    

  return 0;
};
