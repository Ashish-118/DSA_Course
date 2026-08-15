#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){

int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    vector<bool> visited(n,false);
    int i = 0;
    while(i<n){
        if(visited[i]==true){
            continue;
        }

        int max_min=-1;
        int idx=-1;
        for(int j=i+1; j<n; j++){
          if(visited[j]==false && a[j]<a[i] && max_min<a[j]){
            max_min=a[j];
            idx=j;
          }
        
        }
        if(idx!=-1){
            ans++;
            visited[idx]=true;
        }else{
            visited[i]=true;
            i++;
        }
    }
    cout<<ans<<endl;
}

return 0;
}