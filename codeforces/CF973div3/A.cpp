#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
int t;
cin>>t;
while (t--)
{
   int n,k;
   cin>>n>>k;
   int robin=0;
vector<int> v(n);
for (int i = 0; i < n; i++)
{
    cin>>v[i];
}
int c=0;
for (int i = 0; i < n; i++)
{
    if(v[i]==0 && robin!=0){
    robin--;
     c++;
    }
   else if(v[i]>=k){
    robin+=v[i];
    v[i]=0;
   }
}
cout<<c<<endl;

   
}

return 0;
}