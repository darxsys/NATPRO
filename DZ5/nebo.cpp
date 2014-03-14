#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

#define INF 1e18

typedef long long int lld;

class my_compare {
public:
 bool operator() (const pair<int, int> &first, const pair<int, int> &second) const
 {
    return first.second < second.second;
 }
};

const int x_direction[4] = {1, -1, 0, 0};
const int y_direction[4] = {0, 0, 1, -1};
// update_neighbor()

lld dijkstra(int startx, int starty, int endx, int endy, int N, int *city) {
    list<pair<pair<pair<int, int>, int>, int > > nodes; //x, y, floor, dist
    int x, y, new_x, new_y;
    nodes.push_back(make_pair(make_pair(make_pair(x, y), city[startx * N + starty]), 0));
    lld dist, cur_floor;

    while(!nodes.empty()) {
        x = nodes.back().first.first.first;
        y = nodes.back().first.first.second;

    }


}

int main(void) {
    lld A, B, C;
    int N;
    int xa, ya, xb, yb;

    scanf("%d", &N);
    scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
    scanf("%lld %lld %lld", &A, &B, &C);

    int city_map[N * N];
    lld i_fact = (N * A) % C;
    lld j_fact = A % C;
    B = B % C;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            city_map[i * N + j] = ((A * i * N) + (A * j) + B) % C;
        }
    }

    printf("%lld\n", dijkstra(xa-1, ya-1, xb-1, yb-1, N, city_map));
    return 0;
}