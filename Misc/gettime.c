#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include <sys/types.h>
#include <unistd.h>

#define BILLION 1000000000

int main(/*int argc, char **argv*/) {
	uint64_t t;
	struct timespec start, end;

	clock_gettime(CLOCK_MONOTONIC, &start);	/* start time */
	for (int i = 0; i < 1000; ++i) {
		getpid();
	}
	clock_gettime(CLOCK_MONOTONIC, &end);	/* end time */

	t = BILLION * (end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	printf("elapsed time = %llu nanoseconds\n", /*(long long unsigned int)*/ t);

	return 0;
}
