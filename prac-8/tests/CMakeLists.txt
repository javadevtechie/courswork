add_executable(myExecutable
    catch.hpp
    test.cpp
    TheaterUtility.h 
    TheaterUtility.cpp test.cpp Customer.cpp Customer.h TheaterBooking.cpp TheaterBooking.h Event.cpp Event.h Film.cpp Film.h LiveMusic.cpp LiveMusic.h StandupComedy.h StandupComedy.cpp
)



add_executable(tests test.cpp)