main: main.o funcs.o
	g++ -o main main.o funcs.o

tests: tests.o funcs.o
	g++ -o tests tests.o funcs.o

funcs.o: funcs.cpp funcs.h time.h movie.h timeslot.h
	g++ -c -std=c++11 funcs.cpp

main.o: main.cpp funcs.h time.h movie.h timeslot.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp doctest.h funcs.h time.h movie.h timeslot.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f main.o funcs.o tests.o main tests
