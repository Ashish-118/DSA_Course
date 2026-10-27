#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n,k;
    cin>>n>>k;

    vector<int> v(n);
    vector<int> visited(101,false);
    vector<int> index(n, 0);

    if(k==1){
        cout<<-1<<endl;
        return;
    }
    for(int i=0; i<n; i++){
        cin>>v[i];
        if(i<=n-k){
            visited[v[i]] = true;
        }
        index[v[i]] = i;
    }

    int start=-1,end=-1;

    int prev=-1;

    for(int i=0; i<101; i++){
        if(visited[i]==false){
            prev=i;
            start=n-k;
            end=index[i];
            visited[i]=true;
           
            break;
        }
    }

    for(int i=n-1; i>=0; i--){
        if(visited[i]==true){
            visited[i]=false;
            break;
        }
    }
    int curr=-1;

    for(int i=0; i<n; i++){
        if(visited[i]==false){
            curr=i;
        }
    }

    if(curr<prev){
        cout<<-1<<endl;
        return;
    }



    cout<<start<<" "<<end<<endl;



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