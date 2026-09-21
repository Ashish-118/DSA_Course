#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a,b,c;
    cin>>a>>b>>c;

    cout<<max((abs(a-b)),abs(a+c-b))<<endl;
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