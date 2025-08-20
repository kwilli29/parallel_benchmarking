#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

// Our pthread-create benchmark measures the time to recursively create M threads, where M is some large number.
// In this benchmark, the main thread sets a shared iteration count to zero, 
// creates a thread and waits on a condition variable. 
// Each newly created thread increments the iteration count and compares it to M. 
// If the count is M, the thread signals the main thread. 
// Otherwise, the thread creates another thread and immediately calls pthread-exit. 
// The measurement reported for this benchmark is the time taken by the main thread divided by M. 
// We report results for when the threads are created either detached or 
// undetached with either system or process scope


void *do_one_thing(void *);
void *do_another_thing(void *);
void do_wrap_up(int, int);

int r1 = 0, r2 = 0, r3 = 0;
pthread_mutex_t r3_mutex=PTHREAD_MUTEX_INITIALIZER;


void *do_one_thing(void *pnum_times)
{
  int i, j, x;
  
  pthread_mutex_lock(&r3_mutex);
  if(r3 > 0) {
	x = r3;
	r3--;
  } else {
	x = 1;
  } 
  pthread_mutex_unlock(&r3_mutex); 

  for (i = 0;  i < 4; i++) {
    printf("doing one thing\n"); 
    for (j = 0; j < 10000; j++) x = x + i;
    (*(int *)pnum_times)++;
  }

  return(NULL);
}

void *do_another_thing(void *pnum_times)
{
  int i, j, x;
  
  pthread_mutex_lock(&r3_mutex);
  if(r3 > 0) {
        x = r3;
        r3--;
  } else {
        x = 1;
  }
  pthread_mutex_unlock(&r3_mutex);

  for (i = 0;  i < 4; i++) {
    printf("doing another \n"); 
    for (j = 0; j < 10000; j++) x = x + i;
    (*(int *)pnum_times)++;
  }

  return(NULL);
}

void do_wrap_up(int one_times, int another_times)
{
  int total;

  total = one_times + another_times;
  printf("All done, one thing %d, another %d for a total of %d\n",
	one_times, another_times, total);
}
// Each newly created thread increments the iteration count and compares it to M. 
// If the count is M, the thread signals the main thread. 
// Otherwise, the thread creates another thread and immediately calls pthread-exit. 
void create_threads(int M, int shared_iteration_count){

	// Base Case
	if(shared_iteration_count >= M){
		printf("Recursion Complete %d/%d", shared_iteration_count, M);
		// signal parent?
		// join?
		return 0;
	}


	// iterate?

	if (pthread_create(&thread1, NULL, do_one_thing,(void *) &r1) != 0)
	perror("pthread_create"), exit(1);

	// exit?
	
	return create_threads(M, shared_iteration_count);
}

int main(int argc, char* argv[]) {

	int M = 0;
	int shared_iteration_count = 0;

	if(argc > 1){
		M = atoi(argv[1]); // user defined M
	}
	else {
		M = 10; // create M threads !!
	}

	// create a thread
  pthread_t thread1;

	// wait on a condition variable
 
  if (pthread_create(&thread1, NULL, create_threads, M, shared_iteration_count) != 0)
	perror("pthread_create"), exit(1); 

  
  if (pthread_join(thread1, NULL) != 0)
	perror("pthread_join"),exit(1);


  do_wrap_up(r1, r2);

  return 0; 
}
