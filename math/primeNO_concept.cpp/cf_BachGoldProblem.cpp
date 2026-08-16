#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

int t;
cin>>t;

while(t--){


    int n;
    cin>>n;

    vector<int> arr;
    int noOfTwo=(n&1?n/2-1:n/2);

    for(int i=0; i<noOfTwo; i++){
        arr.push_back(2);
    }

    if(n&1){
        arr.push_back(3);
    }

    cout<<arr.size()<<endl;
    for(auto x:arr){
        cout<<x<<" ";
    }
    cout<<endl;
}


return 0;
}