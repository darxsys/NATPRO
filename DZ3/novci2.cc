#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1000000;
const int NUM_ELEMENTS = 1001;

int dp[NUM_ELEMENTS];

int main(void) {
	for (int i = 1; i < NUM_ELEMENTS; i++) {
		dp[i] = MAX;
	}

	int N, M;

	scanf("%d %d", &N, &M);

	int coins[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &coins[i]);
	}

	dp[0] = 0;

	for (int i = 0; i < N; i++) {
		int coin = coins[i];
		// printf("current coin:%d\n", coin);

		for (int sum = M; sum > 0; sum--) {
			if (coin <= sum) {
				if (dp[sum - coin] < MAX) {
					if (dp[sum] > dp[sum - coin] + 1) {
						dp[sum] = dp[sum - coin] + 1;
						// break;
					}
				}
			}
		}		
	}

	printf("%d\n", dp[M] == MAX ? -1 : dp[M]);
	return 0;
}