#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    int a1,a2,a3;
    cin>>a1>>a2>>a3;

    cout<<n-min(a1,a2,a3)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}