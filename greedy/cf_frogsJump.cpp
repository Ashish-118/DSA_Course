
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;

    int ones = count(begin(s1), end(s1), 'f') + count(begin(s2), end(s2), 'f');

    cout << (ones & 1) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
