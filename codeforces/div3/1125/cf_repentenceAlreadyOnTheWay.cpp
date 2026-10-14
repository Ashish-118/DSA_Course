#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    vector<int> b(n);
    for(int i=0; i<n; i++){
        cin>>b[i];
    }


    vector<int> dp(n, 0);
    
    int curr=1+(a[n-1]==b[n-1]);
    dp[n-1]=curr;

    for(int i=n-2; i>=0; i--){
        curr+=1+(a[i]==b[i+1]);
        curr+=1+(b[i]==a[i+1]);

        dp[i]=max(curr,dp[i+1]+2+(a[i]==b[i])+(b[i]==a[i+1]));
    }

    cout<< dp[0] << endl;
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