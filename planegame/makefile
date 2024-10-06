CC = gcc
CFLAGS = -g -Wall

all: planegame
	./planegame NULL

planegame: planegame.o boardmkr.o utils.o
	$(CC) $(CFLAGS) -o planegame planegame.o boardmkr.o utils.o

planegame.o: planegame.c
	$(CC) $(CFLAGS) -c planegame.c
	@echo "planegame.o made"

boardmkr.o: boardmkr.h boardmkr.c
	@echo "making boardmkr"
	$(CC) $(CFLAGS) -c boardmkr.c

utils.o: utils.c utils.h lookuptables.h planegame.h
	@echo "making utlis"
	$(CC) $(CFLAGS) -c utils.c


clean:
	@echo "cleanninggg"
	rm planegame.o boardmkr.o utils.o planegame
