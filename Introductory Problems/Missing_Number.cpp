#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    ll n;
    cin >> n;
    vector<int> v(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    int ans = v[0];
    for (int i = 1; i <= n - 2; i++)
    {
        ans = ans ^ (v[i] ^ i);
    }
    ans ^= n ^ (n - 1);
    cout << ans;
}
int main()
{
    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
}
