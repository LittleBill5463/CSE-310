all: main

main: main.o
	g++ -o main main.o

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *.o main
