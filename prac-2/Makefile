output: main.o Event.o Film.o
	g++ main.o Event.o Film.o -o output
main.o: main.cpp
	g++ -c main.cpp
Event.o: Event.cpp Event.h
	g++ -c Event.cpp 
Film.o: Film.cpp Film.h
	g++ -c Film.cpp


clean:
	rm *.o output
 