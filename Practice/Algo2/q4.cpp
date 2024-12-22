#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<vector<pair<long long, int>>> &graph, int u, pair<long long, int> edge) {
    graph[u].push_back(edge);
}


void initialize(int n, long long &inf, vector<long long> &dist, priority_queue<pair<long long, int>> &pq, vector<bool> &visited) {
    inf = LONG_LONG_MAX / 2;
    dist = vector<long long>(2 * n + 1, inf);
    dist[1] = 0;
    pq = priority_queue<pair<long long, int>>();
    visited = vector<bool>(2 * n + 1, false);
    pq.push({0, 1});
}

int main() {

int n;
int m;
int flag;
cin >> n >> m;
vector<vector<pair<long long, int>>> g(2 * n + 1);
int i = 0;
while (i < m) {
    int u, v, w;
    cin >> u >> v >> w;
    addEdge(g, u, {w, v});
    addEdge(g, n + v, {w, n + u});
    ++i;
}

 i = 1;

while (i <= n) {
    addEdge(g, i, {0, n + i});
    ++i;
}

long long inf;
vector<long long> dist;
priority_queue<pair<long long, int>> pq;
vector<bool> visited;
initialize(n, inf, dist, pq, visited);
int comp;
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        flag=0;
        d = -d;
        pq.pop();
        comp++;
        if (visited[u])
            continue;
        visited[u] = true;

auto it = g[u].begin();
while (it != g[u].end()) {
    auto [w, v] = *it;
    if (d + w < dist[v]) {
        dist[v] = d + w;
        pq.push({-dist[v], v});
    }
    ++it;
}
    }

    for (int v = 2; v <= n; v++)
        cout << (dist[v + n] == inf ? -1 : dist[v + n]) << " ";
    return 0;
}