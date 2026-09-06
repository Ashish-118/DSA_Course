#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);

    int zeroes=0;

    for(int i=0; i<n; i++){
        cin>>a[i];

        if(a[i]==0){
            zeroes++;
        }
    }

    if(zeroes==1){
        cout<<"NO"<<endl;
    }else{
        string ans="";
         int alt=0;
        for(int i=0; i<n; i++){
            if(a[i]>0){
                ans+="A";
            }else{
                if(alt==0){
                    ans+="B";
                    alt=1;
                }else{
                    ans+="C";
                    alt=0;
                }
            }
        }

        cout<<"YES"<<endl;
        cout<<ans<<endl;
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