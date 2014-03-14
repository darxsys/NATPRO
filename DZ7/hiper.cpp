#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long int lld;

int main(void) {
    lld moment_start;
    // lld moment_end;
    lld sum = 0;

    int N1, N2;
    int D, T, O;

    vector<pair<int, int> > wc_one;
    vector<pair<int, int> > wc_two;

    scanf("%d", &N1);
    for (int i = 0; i < N1; i++) {
        scanf("%d %d", &D, &T);
        O = D + T;
        wc_one.push_back(make_pair(D, 1));
        wc_one.push_back(make_pair(O, -1));
    }

    scanf("%d", &N2);
    for (int i = 0; i < N2; i++) {
        scanf("%d %d", &D, &T);
        O = D + T;
        wc_two.push_back(make_pair(D, 1));
        wc_two.push_back(make_pair(O, -1));
    }

    sort(wc_one.begin(), wc_one.end());
    sort(wc_two.begin(), wc_two.end());

    int i = 0, j = 0;
    pair<int, int> current;
    multiset<int> first, second;
    // first.insert(0);
    // second.insert(0);

    // cout << "here" << endl;

    while (1) {
        if (i < wc_one.size() || j < wc_two.size()) {
        // cout << i << " " << j << endl;
            // current = wc_one[i];
            if (i >= wc_one.size() || (j < wc_two.size() && wc_one[i].first > wc_two[j].first)) {
                // cout << "j: " << j << endl;
                current = wc_two[j];
                // cout << "Current j: " << current.first << " " << current.second << endl;
                j++;
                // delete
                if (current.second < 0) {
                    // cout << "here" << endl;
                    second.erase(second.find(-current.second));
                    // cout << "and here" << endl;
                    if (second.size() == 1 && first.size() >= 2) {
                        // cout << "Adding " << current.first - moment_start << endl;
                        sum += current.first - moment_start;
                        moment_start = current.first;
                    }
                } else {
                    second.insert(current.second);
                    if (second.size() == 2 && first.size() >= 2) {
                        // cout << "J here" << endl;
                        moment_start = current.first;
                    }
                }
            } else {
                // cout << "i: " << i << endl;
                current = wc_one[i];
                // cout << "Current i: " << current.first << " " << current.second << endl;
                i++;
                if (current.second < 0) {
                    first.erase(first.find(-current.second));
                    if (first.size() == 1 && second.size() >= 2) {
                        // cout << "Adding " << current.first - moment_start << endl;
                        sum += current.first - moment_start;
                        moment_start = current.first;
                    }
                } else {
                    first.insert(current.second);
                    if (first.size() == 2 && second.size() >= 2) {
                        // cout << "I here" << endl;
                        moment_start = current.first;
                    }
                }
            }      
        } else {
            break;
        }

    }

    printf("%lld\n", sum);
    return 0;
}