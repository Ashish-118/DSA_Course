#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];  
    }

    int ans=1;
    sort(begin(a),end(a));
    
    for(int i=0; i<n; i++){
        int count=1;
        for(int j=i+1; j<n; j++){
          if(a[j]%a[i]==0){
              count++;
          }
        }
        ans=max(ans,count);
    }
    cout<<n-ans<<endl;
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