all: piodisp

piodisp: clock.pio.h piodisp.c piolib.c pio_rp1.c
	gcc -O2 -Iinclude -Wall -o piodisp piodisp.c piolib.c pio_rp1.c

clean: always
	rm -f *~ piodisp