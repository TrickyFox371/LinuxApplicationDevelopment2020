GENERATES = preload.so 123 FIX 123FIX fix
TRASH = *.o *~ o.*
LOG = log

all: preload.c
	cc -shared -fPIC preload.c -ldl -o preload.so
	
test:
	make allclean
	make all
	touch 123
	touch FIX
	touch 123FIX
	touch fix
	-LD_PRELOAD=`pwd`/preload.so rm 123
	test -f 123 && echo "123 was not deleted" >>$(LOG) || echo "123 was deleted" >>$(LOG)
	-LD_PRELOAD=`pwd`/preload.so rm FIX
	test -f FIX && echo "FIX was not deleted" >>$(LOG) || echo "FIX was deleted" >>$(LOG)
	-LD_PRELOAD=`pwd`/preload.so rm 123FIX
	test -f 123FIX && echo "123FIX was not deleted" >>$(LOG) || echo "123FIX was deleted" >>$(LOG)
	-LD_PRELOAD=`pwd`/preload.so rm fix
	test -f fix && echo "fix was not deleted" >>$(LOG) || echo "fix was deleted" >>$(LOG)

clean:
	rm -f $(TRASH)
	
distclean:
	rm -rf $(GENERATES)

cleanlog:
	rm -f $(LOG)
	
allclean: clean distclean cleanlog
