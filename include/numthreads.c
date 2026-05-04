#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/time.h>
#include <math.h>
#include "ctimer.h"

#include "numthreads.h"

// gcc -O3 -Og -g -Wall -Wconversion -lm thread_test.c // ./a.out

int number_threads() {
    FILE *fp;
    char buffer[buffersize];
    int NUM_THREADS = 2; // Default to 2 if command fails or parsing fails

    // Open the pipe to the command
    fp = popen("lscpu | grep '^CPU(s):'", "r");
    
    if (fp != NULL) {

        // Read the output line (e.g., "CPU(s):                          NUM_THREADS")
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            // Find the colon and scan the integer following it 
            if (sscanf(buffer, "CPU(s): %d", &NUM_THREADS) != 1) {
                // If parsing fails, reset to 2 
                NUM_THREADS = 2;
            }
        }
        
        // Close the pipe and get exit status
        if (pclose(fp) != 0) {
            NUM_THREADS = 2;
        }
    }

    // printf("%d\n", NUM_THREADS);

    return NUM_THREADS;
}