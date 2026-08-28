#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

#define pp pair<int,int>

void solve() {
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> mp;
    set<pp> s;

    for(int i=0; i<n; i++){
        s.insert({n-i,i+1});
        mp[i+1] = n-i;
    }

    int t=1,time=n+1;

    vector<int> ans(n,-1);

    for(int i=0; i<m; i++){
        int q;
        cin>>q;

        auto it=s.find({mp[q],q});
        
        if(it!=s.end()){
            pp p = *it;
            s.erase(it);

            s.insert({time,p.second});
            mp[p.second] = time;
        }else{
            auto front=*s.begin();
            if(front.second<=n){
                ans[front.second - 1] = t;
            }
           
            s.erase(front);

            s.insert({time,q});
            mp[q] = time;
        }




        t++;
        time++;
    }


    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
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