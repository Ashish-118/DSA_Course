#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

    int t;
    cin>>t;
    while(t--){
        int n,d;
        cin>>n>>d;

        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        bool needed=false;

        for(auto x:arr){
            if(x>d){
                needed=true;
                break;
            }
        }
        bool pairAvail=false;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[i]+arr[j]<=d){
                    pairAvail=true;
                    break;
                }
            }
        }

        if(!needed || pairAvail){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }


    }

return 0;
}