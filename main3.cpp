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
    return INSUFFICIENT_NUMBER_OF_PARAMETERS;
  };
 
  Enigma enigma;
  enigma.ENIGMA_START(argc, argv);

  if (enigma.error_code == INVALID_INPUT_CHARACTER) {
    cout << "INVALID_INPUT_CHARACTER: Input is not a character.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == INVALID_INDEX) {
    cout << "INVALID_INDEX: Input out of bounds.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == NON_NUMERIC_CHARACTER) {
    cout << "NON_NUMERIC_CHARACTER: There is an non numeric character in one of the file.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == IMPOSSIBLE_PLUGBOARD_CONFIGURATION) {
    cout << "IMPOSSIBLE_PLUGBOARD_CONFIRGURATION: There is a duplicate value present in plugboard file.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS) {
    cout << "INCORRECT_NUMBER_OF_PLUGBOARD_PARAMETERS: There are not an even number of pairs in plugboard file.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == INVALID_ROTOR_MAPPING) {
    cout << "INVALID_ROTOR_MAPPING: There are duplicates in the rotor file.\n";  
    return enigma.error_code;
  };

  if (enigma.error_code == NO_ROTOR_STARTING_POSITION) {
    cout << "NO_ROTOR_STARTING_POSITION: There are not enough starting positions for your rotors.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == INVALID_REFLECTOR_MAPPING) {
    cout << "INVALID_REFLECTOR_MAPPING: There are duplicates in the reflector file.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS) {
    cout << "INCORRECT_NUMBER_OF_REFLECTOR_PARAMETERS: Wrong amount of elements in reflector.\n";
    return enigma.error_code;
  };

  if (enigma.error_code == ERROR_OPENING_CONFIGURATION_FILE) {
    cout << "ERROR_OPENING_CONFIGURATION_FILE: Unable to open one of the files .\n";
    return enigma.error_code;
  };
  
  return NO_ERROR;
};
