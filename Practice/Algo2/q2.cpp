#include<bits/stdc++.h>
using namespace std;
#include <iostream>

#define PI 3.141592653589793238462643383279502884L 

vector<int> arr;
#define INF 1e9 
const int MOD = 1e9 + 7;
#define MAXN 100005 
#define all(x) x.begin(), x.end()
const int MAX = 1024;
#define sz(x) ((int)x.size()) 
int dp[MAX];
#define mp make_pair 
#define pb push_back 




void count_subsequences(int x, int &real_comp) {
    int reality=0;
    for (int i = MAX - 1; i >= 0; --i) {
        real_comp += 1;
        dp[i | x] += dp[i];
        reality+=1;
        dp[i | x] %= MOD;
    }
}

int main() {
    int Q;
    cin >> Q;
    int x;
    memset(dp, 0, sizeof(dp));
    int computations=0;
    dp[0] = 1;

    int real_comp = 0; 

    for (int i = 0; i < Q; ++i) {
        int M;
        int x;

        cin >> M >> x;

        if (M == 1) {
            arr.push_back(x);
            computations+=1;
            count_subsequences(x, real_comp);
        } else {
            computations+=1;
            cout << dp[x] << endl;
            real_comp += 1; 
        }
    }

   // cout << real_comp << endl; 
    return 0;
}