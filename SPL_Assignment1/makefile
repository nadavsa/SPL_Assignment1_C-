all: clean bin/cRace

bin/cRace: bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o bin/EdgeWeightSelectionPolicy.o bin/MandatesSelectionPolicy.o bin/LastOfferJoinPolicy.o bin/MandatesJoinPolicy.o 
	g++ -o bin/cRace bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o bin/EdgeWeightSelectionPolicy.o bin/MandatesSelectionPolicy.o bin/LastOfferJoinPolicy.o bin/MandatesJoinPolicy.o 

bin/main.o: src/main.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/main.o src/main.cpp

bin/Agent.o: src/Agent.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Agent.o src/Agent.cpp

bin/Graph.o: src/Graph.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Graph.o src/Graph.cpp

bin/Parser.o: src/Parser.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Parser.o src/Parser.cpp

bin/Party.o: src/Party.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Party.o src/Party.cpp

bin/Simulation.o: src/Simulation.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/Simulation.o src/Simulation.cpp

bin/EdgeWeightSelectionPolicy.o: src/EdgeWeightSelectionPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/EdgeWeightSelectionPolicy.o src/EdgeWeightSelectionPolicy.cpp

bin/MandatesSelectionPolicy.o: src/MandatesSelectionPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MandatesSelectionPolicy.o src/MandatesSelectionPolicy.cpp

bin/LastOfferJoinPolicy.o: src/LastOfferJoinPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/LastOfferJoinPolicy.o src/LastOfferJoinPolicy.cpp

bin/MandatesJoinPolicy.o: src/MandatesJoinPolicy.cpp
	g++ -g -Wall -Weffc++ -std=c++11 -c -Iinclude -o bin/MandatesJoinPolicy.o src/MandatesJoinPolicy.cpp


clean:
	rm -f bin/*
