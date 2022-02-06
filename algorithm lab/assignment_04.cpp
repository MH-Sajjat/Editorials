#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool valid(ll n, ll m) {
    while (n) {
        int d = n % 10;
        n /= 10;
        if (!m) return 0;
        bool ok = 0;
        while (m) {
            int d1 = m % 10;
            m /= 10;
            if (d == d1) {
                ok = 1;
                break;
            }
        }
        if (!ok) return 0;
    }
    return 1;
}

int len(int n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ll num;
    cin >> num;
    int limit = cbrt(num) + 1;
    ll res = 0;
    for (int i = 1; i <= limit; ++i) {
        ll val = 1LL * i * i * i;
        if (valid(val, num)) {
            res = max(res, val);
        }
    }
    cout << res << endl;
    return 0;
}
