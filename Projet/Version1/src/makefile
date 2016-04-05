EXECS = jeu
SRCS = main.c liste_navires.c maillon.c jeu.c grille.c gestion_fichier.c navires.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -I ../include
CC = gcc

all : $(EXECS) move

jeu : $(OBJS)
	$(CC) -o jeu $(OBJS)

move : 
	mv $(EXECS) ../bin/jeu

clean : 
	rm *.o ../bin/$(EXECS)

