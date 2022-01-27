#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

#include "../TheaterUtility.h"

using namespace std;


TEST_CASE("Add Event Test"){
    TheaterUtility th;
    REQUIRE(1==1);
}

TEST_CASE("Update event"){
    REQUIRE(0==1);
}