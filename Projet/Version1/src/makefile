EXECS = jeu
SRCS = main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -I ../include
CC = gcc

all : $(EXECS) move

jeu : $(OBJS)
	$(CC) -o jeu $(OBJS)

move : 
	mv $(EXECS) ../bin

clean : 
	rm *.o

