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
  static const int alphabet = 26;
  int number_of_rotors;
  int error_code;
  Plugboard pb;
  Reflector rf;
  std::vector<Rotor> rotors;

  // Creates and runs an enigma
  int ENIGMA_START(int argc, char **argv); 
};

#endif
