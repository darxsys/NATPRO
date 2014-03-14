#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lld;

vector<vector<pair<int, int> > > graph;

lld DFS(int parent, int node) {
    lld farthest = 0;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i].first != parent) {
            farthest = max(farthest, DFS(node, graph[node][i].first) + graph[node][i].second);
        }
    }

    return farthest;
}

int main(void) {
    int N, S;
    int a, b, c;

    vector<pair<int,int> > initalize;
    lld edge_sum = 0;

    scanf("%d %d", &N, &S);
    graph.insert(graph.begin(), N, initalize);
    S--;
    N--;
    
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge_sum += c;
        a--; b--;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }

    printf("%lld\n", edge_sum * 2 - DFS(-1, S));
    return 0;
}