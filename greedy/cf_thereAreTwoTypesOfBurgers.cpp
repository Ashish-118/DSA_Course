#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int b,p,f;
    cin>>b>>p>>f;
    int h,c;
    cin>>h>>c;
    int profit=0;
    int poss=b>>1;

    if(h>=c){
       int temp=min(poss,p);
       poss-=temp;
       p-=temp;
       profit+=temp*h;
    }else{
        int temp=min(poss,f);
        poss-=temp;
        f-=temp;
        profit+=temp*c;
    }

    if(poss){
        if(h!=0){
            int temp=min(poss,p);
            p-=temp;
            profit+=temp*h;
        }else{
            int temp=min(poss,f);
            f-=temp;
            profit+=temp*c;
        }
    }


    cout<<profit<<endl;




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