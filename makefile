EXE = enigma
CXX = g++
CXXFLAGS = -Wall -g

$(EXE): main3.o plugboard.o reflector.o rotor.o enigma.o
	$(CXX) -g main3.o plugboard.o reflector.o rotor.o enigma.o -o $(EXE)

main3.o: main3.cpp reflector.h plugboard.h rotor.h enigma.h
	$(CXX) $(CXXFLAGS) -c main3.cpp

reflector.o: reflector.cpp reflector.h
	$(CXX) $(CXXFLAGS) -c reflector.cpp

plugboard.o: plugboard.cpp plugboard.h
	$(CXX) $(CXXFLAGS) -c plugboard.cpp

rotor.o: rotor.cpp rotor.h
	$(CXX) $(CXXFLAGS) -c rotor.cpp

enigma.o: enigma.cpp enigma.h
	$(CXX) $(CXXFLAGS) -c enigma.cpp

clean:
	rm -f *.o $(EXE)
