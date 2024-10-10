#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
int t;
cin>>t;
while (t--)
{
    int n;
    cin >> n;
    int x,y;
    cin>>x>>y;
    int mini=min(x,y);

    if (n%mini==0)
    {
        cout<<n/mini<<endl;
    }
    else{
        cout<<(n/mini)+1<<endl;
    }
    
}

return 0;
}