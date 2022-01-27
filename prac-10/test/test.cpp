#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <vector>
#include "../TheaterUtility.h"
#include "../TheaterBooking.h"
#include <typeinfo>

using namespace std;

TheaterUtility th;
TheaterBooking tb;
TEST_CASE("DummyEvent"){
    
    REQUIRE("course"==th.getStrings());
}

TEST_CASE("Check tokenization"){
   vector<string> tk =th.getStringToken("sdf|sdfd|sdfdsf|sdfsdf");
    REQUIRE(tk[0]=="sdf");
}
TEST_CASE("isValid EventId"){
    bool d=th.isValidEventId("4300");
     cout<<d;
    REQUIRE(d==false);

}
TEST_CASE("Check list of Event"){
    tb.listOfAllEvents();
}

TEST_CASE("Rand"){
    int a=th.getRand();
    REQUIRE(typeid(a).name()=="i");
}