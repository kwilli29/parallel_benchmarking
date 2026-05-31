.PHONY: serial

CC=		gcc
CFLAGS=		-fopenmp -Wall -O3 -Og -g
INCFILES=   ../../../include/numthreads.c
SOURCE=		$(wildcard *.c)
TARGETS=	$(SOURCE:.c=)	

EXECS := $(foreach s,$(TARGETS),$(shell echo $(basename $(s)) | cut -c1-3))

ove: overhead_calc.c
	$(CC) $(CFLAGS) $(INCFILES) overhead_calc.c -o ove

clean:
	rm -f $(EXECS) *.s *.o *_.c lib*.so lib*.a