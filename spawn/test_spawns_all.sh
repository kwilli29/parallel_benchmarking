#!/bin/sh

/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g launch_done_cilk.c -o ldc
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g launch_start_cilk.c -o lsc
/opt/opencilk-2/bin/clang -fopencilk -O3 -Og -g launch_window_cilk.c -o lwc

gcc -fopenmp -Wall -O3 -Og -g launch_done_pthreads.c -o ldp
gcc -fopenmp -Wall -O3 -Og -g launch_start_pthreads.c -o lsp
gcc -fopenmp -Wall -O3 -Og -g launch_window_pthreads.c -o lwp

gcc -fopenmp -Wall -O3 -Og -g launch_done_openmp.c -o ldo
gcc -fopenmp -Wall -O3 -Og -g launch_start_openmp.c -o lso
gcc -fopenmp -Wall -O3 -Og -g launch_window_openmp.c -o lwo

#for ((i=0;i<10;i++)); 
#do 
#   ./ldc # 
#done

for ((i=0;i<10;i++)); 
do 
   ./lsc # 
done
#for ((i=0;i<10;i++)); 
#do 
#   ./lwc # 
#done

#for ((i=0;i<10;i++)); 
#do 
#   ./ldp # 
#done

#for ((i=0;i<10;i++)); 
#do 
#   ./lsp # 
#done

#for ((i=0;i<10;i++)); 
#do 
#   ./lwp # 
#done

#for ((i=0;i<10;i++)); 
#do 
#   ./ldo # 
#done

#for ((i=0;i<10;i++)); 
#do 
#   ./lso # 
#done

#for ((i=0;i<10;i++)); 
#do 
#   ./lwo 
#done
