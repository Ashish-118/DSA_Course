#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    vector<int> piles(3);
    cin >> piles[0] >> piles[1] >> piles[2];
    if(piles[1]-1==piles[0] && piles[1]+1==piles[2]) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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