#CC=		/opt/opencilk/bin/clang 
CC=    xcrun ~/opencilk/bin/clang 
CFLAGS=		-fopencilk -O3 -Og -g
SOURCE=		$(wildcard *.c)
TARGETS=		$(SOURCE:.c=)

all: $(TARGETS)
 
%:%.c
	$(CC) $(CFLAGS) -o $@ $<


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
