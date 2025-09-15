#include <stdio.h>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <math.h>
#include "../ctimer.h"

/* Benchmark: Use cilk_for to count primes. Race condition. 
 */

int isPrime(int n){
int limit = sqrt(n);
int i = 0; for(i=2; i<=limit; i++)
if(n%i == 0)
return 0;
return 1;
}

int main(){
	int n = 10000000;
	int gs = 25000; //grainsize
	int numPrimes = 0;
	int i;

	ctimer_t t;

	ctimer_start(&t);

	#pragma grainsize = gs
	cilk_for(int i = 0; i < n/gs; i++){
		int j; for(j = i*gs+1; j < (i+1)*gs; j += 2){
		if(isPrime(j))
			numPrimes++;
		}
	}

	ctimer_stop(&t);
	ctimer_measure(&t);

	printf("Found %d primes in \n",numPrimes);
	ctimer_print(t, "Overall Time Knox Prime :");

}


