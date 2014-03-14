#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>


long int noWorkersNeeded(long int *pages, int n, long int max) {

	long int noWorkers = 1;
	long int buffer = 0;
	int i;

	for (i = 0; i < n; i++) {

		buffer += pages[i];
		if (buffer > max) {
			noWorkers++;
			i--;
			buffer = 0;
		}
	}

	return noWorkers;
}

long int findMaxPages(long int *pages, int n, long int availableWorkers, long int min, long int max) {

	long int lo = min;
	long int hi = max;
	long int mid;
	int i;

	while (lo < hi) {

		mid = lo + (hi - lo) / 2;

		if (noWorkersNeeded(pages, n, mid) > availableWorkers) {
			lo = mid + 1;
		} else {
			hi = mid;
		}

	}

	return hi;
}

void findOrder(long int **workerPages, int noWorkers, long int *pages, int noPages, long int max) {

	// printf("Max: %ld\n", max);

	long int buffer = 0;
	int workersDone = 1;
	int booksAvailable = noPages;
	int bookIndeks = noPages - 1;
	int currentBook = noPages - 1;
	int i = noWorkers - 1;

	while (booksAvailable > (noWorkers - workersDone)) {
		// printf("in while\n");

		if (buffer + pages[currentBook] > max) {

			(*workerPages)[i] = buffer;
			// printf("Worker: %d, pages: %ld\n", i, buffer);
			buffer = 0;
			workersDone++;
			i--;

		} else {

			buffer += pages[currentBook];
			currentBook--;
			booksAvailable--;

		}
	}

	(*workerPages)[i] = buffer;
	for (i = currentBook; i > -1; i--) {

		// printf("Worker: %d, pages: %ld\n", i, pages[i]);
		(*workerPages)[i] = pages[i];
	}

	return;
}

void printSolution(long int *pages, int noPages, long int *workerPages, int noWorkers) {

	int i;
	int temp;
	int pageIndex = 0;

	for (i = 0; i < noWorkers; i++) {

		temp = workerPages[i];
		while (1) {

			temp -= pages[pageIndex];
			if (temp >= 0 && pageIndex < noPages) {

				if (pageIndex < noPages - 1) {
					printf("%ld ", pages[pageIndex]);
				} else {
					printf("%ld", pages[pageIndex]);
				}
				pageIndex++;
			} else {

				if (i < noWorkers - 1) {
					printf("/ ");
				}
				break;
			}
		}
	}

	printf("\n");

	return;
}

int main(void) {

	int N;
	scanf("%d", &N);

	while (N > 0) {

		int M, K;
		long int minPages = 0;
		long int maxPages = 0;
		long int *pages;
		long int *workerPages;
		int i;
		long int solution = 0;

		scanf("%d %d", &M, &K);

		pages = (long int*) malloc(sizeof(long int) * M);

		for (i = 0; i < M; i++) {

			scanf("%ld", &pages[i]);

			if (pages[i] > minPages) {
				minPages = pages[i];
			}

			maxPages += pages[i];
		}

		solution = findMaxPages(pages, M, K, minPages, maxPages);

		workerPages = (long int*) malloc(sizeof(long int) * K);

		// printf("Here\n");

		findOrder(&workerPages, K, pages, M, solution);

		// printf("There\n");

		printSolution(pages, M, workerPages, K);

		// printf("Now\n");

		free(workerPages);
		free(pages);
		N--;
	}

	return 0;
}