#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


void subtract(vector<int> &A, bool A_positive, vector<int> &B, bool B_positive, vector<int> &result) {
	for (int i = 0; i < A.size(); i++) {
		if (A_positive == false && B_positive == false) {
			result[i] = -A[i] + B[i];
		} else {
			result[i] = A[i] - B[i];
		}
	}

	// carry
	for (int i = 0; i < A.size(); i++) {
		if (A_positive && B_positive == false) {
			if (result[i] > 9) {
				result[i] -= 10;
				result[i + 1]++;
			}
		} else if (A_positive && B_positive) {
			if (result[i] < 0) {
				result[i] += 10;
				result[i + 1]--;
			}
		} else if (A_positive == false && B_positive) {
			if (result[i] < -9) {
				result[i] += 10;
				result[i+1]--;			}
		} else if (A_positive == false && B_positive == false) {
			if (result[i] < 0) {
				result[i] += 10;
				result[i + 1]--;
			}
		}
	}

	while (result.back() == 0) {
		result.pop_back();
	}
}

bool input_vector(vector<int> &A) {
	string buffer;

	bool positive = true;
	int end = 0;

	cin >> buffer;
	if (buffer[0] == '-') {
		positive = false;
		end = 1;
	}

	int len = buffer.length();
	for (int i = len - 1; i >= end; i--) {
		if (positive == false) {
			A.push_back(-(buffer[i] - '0'));
		} else {
			A.push_back(buffer[i] - '0');
		}
	}

	// for (int i = 0; i < A.size(); i++) {
	// 	cout << A[i] << " ";
	// }
	// cout << endl;
	// reverse(A.begin(), A.end());
	return positive;
}

int main(void) {
	vector<int> A;
	vector<int> B;
	vector<int> *C;

	bool A_positive = input_vector(A);
	bool B_positive = input_vector(B);
		
	for (int i = B.size(); i < A.size(); i++) {
		B.push_back(0);
	}

	vector<int> res(A.size());
	res.push_back(0);

	subtract(A, A_positive, B, B_positive, res);

	if (A_positive == false) {
		cout << "-";
	}

	for (int i = res.size() - 1; i >=0; i--) {
		cout << (res[i] < 0 ? -res[i] : res[i]);
	}

	cout << endl;
	return 0;
}
