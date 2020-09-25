export CC=g++
export CFLAGS=-W -Wall -std=c++11 -pedantic


	
main: main.o ticket.o consigne.o
	$(CC) -o main main.o ticket.o consigne.o $(CFLAGS)

main.o: main.cpp ticket.hpp consigne.hpp
	$(CC) -o main.o -I. -c main.cpp $(CFLAGS)

ticket.o: ticket.hpp ticket.cpp
	$(CC) -o ticket.o -I. -c ticket.cpp $(CFLAGS)

consigne.o: consigne.hpp consigne.cpp 
	$(CC) -o consigne.o -I. -c consigne.cpp $(CFLAGS)

main_V: main_V.o ticket.o vconsigne.o
	$(CC) -o main_V main_V.o ticket.o vconsigne.o $(CFLAGS)

main_V.o: main_V.cpp ticket.hpp vconsigne.hpp
	$(CC) -o main_V.o -I. -c main_V.cpp $(CFLAGS)

vconsigne.o: vconsigne.hpp vconsigne.cpp 
	$(CC) -o vconsigne.o -I. -c vconsigne.cpp $(CFLAGS)

clean:
	rm -rf *.o *~ main_V
	rm -rf *.o *~ main
	
