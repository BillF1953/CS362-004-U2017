//
// Created by tylerf on 7/15/17.
//

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertCustom.h"
#include <stdlib.h>
#define NO_CARDS 0
#define TRUE 1
#define FALSE 0

void invariant_tests(int thisPlayer,struct gameState G, struct gameState testG){

    assertCustom(testG.handCount[thisPlayer] == G.handCount[thisPlayer], "Receives No cards");
    assertCustom(testG.deckCount[thisPlayer] == G.deckCount[thisPlayer], "Deck has the same number of cards");
    assertCustom(testG.coins == G.coins, "No extra coins received");
    assertCustom(testG.whoseTurn == G.whoseTurn, "Same Players Turn");
    assertCustom(testG.numActions == G.numActions, "Number of actions" );
    assertCustom(testG.numBuys == G.numBuys, "Number of Buys" );
    assertCustom(testG.playedCardCount == G.playedCardCount, "Number of Cards Discarded");
    assertGameState(thisPlayer+1, &G, &testG);



}



int main() {

    int seed = 1000;
    int numPlayers = 2;
    int thisPlayer = 0;
    int bonus = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, embargo, village, minion, mine, cutpurse,
                 sea_hag, tribute, smithy, council_room};

    // initialize a game state and player cards
    initializeGame(numPlayers, k, seed, &G);
    printf("----------------- Testing isGameOver----------------\n");
    //Game ends when no province cards left in the pile or 3 piles have no cards
    //copy game state
    memcpy(&testG, &G, sizeof(struct gameState));



    testG.supplyCount[province] = NO_CARDS;

    assertCustom(isGameOver(&testG) == TRUE, "Game over: No province Cards");
    invariant_tests(thisPlayer, G, testG);

    memcpy(&testG, &G, sizeof(struct gameState));

    testG.supplyCount[curse] = NO_CARDS;
    testG.supplyCount[adventurer] = NO_CARDS;
    assertCustom(isGameOver(&testG)== FALSE, "Game over: Curse and Adventurer have no Cards");
    invariant_tests(thisPlayer, G, testG);

    testG.supplyCount[gold] = NO_CARDS;
    assertCustom(isGameOver(&testG)== TRUE, "Game over: Curse, Adventurer, Gold have no Cards");
    invariant_tests(thisPlayer, G, testG);

    testG.supplyCount[province] = NO_CARDS;
    assertCustom(isGameOver(&testG)== TRUE, "Game over: Curse, Adventurer, Gold and Province no Cards");
    invariant_tests(thisPlayer, G, testG);


    return 0;
}