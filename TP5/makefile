EXECS = simon TP3

all: $(EXECS) clean

TP1: TP3.o
	gcc $< -o TP3
TP1.o: TP3.c
	gcc -c $<
simon: simon.o
	gcc $< -o simon
simon.o: simon.c
	gcc -c $<
lucas: lucas.o
	gcc $< -o lucas
lucas.o: lucas.c
	gcc -c $<

clean:
	rm -rf *.o

mrporper: clean
	rm -rf $(EXECS)
