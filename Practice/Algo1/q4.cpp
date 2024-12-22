#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
template <typename T>
int binary_search(vector<T>& arr, T target) {
    int left = 0, right = arr.size() - 1, closest_index = -1;

    for (; left <= right; ) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) {
            closest_index = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return closest_index;
}
bool sum_possible(vector<int>& arr, long long k);

int find_less_equal_index(vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    int result_index = -1;

    for (; left <= right; ) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
            result_index = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result_index;
}


void quest(vector<int>& arr, vector<long long>& sum_list, long long highest) {
    int n = arr.size();
    if (n <= 1) {
        if (n == 1) sum_list.push_back(arr[0]);
        return;
    }

    long long mid = (arr[0] + highest) / 2;
    sum_list.push_back(accumulate(arr.begin(), arr.end(), 0LL));
    if (arr[0] == highest) return;

    int ind = binary_search(arr, static_cast<int>(mid));
    vector<int> left(arr.begin(), arr.begin() + ind + 1);
    vector<int> right(arr.begin() + ind + 1, arr.end());

    quest(left, sum_list, left[ind]);
    quest(right, sum_list, arr[n - 1]);
}

int find_greater_equal_index(vector<int>& arr, int target) {
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1; // Convert size() to int
    int result_index = -1;
 
    for (; left <= right; ) {
        int mid = left + (right - left) / 2;
 
        if (arr[mid] >= target) {
            result_index = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
 
    return result_index;
}


bool sum_possible(vector<int>& arr, int k) {
    int n = static_cast<int>(arr.size()); 
    if (n == 0) {
        return false;
    }
 
    int _min = *min_element(arr.begin(), arr.end());
    int _max = *max_element(arr.begin(), arr.end());
    int mid = (_min + _max) / 2;
    int h = find_less_equal_index(arr, mid);
 
    vector<int> left_group(arr.begin(), arr.begin() + h + 1);
    vector<int> right_group(arr.begin() + h + 1, arr.end());
 
    int _sum = accumulate(arr.begin(), arr.end(), 0);
 
    if (_sum == k) {
        return true;
    } else if (left_group.size() == n || right_group.size() == n) {
        return false;
    }
 
    return sum_possible(left_group, k) || sum_possible(right_group, k);
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}


int binary_search(vector<long long>& arr, long long target) {
    int left = 0, right = arr.size() - 1;

    for (; left <= right; ) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    for (int test_case = 0; test_case < t; ++test_case) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        int i = 0;
        while (i < n) {
            cin >> a[i];
            ++i;
        }

        vector<int> query(q);
        i = 0;
        while (i < q) {
            cin >> query[i];
            ++i;
        }

        sort(a.begin(), a.end());

        vector<long long> sum_list;
        quest(a, sum_list, a[n - 1]);
        sort(sum_list.begin(), sum_list.end());

        for (long long x : query) {
            int ind = binary_search(sum_list, x);
            cout << (ind == -1 ? "No" : "Yes") << endl;
        }
    }

    return 0;
}
