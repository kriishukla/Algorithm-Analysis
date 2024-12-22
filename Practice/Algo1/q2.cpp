#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binary_search(const vector<long long>& arr, long long target) {
    int left = 0, right = arr.size() - 1;
    int closest_index = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            closest_index = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return closest_index;
}

int main() {
    int n, b;
    cin >> n >> b;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    if (n == 0 || b == 0) {
        for (int i = 0; i < n; ++i) {
            cout << "0 ";
        }
        cout << endl;
        return 0;
    }

    vector<pair<long long, long long>> query(b);
    for (int i = 0; i < b; ++i) {
        cin >> query[i].first >> query[i].second;
    }

    sort(query.begin(), query.end());

    vector<long long> psum(b), base(b);
    base[0] = query[0].first;
    psum[0] = query[0].second;

    for (int i = 1; i < b; ++i) {
        base[i] = query[i].first;
        psum[i] = psum[i - 1] + query[i].second;
    }

    vector<long long> result(n);
    for (int i = 0; i < n; ++i) {
        int ind = binary_search(base, arr[i]);
        if (ind == -1) {
            result[i] = 0;
        } else {
            result[i] = psum[ind];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
