EXECS = crible
SRCS = crible.c utils.c main.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -I ../include
CC = gcc

all : $(EXECS) move

crible : $(OBJS)
	$(CC) -o crible $(OBJS)

move : 
	mv $(EXECS) ../bin

clean : 
	rm *.o

