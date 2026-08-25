#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int>v(n+1);

    for(int i=1; i<=n; i+=k){
        int req=(i%k==0?i/k:i/k+1);
        int leftOnes=accumulate(v.begin(),v.begin()+i,0);
       
        if(leftOnes<req){
            v[i]=1;
        }
        int rightOnes = accumulate(v.begin() + n - (i - 1), v.end(), 0);
        if(rightOnes<req){
            v[n-(i-1)]=1;
        }

    }

    cout<<accumulate(v.begin(),v.end(),0)<<endl;
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