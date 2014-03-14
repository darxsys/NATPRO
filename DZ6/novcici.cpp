#include <stdio.h>
using namespace std;

#define MAX 1000001

int main(void) {
    int K, L, M;
    int N;

    int m[MAX];
    // int s[MAX];

    scanf("%d %d %d", &K, &L, &M);

    while (M) {
        scanf("%d", &N);
        m[0] = 0;

        for (int j = 1; j <= N; j++) {
            m[j] = 0;
            if (m[j-1] == 0) {
                m[j] = 1;
            }

            if (!m[j] && j >= K) {
                if (!m[j-K]) {
                    m[j] = 1;
                }
            }

            if (!m[j] && j >= L) {
                if (!m[j-L]) {
                    m[j] = 1;
                }
            }
        }

        if (m[N]) {
            printf("A");
        } else {
            printf("B");
        }
        M--;
    }

    printf("\n");
    return 0;
}
