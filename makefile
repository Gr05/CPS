EXECS = simon lucas TP1

all: $(EXECS)

TP1: TP1.o
	gcc $< -o TP1
TP1.o: TP1.c
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