add_executable(myExecutable
    test.cpp
)
set(HEADER_FILES
	catch.hpp
)

add_library(foo TheaterUtility)
target_link_libraries(myExecutable SOURCE_FILES)
target_link_libraries(myExecutable foo)

add_executable(tests test.cpp)