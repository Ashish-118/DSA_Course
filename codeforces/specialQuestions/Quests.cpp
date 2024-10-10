#include <bits/stdc++.h>
#define int long long
using namespace std;

bool poss(int mid, int c, int d, vector<int> v){
    int score=0,n=v.size();
    for (int i = 0; i < d; i++)
    {
        if(i%mid<n) score+=v[i%mid];
    }

    return score>=c;
    
}

int32_t main(){
int t;
cin>>t;
while (t--){

int n,c,d;
cin>>n>>c>>d;

vector<int> v(n);
for(int i=0;i<n;i++)cin>>v[i];

sort(v.rbegin(), v.rend()); //sorts in descending order

int lo=1,hi=1e9;
int result=0;

while(lo<=hi){
    int mid=(lo+hi)>>1;
    if (poss(mid,c,d,v))
    {
       result=mid;
       lo=mid+1;
    }
    else{
        hi=mid-1;
    }
    
}

if(result==0){
    cout<<"Impossible"<<endl;
}
else if(result>d){
    cout<<"Infinity"<<endl;
}
else{
    cout<<result-1<<endl;
}


    
}

return 0;
}