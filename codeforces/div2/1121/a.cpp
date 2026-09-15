#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    bool poss=false;

    int border=n;

    for(int i=0; i<n; i++){
        if(v[i]-1 == i){
            continue;
        }

        int idx=v[i]-1;

        if(idx>border || idx<border && v[idx]-1!=i){
            poss=false;
            break;
        }

        swap(v[i], v[idx]);
        border=idx;
    }


    if(poss){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
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