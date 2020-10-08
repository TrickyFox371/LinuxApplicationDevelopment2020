GENERATES = prog prog-a prog-so README *.so
TRASH = *.o *~ o.* *.a file*
LOG = log
CFLAGS = -Wall -fPIC

all: README prog prog-a prog-so

test:
	make distclean all
	./prog >> file11
	./prog 1 >> file12
	./prog 1 2 3 >> file13
	rm prog
	mv prog-a prog
	./prog >> file21
	./prog 1 >> file22
	./prog 1 2 3 >> file23
	rm prog
	mv prog-so prog
	LD_LIBRARY_PATH=`pwd` ./prog >> file31
	LD_LIBRARY_PATH=`pwd` ./prog 1 >> file32
	LD_LIBRARY_PATH=`pwd` ./prog 1 2 3 >> file33
	cmp file11 file21 && echo "Correct prog prog-a" >>log || echo "Error prog prog-a" >>log
	cmp file11 file31 && echo "Correct prog prog-so" >>log || echo "Error prog prog-so" >>log
	cmp file21 file31 && echo "Correct prog-a prog-so" >>log || echo "Error prog-a prog-so" >>log
	cmp file12 file22 && echo "Correct prog x prog-a x" >>log || echo "Error prog x prog-a x" >>log
	cmp file12 file32 && echo "Correct prog x prog-so x" >>log || echo "Error prog x prog-so x" >>log
	cmp file22 file32 && echo "Correct prog-a x prog-so x" >>log || echo "Error prog-a x prog-so x" >>log
	cmp file13 file23 && echo "Correct prog x x x prog-a x x x" >>log || echo "Error prog x x x prog-a x x x" >>log
	cmp file13 file33 && echo "Correct prog x x x prog-so x x x" >>log || echo "Error prog x x x prog-so x x x" >>log
	cmp file23 file33 && echo "Correct prog-a x x x prog-so x x x" >>log || echo "Error prog-a x x x prog-so x x x" >>log
	make logsaveclean

prog: const.o fun.o prog.o

prog-a: libout.a prog.o
	cc -L. prog.o -lout -o prog-a

prog-so: liboutput.so prog.o
	cc -L. prog.o -lout -o prog-so

libout.a: const.o fun.o
	ar -rcs libout.a const.o fun.o

liboutput.so: const.o fun.o
	cc -shared fun.o const.o -o libout.so

README: prog
	./$< 2> $@

fun.o: outlib.h

clean:
	rm -f $(TRASH)

logsaveclean: clean
	rm -rf $(GENERATES)

distclean: logsaveclean
	rm -f $(LOG)


