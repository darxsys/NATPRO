#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

struct compare {
    bool operator()(const pair<int, int> &first, const pair<int, int> &second) {
        if (first.first < second.first)
            return true;

        if (first.first == second.first)
            return first.second > second.second;

        return false;
    }
} cmp;

int main(void) {
    int N;
    scanf("%d", &N);
    int L, D;
    int counter = 0;
    int current;
    // vector<bool> indicator(N+1, false);
    vector<pair<int, int> > posters;

    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &L, &D);
        posters.push_back(make_pair(L, i));
        posters.push_back(make_pair(D, -i));
    }

    sort(posters.begin(), posters.end(), cmp);
    set<int> sweep;
    // set<int> res;
    set<int> res;
    sweep.insert(0);
    // sweep.insert(posters[0].second);

    for (int i = 0; i < posters.size(); i++) {
        if (posters[i].second > 0) {
            sweep.insert(posters[i].second);
        }

        current = *(--sweep.end());
        if (current > 0) {
            // printf("Inserting: %d\n", current);
            res.insert(current);
        }

        if (posters[i].second < 0) {
            sweep.erase(-posters[i].second);
        }
    }

    printf("%u\n", res.size());
    return 0;
}
