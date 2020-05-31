/*	msort msort.h
		author: lcavalini <lucas.cavalini.barboza@gmail.com>
		license: GPLv3
*/
#include "msort.h"

static void merge(char* str, size_t left, size_t middle, size_t right) {

	char* buff = malloc(sizeof(char) * (strlen(str) + 1));

	if(buff == NULL) {
		
		exit(EXIT_FAILURE);

	}

	strcpy(buff, str);

	for(size_t i = left, j = middle + 1, k = left; k <= right; ++k) {

		if(i <= middle && (j > right || tolower(buff[i]) < tolower(buff[j]))) {

			str[k] = buff[i];
			i++;

		} else {

			str[k] = buff[j];
			j++;

		}

	}

	free(buff);

}


void strmsort(char* str, size_t left, size_t right) {

	if(left < right) {

		size_t middle = (left + right) / 2;
	
		strmsort(str, left, middle);
		strmsort(str, middle+1, right);

		merge(str, left, middle, right);			

	}
	
}


int issorted(char* str) {

	for(size_t i = 0; i < (strlen(str) - 2); ++i) {

			if(tolower(str[i]) > tolower(str[i+1])) {

				return EXIT_FAILURE;

			}
	}

	return EXIT_SUCCESS;

}

