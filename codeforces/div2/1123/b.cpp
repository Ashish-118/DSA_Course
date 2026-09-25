#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> ans(n);
    map<int, int, greater<int>> mp;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        mp[x]++;
    }

    int i=0; 
    
    while(i<n){
        for(auto x:mp){
            if(x.second){
                ans[i]=x.first;
                x.second--;
                i++;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
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