#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,m;
    cin>>n>>m;

    int T_o=0;
    int T_e=0;

    int K_o=0;
    int K_e=0;

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x%2==0){
            T_e++;
        }
        else{
            T_o++;
        }
    }

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(x%2==0){
            K_e++;
        }
        else{
            K_o++;
        }
    }

    cout<<min(T_e,K_o)+min(T_o,K_e)<<endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
   
  
        solve();
    
    return 0;
}