#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    int ans=n;


    vector<pair<int,int>> p;
    for(int i=n-1; i>=1; i--){
        p.push_back({ans,i});
        ans=(ans+i+1)/2;
    }
    cout<<ans<<endl;

    for(auto x:p){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl;
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