#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    int min1,max1;
    cin>>min1>>max1;
    int min2,max2;
    cin>>min2>>max2;
    int min3,max3;
    cin>>min3>>max3;

    int first=min1;
    int second=min2;
    int third=min3;
    n-=first+second+third;

    if(n>0){
        int add1=min(n,max1-min1);
        first+=add1;
        n-=add1;
    }

    if(n>0){
        int add2=min(n,max2-min2);
        second+=add2;
        n-=add2;
    }

    if(n>0){
        int add3=min(n,max3-min3);
        third+=add3;
        n-=add3;
    }

    cout<<first<<" "<<second<<" "<<third<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}