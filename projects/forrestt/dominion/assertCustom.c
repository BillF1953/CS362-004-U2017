//
// Created by Tyler on 7/14/2017.
//
#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertCustom.h"
#include <stdlib.h>

#define TRUE   1
#define FALSE  0
#define DEBUG 0


void dumpVariables(struct gameState * oldG, struct gameState* newG){

    int player, newCards, oldCards;
    printf("Number of Players: Old %d New %d\n", oldG->numPlayers, newG->numPlayers);
    printf("Whose Turn: Old %d New %d \n", oldG->whoseTurn, newG->whoseTurn);
    printf("Phase: Old %d New %d\n", oldG->phase, newG->phase);
    printf("NumActions: Old %d New %d \n", oldG->numActions, newG->numActions);
    printf("Number of Buys: Old %d New %d\n", oldG->numBuys, newG->numBuys);
    printf("Played Card Count: Old %d New %d \n", oldG->playedCardCount, newG->playedCardCount);


    for(player=0; player < oldG->numPlayers; player++) {
        printf("Player %d\n", player);
        printf("Hand Count: Old %d New %d\n", oldG->handCount[player], newG->handCount[player]);
        printf("Deck Count: Old %d New %d \n", oldG->deckCount[player], newG->deckCount[player]);
        printf("Discard Count: Old %d New %d \n", oldG->discardCount[player], newG->discardCount[player]);
    }

    player=oldG->whoseTurn;

    printf("Cards in Hand: Old Player ");

    for(oldCards = 0; oldCards < oldG->handCount[player]; oldCards++){

        printf("%d\t", oldG->hand[player][oldCards]);

    }
    printf("\n");

    printf("Cards in Hand: New Player ");

    for(newCards = 0; newCards < newG->handCount[player]; newCards++){

      printf("%d\t", newG->hand[player][newCards]);
    }
     printf("\n");


    printf("Cards in Deck: Old Player ");

    for(oldCards = 0; oldCards < oldG->deckCount[player]; oldCards++){

        printf("%d\t", oldG->deck[player][oldCards]);

    }
    printf("\n");

    printf("Cards in Deck: New Player ");

    for(newCards = 0; newCards < newG->deckCount[player]; newCards++){

        printf("%d\t", newG->deck[player][newCards]);
    }
    printf("\n");

    printf("Cards in Discard: Old Player ");

    for(oldCards = 0; oldCards < oldG->discardCount[player]; oldCards++){

        printf("%d\t", oldG->discard[player][oldCards]);

    }
    printf("\n");

    printf("Cards in Discards: New Player ");

    for(newCards = 0; newCards < newG->discardCount[player]; newCards++){

        printf("%d\t", newG->discard[player][newCards]);
    }
    printf("\n");

    printf("Played Cards: Old Player ");

    for(oldCards = 0; oldCards < oldG->playedCardCount; oldCards++){

        printf("%d\t", oldG->playedCards[oldCards]);

    }
    printf("\n");

    printf("Played Cards: New Player ");

    for(newCards = 0; newCards < newG->playedCardCount; newCards++){

        printf("%d\t", newG->playedCards[newCards]);
    }
    printf("\n");


}






void assertCustomR(int boolean, char * message, struct gameState * oldG, struct gameState* newG){

    if(DEBUG){
        printf("TEST PASSED: %s\n", message );


    }

    if(boolean == FALSE){

        printf("TEST FAILED: %s\n", message );
        dumpVariables(oldG, newG);

    }

}

void assertGameStateR(int player, struct gameState * oldG, struct gameState * newG){
    int failed = FALSE;
    if(oldG->handCount[player] !=   newG->handCount[player]){
        printf("TEST FAILED: Hand Count for non-action player Changed\n");
        failed = TRUE;
    }
    if(oldG->numPlayers != newG->numPlayers){
        printf("TEST FAILED: Number of Players in Game Changed\n");
        failed = TRUE;
    }
    if(oldG->deckCount[player] !=   newG->deckCount[player]){
        printf("TEST FAILED: Deck Count for non-action player Changed\n");
        failed = TRUE;
    }
    int i;
    for(i = curse; i < NUM_CARDS; i++){
        if(oldG->supplyCount[i] != newG->supplyCount[i]){
            printf("TEST FAILED Card %d Supply Count Changed\n", i);
           failed = TRUE;
        }
        if(oldG->embargoTokens[i] != newG->embargoTokens[i]){
            printf("TEST FAILED Embargo Token on Card %d Changed\n", i);
            failed = TRUE;

        }
    }


    if(failed){
      dumpVariables(oldG, newG);
    }
    if(DEBUG && !failed){
        printf("GAME STATE INVARIANT TEST PASSED\n");
        dumpVariables(oldG, newG);
    }

}


