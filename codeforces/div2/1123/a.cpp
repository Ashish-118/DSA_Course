#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    char c;
    cin>>c;
     
    string s;
    cin>>s;

    int count=0;

    for(int i=0; i<n/2; i++){
        if(s[i]==s[n-1-i]){
            continue;
        }

        if(s[i]==c || s[n-1-i]==c){
            count+=1;
        }else{
            count+=2;
        }
    }

    cout<<count<<endl;
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