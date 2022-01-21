output: main.o Event.o Film.o TheaterBooking.o StandupComedy.o LiveMusic.o
	g++ main.o Event.o Film.o TheaterBooking.o StandupComedy.o LiveMusic.o -o output
main.o: main.cpp
	g++ -c main.cpp
Event.o: Event.cpp Event.h
	g++ -c Event.cpp 
Film.o: Film.cpp Film.h
	g++ -c Film.cpp
TheaterBooking.o: TheaterBooking.cpp TheaterBooking.h
	g++ -c TheaterBooking.cpp
StandupComedy.o: StandupComedy.cpp StandupComedy.h
	g++ -c StandupComedy.cpp
LiveMusic.o: LiveMusic.cpp LiveMusic.h
	g++ -c LiveMusic.cpp
clean:
	rm *.o output
 