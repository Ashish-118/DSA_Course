#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

     int t;
     cin>>t;
    
        int k2,k3,k5,k6;
        cin>>k2>>k3>>k5>>k6;

        int ans=0;
        int mini=min({k2,k5,k6});
        k2-=mini;
        k5-=mini;
        k6-=mini;
        ans+=(256*mini);
        mini=min(k2,k3);
        ans+=(32*mini);
        cout<<ans<<endl;

     

return 0;
}