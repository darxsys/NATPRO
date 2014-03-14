#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1e18+1

vector<long long int> T;

void update(int index, long long int value) {

	T[index] = value;
	// printf("Setting index: %d to %lld\n", index, T[index]);	
	for(index /= 2; index; index /= 2) {


		T[index] = min(T[index * 2], T[index * 2 + 1]);
		// printf("Setting index: %d to %lld\n", index, T[index]);
	}
}

long long int query(int current, int from, int to, int A, int B) {

	if (from >= A && to <= B) {

		return T[current];
	}

	long long int min1 = MAX;
	long long int min2 = MAX;
	// go left
	// child of current node covers interval [from, (from+to) / 2]
	if ((from + to) / 2 >= A) {
		min1 = query(current * 2, from, (from + to)/2, A, B);
	} 

	// go right
	//child of current node covers interval [(from+to) / 2 + 1, to]
	if ((from + to) / 2 + 1 <= B) {
		min2 = query(current * 2 + 1, (from + to)/2 + 1, to, A, B);
	} 

	return min(min1, min2);
}

int main(void) {

	int N;
	int K;
	long long int a, b;
	int two;
	char buffer[100];

	scanf("%d", &N);

	for (two = 1; two < N; two *= 2);
	T.insert(T.begin(), two + N, MAX);

	for (int i = 0; i < N; i++) {

		scanf("%lld", &T[two + i]);
	}

	for (int i = two + N - 1; i > 1; i--) {

		if (T[i/2] > T[i]) {
			T[i/2] = T[i];
		}
	}

	scanf("%d", &K);

	for (int i = 0; i < K; i++) {

		scanf("%s %lld %lld", buffer, &a, &b);

		if (strcmp(buffer, "sef") == 0) {

			// cout << "here" << endl;

			// current node and interval covered by current node
			printf("%lld\n", query(1, 0, two - 1, a-1, b-1));
		} else {

			// cout << "there" << endl;
			update(two + a - 1, b);
		}
	}

	return 0;
}
