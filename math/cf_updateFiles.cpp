#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin>>n>>k;
    n--;
    int hours=0;
    int patched=1;
    int i=0;
    while(n>0 && k>=patched){
       n-=patched;
       patched*=2;
       hours++;
    }
    n=max(0LL,n);
    hours+=(n%k==0)?n/k:(n/k)+1;

    cout<<hours<<endl;

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