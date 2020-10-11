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
	cmp file11 file21 && echo "Correct prog prog-a" >>$(LOG) || echo "Error prog prog-a" >>$(LOG)
	cmp file11 file31 && echo "Correct prog prog-so" >>$(LOG) || echo "Error prog prog-so" >>$(LOG)
	cmp file21 file31 && echo "Correct prog-a prog-so" >>$(LOG) || echo "Error prog-a prog-so" >>$(LOG)
	cmp file12 file22 && echo "Correct prog x prog-a x" >>$(LOG) || echo "Error prog x prog-a x" >>$(LOG)
	cmp file12 file32 && echo "Correct prog x prog-so x" >>$(LOG) || echo "Error prog x prog-so x" >>$(LOG)
	cmp file22 file32 && echo "Correct prog-a x prog-so x" >>$(LOG) || echo "Error prog-a x prog-so x" >>$(LOG)
	cmp file13 file23 && echo "Correct prog x x x prog-a x x x" >>$(LOG) || echo "Error prog x x x prog-a x x x" >>$(LOG)
	cmp file13 file33 && echo "Correct prog x x x prog-so x x x" >>$(LOG) || echo "Error prog x x x prog-so x x x" >>$(LOG)
	cmp file23 file33 && echo "Correct prog-a x x x prog-so x x x" >>$(LOG) || echo "Error prog-a x x x prog-so x x x" >>$(LOG)
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


