test: prog.o code.o
	        gcc prog.o code.o -o test
prog.o: prog.c code.h
	        gcc -c prog.c -o prog.o
code.o: code.c code.h
	        gcc -c code.c -o code.o
clean:
	        rm -f *.o test
