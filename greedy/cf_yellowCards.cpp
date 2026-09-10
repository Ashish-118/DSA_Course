#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a1,a2,k1,k2,n;
    cin>>a1>>a2>>k1>>k2>>n;

    int minReq=(k1-1)*a1+(k2-1)*a2;
    int left=min(0,n-minReq);
    cout<<left<<" ";


    int maxi=0;
    if(k1<k2){
        int poss_a1=min(a1,n/k1);
        n-=poss_a1*k1;
        maxi+=poss_a1;

        int poss_a2=min(a2,n/k2);
        n-=poss_a2*k2;
        maxi+=poss_a2;
    }else{
        int poss_a2=min(a2,n/k2);
        n-=poss_a2*k2;
        maxi+=poss_a2;

        int poss_a1=min(a1,n/k1);
        n-=poss_a1*k1;
        maxi+=poss_a1;

    }

    cout<<maxi<<endl;
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