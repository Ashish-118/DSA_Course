#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,r,b;
    cin>>n>>r>>b;

    int R_inEachSlot=r/(b+1);
    int rem=r%(b+1);
    string ans="";

    for(int i=1; i<=b+1; i++) {
        if(i<=rem){
            ans+=string(R_inEachSlot+1,'R');
            ans+='B';
        }
        else{
            ans+=string(R_inEachSlot,'R');
            if(i!=b+1) ans+='B';
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