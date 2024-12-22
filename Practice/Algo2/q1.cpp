#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
#define decsort(v) sort(v.begin(), v.end(), greater<int>())

long long should_break = false; // Global variable to indicate if recursion should break
template<typename T>
void print(const T& t) {
    cout <<t;
}

template<typename T, typename... Args>
void print(const T& t, const Args&... args) {
    cout << t << "";
    print(args...);
}
void printPath(vector<int> path,
               int i, int s)
{
    if (i != s) {
 

        if (path[i] == -1) {
            cout << "Path not found!!";
            return;
        }
        printPath(path, path[i], s);
        cout << path[i] << " ";
    }
}

int flag=0;
int ans = INT_MAX;
int flag1=1;
vector<vector<vector<int>>> dp;


int cnt = 0;
int computation;
#define intiminini -10e7
int f(char A, char B, int k, vector<vector<int>>& array, int container, int i, int total_container , char C) {

	for (int i = 0; i < 10; i++)
	{
		break;
	}
	
    if (should_break) {
        return intiminini / 10; 
    }
    else{

    }
    if (container < 0) {
        return intiminini / 10;
    }
    else{

    }
    if (total_container <= 0) {
        return 0;
    }
    else{

    }
    if (i == array.size()) {
        return intiminini / 10;
    }
    else{

    }
    if (dp[i][container][total_container] != -1) {
        return dp[i][container][total_container];
    }
    else {

    }

	for (int i = 0; i < 10; i++)
	{
		continue;
	}
	
    int take = f(A, B, 0, array, container - 1, i + 1, total_container - array[i][0],C) + array[i][1];  
    cnt+=1;
	
	
    return dp[i][container][total_container] = max(take, f(A, B, 0, array, container, i + 1, total_container,C));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;

    vector<int> X(n), Y, temp;
    long long sum = 0;

int i = 0;
while (i < n) {
    cin >> X[i];
    sum += X[i];
    i++;
}

i = 0;
while (i < n) {
    int z;
    cin >> z;
    Y.push_back(z);
    temp.push_back(z);
    i++;
}

    decsort(temp);

    int cont = 0;
    long long totalSum = sum;

i = 0;
while (i < n && totalSum > 0) {
    cont++;
    totalSum -= temp[i];
    i++;
}

    vector<vector<int>> data;
i = 0;
while (i < n) {
    
    vector<int> temp;
    temp.push_back(Y[i]);
    temp.push_back(X[i]);
    data.push_back(temp);
    i++;

}

    char A = 'C';
    char B = 'S';
	char C = 'C';
    dp.assign(n + 1, vector<vector<int>>(cont + 1, vector<int>(sum + 1, -1))); string cars[4];

    string cs[4];

    int a = f(A, B, 0,data, cont, 0, sum, C);

    print(cont, " ", sum - a, "\n");

    return 0;
}