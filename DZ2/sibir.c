#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX 1000000000
#define NUM 1000000001

void insert(int *where, int n, int index, int how_much) {

	for(; index < n; index += index&-index) {

		where[index] += how_much;
		if (where[index] < 0) {
			where[index] = 0;
		}
	}
}

int query(int *where, int index) {

	int result = 0;
	for(; index > 0; index -= index&-index) {

		result += where[index];
	}

	return result;
}

int main(void) {

	int N;
	int K;
	int X, Y;
	int i;
	int *wagons;
	int *each;
	char buffer[100];

	scanf("%d", &N);

	wagons = (int*) malloc(sizeof(int) * (N + 1));
	each = (int*) malloc(sizeof(int) * (N + 1));

	for(i = 0; i < N + 1; i++) {

		each[i] = 0;
		wagons[i] = 0;
	}

	scanf("%d", &K);

	for (i = 0; i < K; i++) {

		scanf("%s %d %d", buffer, &X, &Y);

		// printf("%s %d %d\n", buffer, X, Y);

		if (strcmp(buffer, "posadka") == 0) {

			// printf("here\n");
			int temp = each[X+1];
			int diff = Y;
			each[X+1] += Y;
			if (each[X+1] > MAX) {
				each[X+1] = MAX;
				diff = MAX - temp;
			}		 

			insert(wagons, N+1, X+1, diff);

		} else if (strcmp(buffer, "razgruzka") == 0) {

			// printf("there\n");
			int temp = each[X+1];
			each[X+1] -= Y;
			if (each[X+1] < 0) {
				Y = temp;
				each[X+1] = 0;
			}

			insert(wagons, N+1, X+1, -Y);
		} else if (strcmp(buffer, "kontora") == 0) {

			printf("%d\n", query(wagons, Y+1) - query(wagons, X));
		}
	}

	free(each);
	free(wagons);
	return 0;
}


