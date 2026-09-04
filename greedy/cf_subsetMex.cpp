#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n; 

    vector<int> a(101,0);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[x]++;
    }

    int A=0,B=0;

    for(int i=0; i<101; i++){
        if(a[i]==0){
            A=i;
            break;
        }else{
            a[i]--;
        }
    }

    for(int i=0; i<101; i++){
        if(a[i]==0){
            B=i;
            break;
        }else{
            a[i]--;
        }
    }
    cout<<A+B<<endl;
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