TARGETS = ldc ldp ldo lsc lsp lso lwc lwp lwo

all: $(TARGETS)

ldc: launch_done_cilk2.c
	/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g launch_done_cilk2.c -o ldc
ldp: launch_done_pthreads.c
	gcc -fopenmp -std=gnu99 -Wall -O3 -Og -g launch_done_pthreads.c -o ldp
ldo: launch_done_openmp2.c
	gcc -fopenmp -std=gnu99 -Wall -O3 -Og -g launch_done_openmp2.c -o ldo

lsc: launch_start_cilk2.c
	/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g launch_start_cilk2.c -o ldc
lsp: launch_start_pthreads.c
	gcc -fopenmp -std=gnu99 -Wall -O3 -Og -g launch_start_pthreads.c -o ldp
lso: launch_start_openmp2.c
	gcc -fopenmp -std=gnu99 -Wall -O3 -Og -g launch_start_openmp2.c -o ldo

lwc: launch_done_cilk2.c
	/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g launch_window_cilk.c -o ldc
lwp: launch_done_pthreads.c
	gcc -fopenmp -std=gnu99 -Wall -O3 -Og -g launch_window_pthreads.c -o ldp
lwo: launch_done_openmp2.c
	gcc -fopenmp -std=gnu99 -Wall -O3 -Og -g launch_window_openmp.c -o ldo

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
