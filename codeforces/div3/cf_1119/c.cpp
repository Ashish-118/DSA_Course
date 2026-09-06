#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int start=INT_MAX,end=-1;

    for(int i=0; i<n; i++){
        cin>>a[i];

        if(a[i]==1 || a[i]==-1){
            start=min(start,i);
            end=max(end,i);
        }
    }


    int maxi=0;
    int startingIdx=-1;
    int zeroes=0;

    for(int i=start+1; i<=end; i++){
        if(i!=end && (a[i]==0 || a[i]==-1)){
            zeroes++;
        }

        if(i==end || a[i]==1){
            
            if(zeroes>maxi){
                maxi=zeroes;
                startingIdx=i-zeroes;
            }
            zeroes=0;
        }
       
    }

    for(int i=0; i<n; i++){
        if(i>=startingIdx && i<startingIdx+maxi){
         a[i]=0;
        }
        else{
            if(a[i]==-1){
                a[i]=1;
            }
        }
    }


    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }

    cout<<endl;

    





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