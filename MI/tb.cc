#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

int GCD(long long int A, long long int B) {
	if (B == 0) return A;
	return GCD(B, A%B);
}

vector<int> p(42, 1);

void eratosten() {
	for (int i = 2; i < 42; i++) {
		for(int j = i*2; j < 42; j += i) {
			p[j] = 0;
		}
	}
}

int main(void) {
	long long int B;
	int K;
	long long int count = 0;

	eratosten();
		
	scanf("%lld %d", &B, &K);
	
	//if (K == 2) {
		//printf("%lld\n", (B-K)/K + 1);
		//return 0;	
	//}
	
	long long int num = 1;
	int K_ = K;
	for (int i = 2; i < K; i++) {
		//printf("i: %d\n", i);
		if (p[i]) {
			while(K_ / i) {
			//printf("times\n");
				num *= i;
				K_ /= i;
			}
			K_ = K;
		}
	}
	
	//printf("%lld\n", num);
	
	long long int subtract = B / (K * num);
	//printf("%lld\n", num);
	
	printf("%lld\n", B/num - subtract);
	return 0;
}
