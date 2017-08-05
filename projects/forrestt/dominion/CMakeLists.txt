cmake_minimum_required(VERSION 3.6)
project(Program3)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES dominion.c dominion.h rngs.c assertCustom.c randomtestcard1.c randomtestcard2.c randomtestAdventurer.c cardtest1.c)
set(TEST_FILES cardtest2.c cardtest3.c cardtest4.c unittest1.c unittest2.c unittest3.c unittest4.c assertCustomUnit.c)
add_executable(Program3 ${SOURCE_FILES} ${TEST_FILES})