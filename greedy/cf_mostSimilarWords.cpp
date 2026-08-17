#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

int t;
cin>>t;

while(t--){
    int n,m;
    cin>>n>>m;

    vector<string> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    int ans=INT_MAX;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int cnt=0;
            for(int k=0; k<m; k++){
               cnt+=(abs(v[i][k]-v[j][k]));
            }
            ans=min(ans,cnt);
        }
    }

    cout<<ans<<endl;
}

return 0;
}