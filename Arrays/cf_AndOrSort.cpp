#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<pair<int,int>> v;
    int trappedZeroes = 0;
    int totalOnes=0;
    int ones=0,zeroes=0;
    
    for(int i=0; i<n; i++){

       if(ones && zeroes && s[i]=='1'){
        v.push_back({ones,zeroes});
        trappedZeroes+=zeroes;
        ones=0;
        zeroes=0;
       }

       if(s[i]=='1'){
        totalOnes++;
        ones++;
       }

       if(ones && s[i]=='0'){
        zeroes++;
       }
    }

    if(ones && zeroes){
        trappedZeroes+=zeroes;
        v.push_back({ones,zeroes});
    }

    if(s[0]=='1'){
      cout<<trappedZeroes<<endl;
      return ;
    } 


    int ans=trappedZeroes;
    int removedOnes=0;

    for(auto it:v){
        int zeroes=it.second;
        int ones=it.first;
        removedOnes+=ones;
        trappedZeroes-=zeroes;
        ans=min(ans,(removedOnes+trappedZeroes));

    }

    cout<<ans<<endl;





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