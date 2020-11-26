TRASH = *.o *~ o.* prog
CFLAGS = -lglib-2.0

all: prog.c
	cc prog.c `pkg-config --cflags glib-2.0` $(CFLAGS) -o prog
	
clean:
	rm -f $(TRASH)