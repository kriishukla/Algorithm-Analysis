#include <bits/stdc++.h>
using namespace std;

bool printSubsequences(vector<int> arr, int index, vector<int> subarr, int n) {
    if (index == arr.size()) {
        if (!subarr.empty()) {
            int sum = accumulate(subarr.begin(), subarr.end(), 0);
            if (sum % n == 0) {
                return true;
            }
        }
    } else {
        if (printSubsequences(arr, index + 1, subarr, n)) {
            return true;
        }
        subarr.push_back(arr[index]);
        if (printSubsequences(arr, index + 1, subarr, n)) {
            return true;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        vector<int> arr(m);
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        bool flag = true;
        for (int i = 0; i < m; i++) {
            if (!flag) {
                break;
            }
            vector<int> arr1(arr);
            arr1.erase(arr1.begin() + i);

            if (!printSubsequences(arr1, 0, {}, n)) {
                flag = false;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}