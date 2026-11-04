#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int r,s,p;
    cin>>r>>s>>p;

    if(s>=p){
        cout<<string(r+s+p,'R')<<endl;
    }else if(p>=r){
        cout<<string(r+s+p,'S')<<endl;
    }else{
        cout<<string(r+s+p,'P')<<endl;
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