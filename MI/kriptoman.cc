#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

void update(vector<int> &tree, int index, int value) {
	tree[index] ^= value;
	
	for(index /= 2; index > 0; index /=2) {
		tree[index] = tree[index*2] ^ tree[index*2+1];
	}
}

int query(vector<int> &tree, int current, int from, int to, int A, int B) {
	if (from >= A && to <= B) {
		return tree[current];
	}
	
	int one = 0;
	int two = 0;
	
	if ((from + to)/2 >= A) {
		one = query(tree, current*2, from, (from+to)/2, A, B);
	}
	
	if ((from + to)/2 + 1 <= B) {
		two = query(tree, current*2+1, (from+to)/2+1, to, A, B);
	}
	
	return one ^ two;
}

int main(void) {
	int N, M;
	char c;
	scanf("%d", &N);
	scanf("%d", &M);
	
	int two;
	for(two = 1; two < N; two *= 2);
	vector<int> tree(two + N + 1, 0);
	
	int a, b;
	scanf("%c", &c);
	
	for(int i = 0; i < M; i++) {
		scanf("%c %d %d\n", &c, &a, &b);
		if (c == 'I') {
			update(tree, two + a - 1, b);
		} else if (c == 'F') {
			printf("%d\n", query(tree, 1, 0, two-1, a-1, b-1));
		}
	}

	return 0;
}

