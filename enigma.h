#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"


class Enigma {
 public:
  int number_of_rotors;
  int error_code;
  Plugboard pb;
  Reflector rf;
  int ENIGMA_START(int argc, char **argv); 
};

#endif
