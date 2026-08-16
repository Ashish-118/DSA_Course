#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

int t;
cin>>t;

while(t--){
    int n,k,p;
    cin>>n>>k>>p;
    k=abs(k);

    int required=((k%p==0)?k/p:(k/p)+1);

    if(required<=n){
        cout<<required<<endl;
    }else{
        cout<<-1<<endl;
    }
  
  
}

return 0;
}