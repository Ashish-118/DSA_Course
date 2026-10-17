#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n;
    cin>>n;

    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(begin(a),end(a));
    int mini=INT_MAX;
    int start=-1,end=-1;
    map<int,int> mp;

    for(int i=0; i<n-1; i++){
      if(abs(a[i]-a[i+1])<mini){
          mini = abs(a[i] - a[i + 1]);
          start=a[i];
          end=a[i+1];
      }

      mp[a[i]]++;
    }
    mp[a[n-1]]++;

    mp[start]--;
    mp[end]--;

    a[0]=start;
    auto it=mp.find(start);
    if(mp[start]==0){
        it++;
        mp.erase(start);
    }
    if (mp[end] == 0)
    {
        mp.erase(end);
    }

    int idx=1;

    while(it!=mp.end()){
        auto f=*it->second;
        auto val=*it->first;
        for(int i=0; i<f; i++){
            a[idx++]=val;
        }
        it++;
        mp.erase(val);
    }

    if(!mp.empty()){
        for (auto m : mp)
        {
            int f = m.second;
            int val = m.first;
            for (int i = 0; i < f; i++)
            {
                a[idx++] = val;
            }
            mp.erase(val);
        }
    }

    a[n-1]=end;


    for(auto x:a){
        cout<<x<<" ";
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