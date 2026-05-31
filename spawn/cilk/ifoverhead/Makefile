.PHONY: serial

CC=		/opt/$$(ls /opt | grep "opencilk")/bin/clang # /opt/opencilk-2/bin/clang 
CFLAGS=		-fopencilk -O3 -Og -g # -fcilktool=cilkscale -lm -Wall -Wextra -Wconversion -std=c11 -Werror
SOURCE=		$(wildcard *.c)
TARGETS=	$(SOURCE:.c=)	

EXECS := $(foreach s,$(TARGETS),$(shell echo $(basename $(s)) | cut -c1-3))

ove: overhead_calc.c
	$(CC) $(CFLAGS) overhead_calc.c -o ove

clean:
	rm -f $(EXECS) *.s *.o *_.c lib*.so lib*.a