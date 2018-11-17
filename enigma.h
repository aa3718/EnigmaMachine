#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include "plugboard.h"
#include "reflector.h"
#include "rotor.h"
#include "errors.h"


class Enigma {
 public:
  int number_of_rotors;
  int error_code;
  Plugboard pb;
  Reflector rf;
  std::vector<Rotor> rotors;
  int ENIGMA_START(int argc, char **argv); 
};

#endif
