#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    int start=-1,end=-1;


    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        if(i==0){
            start=x;
            end=x;
        }

        end=x;
    }
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