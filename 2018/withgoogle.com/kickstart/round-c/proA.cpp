#include "bits/stdc++.h"
using namespace std;

int FindFirstCircleVertex(const int u, const int p, list<int> &deq,
        vector<bool> &visited,
        const vector<vector<int>> &neighbors){
    deq.push_back(u);
    visited[u] = true;
    for (const int v : neighbors[u]) {
        if (v == p) continue;
        if (!visited[v]) {
            int cache = FindFirstCircleVertex(v, u, deq, visited, neighbors);
            if (cache != -1) return cache;
        } else {
            return v;
        }
    }
    deq.pop_back();
    return -1;
}

vector<int> FindCircleVertexs(const vector<vector<int>> &neighbors) {
    const int n = neighbors.size();
    list<int> deq;
    vector<bool> visited(n, false);
    const int first_circle_vertex = FindFirstCircleVertex(0, -1, deq, visited, neighbors);
    while (deq.front() != first_circle_vertex)
        deq.pop_front();
    return vector<int>(deq.begin(), deq.end());
}

vector<int> PlanetDistance(const vector<pair<int, int>> &edges) {
    const int n = edges.size();
    //TODO: check input validity
    vector<vector<int>> neighbors(n, vector<int>());
    for (const pair<int, int> edge : edges) {
        neighbors[edge.first].push_back(edge.second);
        neighbors[edge.second].push_back(edge.first);
    }
    vector<int> key_vertexs = FindCircleVertexs(neighbors);
    vector<int> foo(n, -1);
    queue<int> bfsq;
    for (const int vertex : key_vertexs) {
        foo[vertex] = 0;
        bfsq.push(vertex);
    }
    while (!bfsq.empty()) {
        const int u = bfsq.front();
        for (const int v : neighbors[u]) {
            if (foo[v] == -1) {
                foo[v] = foo[u] + 1;
                bfsq.push(v);
            }
        }
        bfsq.pop();
    }
    return foo;
}

void process(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> edges(n, pair<int, int>(0, 0));
    for(int i=0; i<n; i++){
        scanf("%d%d", &edges[i].first, &edges[i].second);
        edges[i].first--;
        edges[i].second--;
    }
    auto foo = PlanetDistance(edges);
    for (const auto el : foo) {
        printf(" %d", el);
    }
}

int main(){
    int c;scanf("%d", &c);
    for(int i=0; i<c; i++){
        printf("Case #%d:", i+1);
        process();
        printf("\n");
    }
    return 0;
}
