#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int start=-1,end=-1;
    int count=0;
    for(int i=0; i<n; i++){
       if(s[i]=='1'){
        count++;
        if(start==-1){
            start=i;
        }
        end=i;
       }
    }
    
    if(count==(end-start+1-2)){
        cout<<1<<endl;

    }  
    else{
        cout<<end-start<<endl;
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