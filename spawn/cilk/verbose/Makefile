CC=		/opt/opencilk-2/bin/clang 
CFLAGS=		-fopencilk -O3 -Og -g # -Wall -Wextra -Wconversion -std=c11 -Werror -lm
SOURCE=		$(wildcard *.c)
TARGETS=	$(SOURCE:.c=)	

EXECS := $(foreach s,$(TARGETS),$(shell echo $(basename $(s)) | cut -c1-2))

build: $(TARGETS)

At: Atest_cilk.c
	$(CC) $(CFLAGS) Atest_cilk.c -o At

Ct: Ctest_cilk.c
	$(CC) $(CFLAGS) Ctest_cilk.c -o Ct

Dt: Dtest_cilk.c
	$(CC) $(CFLAGS) Dtest_cilk.c -o Dt

Et: Etest_cilk.c
	$(CC) $(CFLAGS) Etest_cilk.c -o Et

Pt: Ptest_cilk.c
	$(CC) $(CFLAGS) Ptest_cilk.c -o Pt

all:
	@for s in $(SOURCE); do \
		name=$$(basename $$s); \
		exe=$$(echo $$name | cut -c1-2); \
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
