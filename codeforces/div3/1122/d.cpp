#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
vector<int> sieve;
void solve() {
    int n;
    cin>>n;
    


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve.assign(100001,true);
    int N=100001;

    sieve[1]=false;
    sieve[0]=false;

    for(int i=2; i*i<=N; i++){
        if(!sieve[i]) continue;
       sieve[i]=true;
       for(int j=i*i; j<=N; j+=i){
        sieve[j]=false;
       }
    }
    
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}