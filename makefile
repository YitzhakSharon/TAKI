CXX=g++
CXXFLAGS=-std=c++0x -Werror -Wvla -Wall
 
a.out: Card.o Player.o Game.o main.o
	$(CXX) $(CXXFLAGS) Card.o Player.o Game.o main.o -o a.out

main.o: main.cpp 
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) -c Card.cpp -o Card.o

Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o

Game.o: Game.cpp Game.h
	$(CXX) $(CXXFLAGS) -c Game.cpp -o Game.o

clean:
	rm *.o 