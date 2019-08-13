#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <string>

#include "Train_tests.hpp"

using namespace std;

void Increment(int& number)
{
  number++;
}

TEST_CASE( "Increment Number", "[Increment]" )
{
    int a(5);
    int expectedResult(6);
    Increment(a);
    REQUIRE( a == expectedResult );
}
