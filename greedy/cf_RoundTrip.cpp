#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int R0, X, D ,n;

    cin >> R0 >> X >> D >> n;

    string s;
    cin>>s;

    int count=0;

    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            R0=min(0,R0-D);
            count++;
        }else{
          if(R0<X){
            count++;
            R0 = min(0, R0 - D);
          }
        }
    }
    cout<<count<<endl;
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