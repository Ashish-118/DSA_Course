#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<int> mem;
    vector<int> printed(n+1,0);
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;

        if(x==1){
            mem.push_back(i);
        }else if(x==2){
            if(mem.size()>0){
                printed[mem.back()]=1;
                mem.pop_back();
            }
        }else{
            printed[i]=1;
        }
    }
    cout<<count(printed.begin(),printed.end(),0)<<endl;

    for(int i=1;i<=n;i++){
        if(printed[i]==0){
            cout<<i<<" ";
        }
    }
    cout<<endl;
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