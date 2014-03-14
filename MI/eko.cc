#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int binary(vector<int> &trees, int M, int min, int max) {
	long long int sum;
	int lo = min;
	int hi = max;
	int mid;
	
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		sum = 0;
		
		for (int i = 0; i < trees.size(); i++) {
			if (trees[i] - mid > 0) {
				sum = (sum + trees[i]) - mid;
			}
		}
		
		if (sum < M) {
			hi = mid  - 1;
		} else {
			lo = mid;
		}
	}	
	
	return lo;
}

int main(void) {
	int N, M;
	int min = 1000000001;
	int max = -1;
	scanf("%d %d", &N, &M);
	vector<int> trees(N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &trees[i]);
		if (trees[i] > max) {
			max = trees[i];
		}
		if (trees[i] < min) {
			min = trees[i];
		}
	}

	if (N == 1) {
		printf("%d\n", trees[0] - M);
		return 0;
	}
	
	printf("%d\n", binary(trees, M, min, max));
	return 0;
}
