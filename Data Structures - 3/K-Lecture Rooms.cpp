/*------------------------------------
   bismillahir rahmanir rahim
   author : md. sajjat hossen
   created : 30-August,2021 10:45:44
-------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long             ll;
typedef long double           ld;
typedef unsigned long long    ull;
typedef pair <int, int>       pii;
typedef pair <ll, ll>         pll;
typedef vector <int>          vi;
typedef vector <ll>           vll;
typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds_multiset;

inline int Int() { int x; scanf("%d", &x); return x; }
inline ll Long() { ll x; scanf("%lld", &x); return x; }

int dx[8] = { 0, -1, 0, 1, -1, -1, 1, 1 };
int dy[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };

const int N           = (int) 2e5 + 5;
const int mxN         = (int) 1e6 + 6;
const int MOD         = (int) 1e9 + 7;
const int INF         = (int) 1e9 + 9;
const double EPS    = (double) 1e-9;

#define debug(x)    cerr << #x << " = " << x << '\n';
#define all(x)      x.begin(), x.end()
#define szof(x)     (int) x.size()
#define ff          first
#define ss          second
#define pb          push_back
#define mp          make_pair
#define PI          acos(-1.0)
#define TN          typename
#define nl          '\n'
#define Fast_IO     ios_base::sync_with_stdio(false); cin.tie(nullptr);

inline int add(int a, int b, int mod) { a += b; return a >= mod ? a - mod : a < 0 ? a + mod : a; }
inline int mult(int a, int b, int mod) { return (ll) a * b % mod; }

template <TN T> inline void umin(T &x, T y) { x = x < y ? x : y; }
template <TN T> inline void umax(T &x, T y) { x = x > y ? x : y; }

template <TN T> T gcd(T a, T b) { return !b ? a : gcd(b, a % b); }
template <TN T> T lcm(T a, T b) { return a * (b / gcd(a, b)); }

vi g[N];
int depth[N], spt[N][22];
int subTree[N];

void dfs(int u, int p = -1, int l = 0) {
    depth[u] = l;
    spt[u][0] = p;
    subTree[u] = 1;
    for (int k = 1; k <= 20; ++k) {
        spt[u][k] = spt[spt[u][k - 1]][k - 1];
    }
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u, l + 1);
        subTree[u] += subTree[v];
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = 20; k >= 0; --k) {
        if (depth[u] - (1 << k) >= depth[v]) {
            u = spt[u][k];
        }
    }
    if (u == v) return u;

    for (int k = 20; k >= 0; --k) {
        if (spt[u][k] != -1 and spt[u][k] != spt[v][k]) {
            u = spt[u][k];
            v = spt[v][k];
        }
    }
    return spt[u][0];
}

int goUp(int u, int l) {
    for (int k = 20; k >= 0; --k) {
        if ((1 << k) <= l) {
            u = spt[u][k];
            l -= (1 << k);
        }
    }
    return u;
}

int query(int u, int v, int n) {
    if (u == v) return n;
    if (depth[u] == depth[v]) {
        for (int k = 20; k >= 0; --k) {
            if (spt[u][k] != -1 and spt[u][k] != spt[v][k]) {
                u = spt[u][k];
                v = spt[v][k];
            }
        }
        return (n - subTree[u] - subTree[v]);
    }

    if (depth[u] < depth[v]) swap(u, v);
    int lcaNode = lca(u, v);
    int dis = depth[u] + depth[v] - 2 * depth[lcaNode];
    if (dis & 1) return 0;
    dis /= 2;
    int x = goUp(u, dis);
    int y = goUp(u, dis - 1);
    return subTree[x] - subTree[y];
}

void build() {
    memset(spt, -1, sizeof spt);
    dfs(1);
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // Fast_IO
    int test = 1, tc = 0;
    while (test--) {
        int n = Int();
        for (int i = 1; i < n; ++i) {
            int u = Int(), v = Int();
            g[u].pb(v);
            g[v].pb(u);
        }
        build();
        int q = Int();
        while (q--) {
            int u = Int(), v = Int();
            printf("%d\n", query(u, v, n));
        }
    }
    return 0;
}
