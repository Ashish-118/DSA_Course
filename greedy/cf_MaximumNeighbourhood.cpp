#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    int maxi=0;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int cellV=n*i+j+1;
            int topCellV=(i>0? n*(i-1)+j+1:0);
            int bottomCellV=(i<n-1? n*(i+1)+j+1:0);
            int leftCellV=(j>0? n*i+j:0);
            int rightCellV=(j<n-1? n*i+j+2:0);
            maxi=max(maxi,cellV+topCellV+bottomCellV+leftCellV+rightCellV);
        }
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