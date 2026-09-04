#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);

    int sum=0;

    for(int i=0; i<n; i++){
        cin>>a[i];

        sum+=pow(a[i],2);
    }

    sort(a.begin(), a.end());

    for(int i=0; i<n/2; i++){
        sum+=(2*a[i]*a[n-1-i]);
    }
    cout<<sum<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
        solve();
    
    return 0;
}