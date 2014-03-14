#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int dp[1000][1000];

int main(void) {
	int N, M;
	char c;
	scanf("%d %d\n", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			scanf("%c", &c);
			if(c == '.') {
				dp[i][j] = 0;
			} else if (c == 'Z') {
				dp[i][j] = 1;
			} else if (c == 'D') {
				dp[i][j] = 5;
			} else {
				dp[i][j] = -1;
			}
		}
		scanf("%c", &c);
	}
	
	for (int i = N - 1; i >= 0; i--) {
		for(int j = M - 1; j >= 0; j--) {
			if (dp[i][j] == -1) {
				continue;
			}
			
			if (i == N - 1) {
				if (j == M - 1) {
					continue;
				}
				if (dp[i][j+1] == -1) {
					dp[i][j] = -1;
				} else {
					dp[i][j] += dp[i][j+1];
				}
				continue;
			}
			
			if (j == M - 1) {
				if (dp[i+1][j] == -1) {
					dp[i][j] = -1;
				} else {
					dp[i][j] += dp[i+1][j];
				}
				continue;
			}
			
			if (max(dp[i+1][j], dp[i][j+1]) == -1) {
				dp[i][j] = -1;
			} else {
				dp[i][j] += max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}
	
	printf("%d\n", dp[0][0]);
	return 0;
}
