#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
       int n,m;
       cin>>n>>m;

       unordered_map<int,int> mp;

       for(int i=0; i<n; i++){
             int x;
             cin>>x;
              mp[x]++;
       }
       int ans=INT_MIN;
       for(int i=1; i<=m; i++){
           if(mp.count(i)){
             n-=mp[i];
           }

           ans=max(ans,mp[i]+mp[2*i]*2+n-mp[2*i]);
       }
    }
    return 0;
}