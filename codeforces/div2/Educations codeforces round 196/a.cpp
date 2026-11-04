#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int l,r;
    cin>>l>>r;

    int ans=r-l;
   
    if(l<=0 && r>=0){
        int left = abs(0 - l);
        int right = abs(0 - r);
        int mini = min(left, right);
        int ans = 2 * mini + 1;

        if(mini>l || mini>r){
            ans++;
        }
        
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