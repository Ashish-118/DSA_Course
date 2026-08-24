#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,s;
    cin>>n>>s;

    cout<<s/n+(s%n!=0?1:0)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
        solve();
    
    return 0;
}