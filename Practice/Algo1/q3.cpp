#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

int sus(string s, char c, int n) {
    if (n == 1 || n == 0) {
        return s[0] != c;
    }
    int mid = n / 2;
    int cnt1 = count(s.begin(), s.begin() + mid, c); 
    int cnt2 = count(s.begin() + mid, s.end(), c);
    return min(mid - cnt1 + sus(s.substr(mid), c + 1, mid), mid - cnt2 + sus(s.substr(0, mid), c + 1, mid));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << sus(s, 'a', n) << endl;
    }
    return 0;
}
