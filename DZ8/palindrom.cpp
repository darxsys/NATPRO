#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
using namespace std;

#define MAX 100002

const int p = 10007;

int hash(int i, int j, int *H, int *P) {
    if (i > 0) {
        return H[j] - H[i-1] * P[j-i+1];
    } else {
        return H[j];
    }
}

int odd(char *str, int N, int start, int *H, int *HR, int *P) {
    int lo = 0, hi = min(start, N-start-1), mid;

    while (lo < hi) {
        mid = (lo + hi + 1) / 2;

        if (hash(start - mid, start + mid, H, P) == hash(N - start - mid - 1, N-1-start+mid, HR, P)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }

    return 2 * lo + 1;
}

int even(char *str, int N, int start, int *H, int *HR, int *P) {
    if (start == N-1) {
        return 0;
    }

    int lo = 0, hi = min(start+1, N-start-1), mid;

    while (lo < hi) {
        mid = (lo + hi + 1) / 2;

        if (hash(start-mid+1, start+mid, H, P) == hash(N-start-mid-1, N-start + mid - 2, HR, P)) {
            lo = mid;
        } else {
            hi = mid-1;
        }
    }

    return 2 * lo;
}

int main(void) {
    int N;

    scanf("%d", &N);
    char str[MAX];
    scanf("%s", str);

    int P[MAX];
    int H[MAX];
    int HR[MAX];
    P[0] = 1;
    H[0] = str[0];
    HR[0] = str[N-1];

    for (int i = 1; i < N; i++) {
        P[i] = p * P[i-1];
        H[i] = H[i-1] * p + str[i];
        HR[i] = HR[i-1] * p + str[N-i-1];
    }

    int len = 0;

    for (int i = 0; i < N; i++) {
        len = max(len, odd(str, N, i, H, HR, P));
        len = max(len, even(str, N, i, H, HR, P));
    }

    printf("%d\n", len);
    return 0;
}
