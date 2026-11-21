#include <bits/stdc++.h>
using namespace std;

void solve(int tc)
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dif(n);
    for (int &x : a)
    {
        cin >> x;
        x &= 1;
    }
    int off = 0, tot = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        a[i] ^= off;
        tot ^= a[i];
        dif[max(i - k, 0)] ^= a[i];
        off ^= dif[i] ^ a[i];
    }
    cout << (tot ? "Alice" : "Bob") << endl;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i);
}