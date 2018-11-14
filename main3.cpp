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

  if (argc == 0) {
    cout << "INSUFFICIENT_NUMBER_OF_PARAMETERS: There are no files in the command line.\n";
    return 1;
  };

 
  Enigma enigma;
  enigma.ENIGMA_START(argc, argv);

  
   if (enigma.error_code != 0) {
      return enigma.error_code;
     };

  return 0;
};
