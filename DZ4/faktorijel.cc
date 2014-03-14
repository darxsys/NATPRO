#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

#define MAX 1000001

vector<int> memo(MAX, -1);

void initialize() {
	memo[0] = 1;
	memo[1] = 1;
	memo[2] = 2;
	memo[3] = 6;
	memo[4] = 4;
	memo[5] = 2;
	memo[6] = 2;
	memo[7] = 4;
	memo[8] = 2;
	memo[9] = 8;
}

int main(void) {
	int N;
	int i;
	int tens;
	scanf("%d", &N);

	initialize();

	for (int i = 10; i <= N; i++) {
		tens = (i / 10) % 10;
		if (tens % 2) {
			memo[i] = (4 * memo[i/5] * memo[i%10]) % 10;
		} else {
			memo[i] = (6 * memo[i/5] * memo[i%10]) % 10;
		}
	}

	int res = memo[N] % 10;
	printf("%d\n", res % 10);
	return 0;
}