//
// Created by Tyler on 7/14/2017.
//

#ifndef DOMINION_ASSERTCUSTOM_H
#define DOMINION_ASSERTCUSTOM_H
#define NUM_CARDS 27
void assertCustomR(int boolean, char * message, struct gameState * oldG, struct gameState* newG);

void assertGameStateR(int player, struct gameState * oldG, struct gameState * newG);

#endif //DOMINION_ASSERTCUSTOM_H
