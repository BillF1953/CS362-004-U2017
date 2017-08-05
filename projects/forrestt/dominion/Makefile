
CFLAGS = -Wall -fpic -coverage -lm

all: playdom player testDrawCard testBuyCard badTestDrawCard cardTest1 cardTest2 cardTest3 cardTest4 randomtestAdventurer.out randomtestcard1.out randomtestcard2.out

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

assertCustom.o: assertCustom.h assertCustom.c dominion.o
	gcc -c assertCustom.c -g $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS)
#To run playdom you need to entere: ./playdom <any integer number> like ./playdom 10*/
testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc  -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

cardTest1: cardtest1.c dominion.o rngs.o assertCustom.o
	gcc -o cardTest1 -g cardtest1.c dominion.o rngs.o assertCustom.o $(CFLAGS)

cardTest2: cardtest2.c dominion.o rngs.o assertCustom.o
	gcc -o cardTest2 -g cardtest2.c dominion.o rngs.o assertCustom.o $(CFLAGS)

cardTest3: cardtest3.c dominion.o rngs.o assertCustom.o
	gcc -o cardTest3 -g cardtest3.c dominion.o rngs.o assertCustom.o $(CFLAGS)	

cardTest4: cardtest4.c dominion.o rngs.o assertCustom.o
	gcc -o cardTest4 -g cardtest4.c dominion.o rngs.o assertCustom.o $(CFLAGS)

unitTest1: unittest1.c dominion.o rngs.o assertCustom.o
	gcc -o unitTest1 -g unittest1.c dominion.o rngs.o assertCustom.o $(CFLAGS)

unitTest2: unittest2.c dominion.o rngs.o assertCustom.o
	gcc -o unitTest2 -g unittest2.c dominion.o rngs.o assertCustom.o $(CFLAGS)

unitTest3: unittest3.c dominion.o rngs.o assertCustom.o
	gcc -o unitTest3 -g unittest3.c dominion.o rngs.o assertCustom.o $(CFLAGS)

unitTest4: unittest4.c dominion.o rngs.o assertCustom.o
	gcc -o unitTest4 -g unittest4.c dominion.o rngs.o assertCustom.o $(CFLAGS)

randomtestcard1: randomtestcard1.c dominion.o rngs.o assertCustom.o
	gcc -o randomtestcard1 -g randomtestcard1.c dominion.o rngs.o assertCustom.o $(CFLAGS)

randomtestcard2: randomtestcard2.c dominion.o rngs.o assertCustom.o
	gcc -o randomtestcard2 -g randomtestcard2.c dominion.o rngs.o assertCustom.o $(CFLAGS)

randomtestAdventurer: randomtestAdventurer.c dominion.o rngs.o assertCustom.o
	gcc -o randomtestAdventurer -g randomtestAdventurer.c dominion.o rngs.o assertCustom.o $(CFLAGS)

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS)

testBuyCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS)

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS)

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4
	./unitTest1 >> unittestresults1.out
	./unitTest2 >> unittestresults1.out
	./unitTest3 >> unittestresults1.out
	./unitTest4 >> unittestresults1.out
	./cardTest1 >> unittestresults1.out
	./cardTest2 >> unittestresults1.out
	./cardTest3 >> unittestresults1.out
	./cardTest4 >> unittestresults1.out
	gcov -b -u dominion.c >> unittestresults1.out
	cat dominion.c.gcov >> unittestresults1.out

randomtestAdventurertest: randomtestAdventurer  
	./randomtestAdventurer >> randomtestAdventurer.out
	gcov -b -u dominion.c >> randomtestAdventurer.out
	cat dominion.c.gcov >> randomtestAdventurer.out   
	
randomtestcard1test: randomtestcard1
	./randomtestcard1 >> randomtestcard1.out
	gcov -b -u dominion.c >> randomtestcard1.out
	cat dominion.c.gcov >> randomtestcard1.out

randomtestcard2test: randomtestcard2
	./randomtestcard2 >> randomtestcard2.out
	gcov -b -u dominion.c >> randomtestcard2.out
	cat dominion.c.gcov >> randomtestcard2.out

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS)

clean:
	rm -f *.o playdom.exe playdom player player.exe  *.gcov *.gcda *.gcno *.so testDrawCard badTestDrawCard testDrawCard.exe unitTest1 unitTest2 unitTest3 unitTest4 cardTest1 cardTest2 cardTest3 cardTest4 randomtestcard1 randomtestcard2 randomtestcardAdventurer

