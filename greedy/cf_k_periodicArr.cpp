#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int ans=0;

    int blocks=n/k;

    for(int i=0; i<k; i++){
        int ones=0,twos=0;
       for(int b=0; b<blocks; b++){
           if(v[k*b+i]==1){
               ones++;
           }
           else{
               twos++;
           }
       }

       ans+=min(ones,twos);
    }

     cout<<ans<<endl;
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