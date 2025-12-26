#include <bits/stdc++.h>
using namespace std;
#define ll long long 
void solve()
{
    ll n;
    cin >> n;
    while (n)
    {

        cout << n << " ";
        if (n == 1)
            break;
        if (n & 1)
        {
            n = n * 3 + 1;
        }
        else
        {
            n /= 2;
        }
    }
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
