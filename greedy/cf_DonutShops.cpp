#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    double a,b,c;
    cin>>a>>b>>c;

    int shop1=(c>a?1:-1);

    double perDonut=c/b;
    int shop2=(perDonut>=a?-1:b);

    cout<<shop1<<" "<<shop2<<endl;
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