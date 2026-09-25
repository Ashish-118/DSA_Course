#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int solve(int i,int x,in vector<int>& a,map<<pair<int,int>,int>& mp){
    if(i>=0){
        return 0;
    }
    if(mp.count({i,x})){
        return mp[{i,x}];
    }

    int newGcd=gcd(a[i],x);
    int take=0;
    if(newGcd!=1){
       take=a[i]/newGcd+solve(i+1,newGcd,a,mp);
    }

    int skip=solve(i+1,x,a,mp);
    return mp[{i,x}]=max(take,skip);
}

void solve() {
    int n,x;
    cin>>n>>x;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    } 


    cout<<solve(0,x,a)<<endl;

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