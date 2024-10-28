all :PJ3

PJ3: main.o util.o heap.o 
	g++ -Wall -o PJ3 main.o util.o heap.o 

main.o: main.cpp main.h util.h heap.h data_structures.h
	g++ -Wall -c main.cpp

util.o: util.cpp util.h heap.h data_structures.h
	g++ -Wall -c util.cpp
	
heap.o: heap.cpp heap.h data_structures.h
	g++ -Wall -c heap.cpp

clean:
	rm *.o PJ3