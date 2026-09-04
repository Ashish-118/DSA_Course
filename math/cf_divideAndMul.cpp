#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);

    int factor_2=0;

    for(int i=0;i<n;i++){
        cin>>a[i];
        while(a[i]%2==0){
            a[i]/=2;
            factor_2++;
        }
    }

    sort(a.begin(),a.end());
    a[n-1]*=(1LL<<factor_2);

    cout<<accumulate(a.begin(),a.end(),0LL)<<endl;
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