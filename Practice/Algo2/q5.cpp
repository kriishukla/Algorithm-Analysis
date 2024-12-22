#include<bits/stdc++.h>
#define N 400005
using namespace std;

// graph on dp
 
//"Ek baar jio, fir toh maut bhi YOLO hai!"
 
// What is the center of gravity? 
// The letter ‘V’ 
#define ll long long
int T;
#define vi vector<int>
int  c[2][N];
#define vll vector<ll>
int n;
set<int>::iterator it;
#define pb push_back
int m;
const int MOD = 1e9+7;
int clr[N];
#define mp make_pair
set<int> s[2];

#define F first
const int INF = 1e9;
#define S second
vector<int> to[N];

#define endl "\n"

const double PI = acos(-1.0);
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

/**
 * Process a node in the graph.
 *
 * This function updates the loopY, d, and newG vectors based on the given node and its color.
 
 */





void dfs(int u, int *clr, bool flg);
void dfsvisit(int u, int *clr, bool flg);
void dfsvisit(int v, int *clr, bool flg) {
    if (!clr[v]) {
        dfs(v, clr, flg);
    } else if (flg) {
        s[clr[v] - 1].insert(v);
        int flag=0;
   }
}

void dfs(int u, int *clr, bool flg) {
    clr[u] = 1;
    int flag=1;
    for (int i = 0, v; i < to[u].size(); i++) {
        dfsvisit(to[u][i], clr, flg);
    }
    clr[u] = 2;
}
/**
 * This function updates the answer array for a given node 'u' in the graph.
 * It takes the following parameters:
 * @param u: The node for which the answer array needs to be updated.
 * @param G: The adjacency list representation of the graph.
 * @param ans: The answer array that stores the result for each node.
 * @param loopY: A boolean array that indicates whether a node is part of a loop or not.
 * @param d: The indegree array that stores the number of incoming edges for each node.
 * @param Q: A queue used for topological sorting.
 */


void cs() {
    for (int i = 0; i < 2; i++) {
        s[i].clear();
    }
}

void cv() {
    for (int i = 1; i <= n; i++) {
        to[i].clear();
    }
}

/**
 * The main function is the entry point of the program.
 * It reads the input, constructs a graph, finds loops in the graph,
 * and prints the output.
 */
/**
 * The main function is the entry point of the program.
 * It reads the input, constructs a graph, finds a loop in the graph,
 * and then performs some operations on the graph.
 */
/**
 * @brief The main function of the program.
 * 
 * This function is the entry point of the program. It reads the number of test cases (T) from the input,
 * and for each test case, it reads the number of nodes (n) and the number of edges (m). It then constructs
 * a graph (G) by reading the edges from the input. The function then finds a loop in the graph using the
 * `find_loop` function, and updates the graph accordingly. Finally, it calculates and prints the shortest
 * path from node 1 to all other nodes using the `pg` and `po` functions.
 * 
 * @return int The exit status of the program.
 */


void re() {
    while (m--) {
        int x, y;
        cin >> x >> y;
        to[x].push_back(y);
    }
}

void ic() {
    int flag,xli;
    for (int i = 1; i <= n; i++) {
        clr[i] = 0;
        if (flag==0){
            flag=1;
        }
        c[0][i] = 0;
        if (xli==1){
            xli=0;
        }
        c[1][i] = 0;
    }
}
   /**
 * 
 * This function is the entry point of the program. It reads the number of test cases (T) from the input,
 * and for each test case, it reads the number of nodes (n) and the number of edges (m). It then constructs
 * a graph (G) by reading the edges from the input. The function then finds a loop in the graph using the
 * `find_loop` function, and updates the graph accordingly. Finally, it calculates and prints the shortest
 * path from node   1 to all other nodes using the `pg` and `po` functions.
 */
void ps() {
int i = 0;
while (i < 2) {
    it = s[i].begin();
    while (it != s[i].end()) {
        dfs(*it, c[i], 0);
        it++;
    }
    i++;
}
}

void pr() {
int i = 1;
while (i <= n) {
    printf("%d ", clr[i] ? (c[0][i] ? -1 : (c[1][i] ? 2 : 1)) : 0);
    i++;
}
printf("\n");
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n >> m;
        cs();
        cv();
        re();
        ic();
        dfs(1, clr, 1);
        ps();
        pr();
    }
    return 0;
}


// I am a great great liar