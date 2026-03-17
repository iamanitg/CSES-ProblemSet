#include <bits/stdc++.h>
using namespace std;

/* ===================== TYPE ALIASES & MACROS ===================== */
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pii>;
using vpll = vector<pll>;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

/* ===================== CONSTANTS ===================== */
const ll INFLL = 4e18;
const int INF = 1e9;
const int MOD = 1e9 + 7; // 998244353;
const ld EPS = 1e-9;
const ld PI = acos(-1);

/* ===================== FAST IO ===================== */
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);

/* ===================== DEBUG ===================== */
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = " << x << '\n'
#else
#define debug(x)
#endif

/* ===================== MODULAR MATH ===================== */
ll add(ll a, ll b) { return (a + b) % MOD; }
ll sub(ll a, ll b) { return (a - b + MOD) % MOD; }
ll mul(ll a, ll b) { return (a * b) % MOD; }

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

ll inv(ll a) { return binpow(a, MOD - 2); }

/* ===================== COMBINATORICS ===================== */
// const int MAXN = 2e5 + 5;
// ll fact[MAXN], invFact[MAXN];
// void precompute() {
//     fact[0] = invFact[0] = 1;
//     for(int i = 1; i < MAXN; i++) fact[i] = mul(fact[i - 1], i);
//     invFact[MAXN - 1] = inv(fact[MAXN - 1]);
//     for(int i = MAXN - 2; i >= 1; i--) invFact[i] = mul(invFact[i + 1], i + 1);
// }
// ll nCr(int n, int r) {
//     if(r < 0 || r > n) return 0;
//     return mul(fact[n], mul(invFact[r], invFact[n - r]));
// }

/* ===================== NUMBER THEORY ===================== */
ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }

// vector<bool> is_prime;
// vector<int> primes;
// void sieve(int n) {
//     is_prime.assign(n + 1, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int i = 2; i * i <= n; i++) {
//         if (is_prime[i]) {
//             for (int j = i * i; j <= n; j += i) is_prime[j] = false;
//         }
//     }
//     for(int i = 2; i <= n; i++) if(is_prime[i]) primes.pb(i);
// }

/* ===================== DSU ===================== */
struct DSU
{
    vector<int> p, sz;
    DSU(int n = 0)
    {
        p.resize(n + 1);
        sz.assign(n + 1, 1);
        iota(all(p), 0);
    }
    int find(int x)
    {
        return (p[x] == x) ? x : (p[x] = find(p[x]));
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

/* ===================== SEGMENT TREE ===================== */
struct SegTree
{
    int n;
    vector<ll> t;
    SegTree(int _n)
    {
        n = _n;
        t.assign(4 * n, 0); // Change 0 to INF for Min SegTree
    }
    ll merge(ll a, ll b) { return a + b; } // Easy to change to min/max

    void build(int v, int tl, int tr, const vector<ll> &a)
    {
        if (tl == tr)
        {
            t[v] = a[tl];
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    ll query(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0; // Change to INF for Min SegTree
        if (l == tl && r == tr)
            return t[v];
        int tm = tl + (tr - tl) / 2;
        return merge(query(v * 2, tl, tm, l, min(r, tm)),
                     query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }

    void update(int v, int tl, int tr, int pos, ll val)
    {
        if (tl == tr)
        {
            t[v] = val;
            return;
        }
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm)
            update(v * 2, tl, tm, pos, val);
        else
            update(v * 2 + 1, tm + 1, tr, pos, val);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
};

/* ===================== GRAPH ===================== */
// 4-directional
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};
// 8-directional
// vector<int> dx8 = {1, 1, 0, -1, -1, -1, 0, 1};
// vector<int> dy8 = {0, 1, 1, 1, 0, -1, -1, -1};

/* ===================== SOLVE ===================== */
void solve()
{
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // Kadane's Algorithm
    ll currentSum = 0, maxSum = INT64_MIN;
    for (int i = 0; i < n; i++)
    {
        currentSum += v[i];
        maxSum = max(currentSum, maxSum);
        if (currentSum < 0)
        {
            currentSum = 0;
        }
    }
    cout << maxSum;
}

/* ===================== MAIN ===================== */
int main()
{
    fastio;
    // precompute(); // Uncomment if using combinatorics
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
