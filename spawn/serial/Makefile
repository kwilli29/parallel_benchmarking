CC=		gcc 
CFLAGS=		-O3 -Og -g -Wall -Wconversion -lm
SOURCE=		$(wildcard *.c)
TARGETS=	$(SOURCE:.c=)	

EXECS := $(foreach s,$(TARGETS),$(shell echo $(basename $(s)) | cut -c1-3))

build: $(TARGETS)

01A: 01A_spawntime_after_sequential_serial.c
	$(CC) $(CFLAGS) 01A_spawntime_after_sequential_serial.c -o 01A

01C: 01C_spawntime_after_for_serial.c
	$(CC) $(CFLAGS) 01C_spawntime_after_for_serial.c -o 01C

01D: 01D_spawntime_after_cilkfor_1_serial.c
	$(CC) $(CFLAGS) 01D_spawntime_after_cilkfor_1_serial.c -o 01D

05A: 05A_spawntime_window_serial.c
	$(CC) $(CFLAGS) 05A_spawntime_window_serial.c -o 05A

04B: 04B_spawntime_beforefunc_cilkscope_serial.c
	$(CC) $(CFLAGS) 04B_spawntime_beforefunc_cilkscope_serial.c -o 04B

all:
	@for s in $(SOURCE); do \
		name=$$(basename $$s); \
		exe=$$(echo $$name | cut -c1-3); \
		$(CC) $(CFLAGS) $$s -o $$exe; \
	done

#clang  -fopenmp -lomp -O3 -Og -g omp/fib_omp.c -o ompfib
# 

# For compilers to find libomp you may need to set:
#  export LDFLAGS="-L/opt/homebrew/opt/libomp/lib"
#  export CPPFLAGS="-I/opt/homebrew/opt/libomp/include"

#If you need to have llvm first in your PATH, run:
#  echo 'export PATH="/opt/homebrew/opt/llvm/bin:$PATH"' >> /Users/Kelly/.bash_profile

#For compilers to find llvm you may need to set:
#  export LDFLAGS="-L/opt/homebrew/opt/llvm/lib"
#  export CPPFLAGS="-I/opt/homebrew/opt/llvm/include"

clean:
	rm -f $(TARGETS) $(EXECS) *.s *.o *_.c lib*.so lib*.a
