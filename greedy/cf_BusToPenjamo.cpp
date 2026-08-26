#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,r;
    cin>>n>>r;
    int totalMem=0;

    int unHappyMem=0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        totalMem+=x;

        r-=xor_eq/2;

        if(x&1){
            unHappyMem++;
        }
    }

    cout << totalMem-2 * (unHappyMem - min(r, unHappyMem)) << endl;
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