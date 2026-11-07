#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        a[i]=pow(2, x);
    }

    sort(begin(a),end(a));

    int num1=a[n-2],num2=a[n-1];

    int j=n-3;
    while(j>=0){
        if(num1<=num2){
            num1+=a[j--];
        }else{
            num2+=a[j--];
        }
        
    }

    cout<<num1*num2<<endl;

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