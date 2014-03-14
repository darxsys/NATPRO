#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_NUM 1000000

void eratosten(vector<int> &p, int limit) {
	vector<int> flags(limit + 1, 0);

	for (int i = 2; i<= limit; i++) {
		if (flags[i] == 0) {
			p[i] = i;
			for (int j = i * 2; j<= limit; j+=i) {
				flags[j] = 1;
				p[j] = i;
			}
		}
	}
}

int main(void) {	
	vector<int> p(MAX_NUM + 1, 1);
	vector<int> indicator(MAX_NUM + 1, 0);
	int is_square = 1;
	eratosten(p, MAX_NUM);

	int K;
	int a = 0;
	int num;
	scanf("%d", &K);

	int factor;
	for (int i = 0; i < K; i++) {
		scanf("%d", &num);	

		while (num > 1) {
			factor = p[num];
			indicator[factor] ^= 1;
			num /= factor;

			if (indicator[factor] == 0) {
				a--;
			} else {
				a++;
			}
		}

		// for (int j = 2; j <= MAX_NUM; j++) {
		// 	if (indicator[j] == 1) {
		// 		is_square = 0;
		// 		break;
		// 	}
		// }

		if (a) {
			printf("NE\n");
		} else {
			printf("DA\n");
		}

		is_square = 1;
	}

	return 0;
}