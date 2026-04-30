.PHONY: cilk cilkclean omp ompclean pt ptclean serial serialclean

CC = gcc
CFLAGS = -lm

CCCILK=		/opt/$$(ls /opt | grep "opencilk")/bin/clang # /opt/opencilk-2/bin/clang 
CFLAGSCILK=		-fopencilk -O3 -Og -g # -fcilktool=cilkscale -lm -Wall -Wextra -Wconversion -std=c11 -Werror


TARGETS = x
CILKSOURCE= $(wildcard cilk/*.c)


cilk:
	$(MAKE) -C cilk all

cilkclean:
	$(MAKE) -C cilk clean

####
omp:
	$(MAKE) -C openmp all

ompclean:
	$(MAKE) -C openmp clean

####
pt:
	$(MAKE) -C pthreads all

ptclean:
	$(MAKE) -C pthreads clean

####
serial:
	$(MAKE) -C serial all

serialclean:
	$(MAKE) -C serial clean

####

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
	rm -f $(TARGETS) *.s *.o *_.c lib*.so lib*.a
