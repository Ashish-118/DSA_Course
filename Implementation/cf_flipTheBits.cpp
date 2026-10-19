#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;

    int zeroes=0,ones=0;
    int sameBit=0;

    for(int i=0; i<n; i++){

        if(a[i]=='0') zeroes++;
        else ones++;

    }

    bool poss=true;
    for(int i=n-1; i>=0; i--){

        if(sameBit){

            if(a[i]==b[i] && zeroes!=ones){
                poss=false;
                break;
            }else if(a[i]==b[i]){
                sameBit=0;
            }

        }else{
            if(a[i]!=b[i] && zeroes!=ones){
               poss=false;
               break;
            }else if(a[i]!=b[i]){
                sameBit=1;
            }
        }
      



        if(a[i]=='0'){
            zeroes--;
        }else{
            ones--;
        }
    }

    if(poss) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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