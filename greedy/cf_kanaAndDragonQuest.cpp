#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int x,n,m;
    cin>>x>>n>>m;

    for(int i=0; i<n && x>20; i++) {
        x = x/2 + 10;
    }

    for(int i=0; i<m; i++) {
        x-= 10;
    }

    if(x<=0) {
        cout<<"YES"<<endl;
    } else {
        cout<<"NO"<<endl;
    }
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