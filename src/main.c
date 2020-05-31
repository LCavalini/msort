/* 	msort main.c
		author: lcavalini <lucas.cavalini.barboza@gmail.com>
		license: GPLv3
*/	

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "msort.h"

int main(int argc, char **argv) {

	char* str;
	int test_res;
	struct timespec start, end;

	if(argc < 2) {

		printf("Usage: msort string\n");
		return EXIT_FAILURE;

	}

	str = argv[1];

	printf("Step 1: Sorting %s\n", str);

	clock_gettime(CLOCK_MONOTONIC, &start);
	strmsort(str, 0, strlen(str) - 1);
	clock_gettime(CLOCK_MONOTONIC, &end);

	printf("Result: %s\n", str);
	printf("Sorting time: %ld ns\n", end.tv_nsec - start.tv_nsec);

	printf("Step 2: Testing %s\n", str);

	clock_gettime(CLOCK_MONOTONIC, &start);
	test_res = issorted(str);
	clock_gettime(CLOCK_MONOTONIC, &end);
	
	if(test_res == EXIT_SUCCESS) {

		printf("Result: Passed!\n");

	} else {

		printf("Result: Failure!\n");

	}
	
	printf("Testing time: %ld ns\n", end.tv_nsec - start.tv_nsec);

	return EXIT_SUCCESS;

}
