#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        if ((v[n-1]-v[n-2])>1)
        {
            cout<<"Ambiguous"<<endl;
        }
        else{
            
            cout<<v[n-2]<<endl;
        }
        
    }
    

return 0;
}