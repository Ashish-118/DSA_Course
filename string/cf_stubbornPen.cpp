
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    int color=0;

    int ans=0;

    for(int i=0; i<n; i++){
        int c=(s[i]=='R')?0:1;
        if(c!=color)
        {
            ans++;
            color = !color;
        }


        color=!color;
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