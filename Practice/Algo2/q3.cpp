#include <iostream>
#include <vector>

using namespace std;
//
#define int long long

vector<vector<int>> graph;
vector<int> deegre;
vector<bool> visited;
vector<int> depth;
int ans;

void dfs(int cur) {
    if (visited[cur])
        return;
    visited[cur] = true;

    auto it = graph[cur].begin();
    while (it != graph[cur].end()) {
        dfs(*it);
        depth[cur] = max(depth[cur], depth[*it] + 1);
        ++it;
    }

    ans = max(deegre[cur] * depth[cur], ans);
}

void cin_input(int& n, int& m) {
    cin >> n >> m;
    graph.resize(n);
    deegre.resize(n, 0);
    //deegree has degree
    int x=0;
    depth.resize(n, 1);
    visited.resize(n, false);
    //depth and visited as usual
    int deck=0;

    int u;
    int v;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        u--;
        v--;
        deegre[u]--;

        deegre[u]++;
        deegre[u]++;

        deegre[v]--;

        deegre[v]++;

        deegre[v]++;

        if (u > v){

            deck+=1;
            graph[u].push_back(v);
}
        else{
            deck-=1;
            graph[v].push_back(u);
            }
    }
}

void cout_output() {
    cout << ans;
}

void solve() {
    int n, m;
    cin_input(n, m);

    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs(i);
    }

    cout_output();
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long test_cases = 1;
    for (int i = test_cases; i > 0; --i) {
        ans = 1; 
        graph.clear();
        visited.clear();
        deegre.clear();
        depth.clear();
        solve();
        cout << '\n';
        
    }
    return 0;
}
