#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;

        int first=0;
        int last=0;
        for(int i=0; i<n; i++){
            if(i==0){
                cin>>first;
            }else if(i==n-1){
                cin>>last;
            }
        }

        cout<<gcd(first, last)<<endl;
    }
    return 0;
}