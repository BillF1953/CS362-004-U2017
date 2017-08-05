//
// Created by tylerf on 8/2/17.
//

#ifndef PROGRAM3_ASSERTCUSTOMUNIT_H
#define PROGRAM3_ASSERTCUSTOMUNIT_H
#include "assertCustomUnit.c"

void assertCustom(int boolean, char * message);

void assertGameState(int player, struct gameState * oldG, struct gameState * newG);


#endif //PROGRAM3_ASSERTCUSTOMUNIT_H
