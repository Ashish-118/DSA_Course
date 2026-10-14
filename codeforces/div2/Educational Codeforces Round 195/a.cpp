#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int a,b;
    cin>>a>>b;
    
    if(a<=b){
        cout<<-1<<endl;
    }else{
        int chessPoss=a/2;
        int mini=min(chessPoss,b);
        a-=mini*2;
        b-=mini;
        int x=b-a;
        mini-=x;

        if(b+x<=mini){
            cout<<mini<<endl;
        }else{
            cout<<-1<<endl;
        }
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