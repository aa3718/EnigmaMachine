EXE = enigma
CXX = g++
CXXFLAGS = -Wall -g

$(EXE): main3.o plugboard.o reflector.o rotor.o enigma.o
	$(CXX) -g main3.o plugboard.o reflector.o rotor.o enigma.o -o $(EXE)

main3.o: main3.cpp 
	$(CXX) $(CXXFLAGS) -c main3.cpp

reflector.o: reflector.cpp 
	$(CXX) $(CXXFLAGS) -c reflector.cpp

plugboard.o: plugboard.cpp 
	$(CXX) $(CXXFLAGS) -c plugboard.cpp

rotor.o: rotor.cpp 
	$(CXX) $(CXXFLAGS) -c rotor.cpp

enigma.o: enigma.cpp 
	$(CXX) $(CXXFLAGS) -c enigma.cpp

clean:
	rm -f *.o $(EXE)
