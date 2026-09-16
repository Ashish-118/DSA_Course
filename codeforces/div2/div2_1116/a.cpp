#include <bits/stdc++.h>
using namespace std;


int main(){


    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;

        a=min(a, b+c);
        b=min(b, a+c);
        c=min(c, a+b);
        
        cout<<max({a,b,c})-min({a,b,c})<<endl;
    }

    return 0;
}