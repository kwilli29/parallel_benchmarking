CC=		gcc
CFLAGS=		-fopenmp -Wall -O3 -Og -g
SOURCE=		$(wildcard *.c)
TARGETS=	$(SOURCE:.c=)	

EXECS := $(foreach s,$(TARGETS),$(shell echo $(basename $(s)) | cut -c1-3))

all: $(TARGETS)

02A: 02A_spawntime_before_sequential_openmp.c
	$(CC) $(CFLAGS) 02A_spawntime_before_sequential_openmp.c -o 02A

02B: 02B_spawntime_before_parasect_openmp.c
	$(CC) $(CFLAGS) 02B_spawntime_before_parasect_openmp.c -o 02B

06A: 06A_spawntree.openmp.c 
	$(CC) $(CFLAGS) 06A_spawntree.openmp.c  -o 06A

build:
	@for s in $(SOURCE); do \
		name=$$(basename $$s); \
		exe=$$(echo $$name | cut -c1-3); \
		$(CC) $(CFLAGS) $$s -o $$exe; \
	done

#clang  -fopenmp -lomp -O3 -Og -g omp/fib_omp.c -o ompfib

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
