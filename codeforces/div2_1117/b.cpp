#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'



int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        vector<int> b(m);
        for(int i=0; i<m; i++){
            cin>>b[i];
        }

        int benSteps=0,verSteps=0;

        for(int i=1; i<n; i++){
          benSteps+=abs((a[i]-1)-a[i-1]);
        }
        benSteps+=a[n-1];

        for(int i=1; i<m; i++){
          verSteps+=abs((b[i]-1)-b[i-1]);
        }
        verSteps+=b[m-1];

        if(benSteps<verSteps){
            cout<<2<<endl;
        }else{
            cout<<1<<endl;
        }


    }
    return 0;
}