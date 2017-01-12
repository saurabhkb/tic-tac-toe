CPP=g++
CFLAGS=-Wall -g

ttt: game.o ttt.cpp
	$(CPP) $(CFLAGS) ttt.cpp game.o -o ttt

game.o: game.cpp game.h
	$(CPP) $(CFLAGS) -c game.cpp

clean:
	rm -f *.o a.out ttt
