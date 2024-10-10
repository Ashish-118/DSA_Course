#include<bits/stdc++.h>
#define int long long
using namespace std;

vector<int>getContribution(int n,int k)
{
    vector<int>difference_array(n+1,0);
    for(int i=0;i+k-1<n;i++)
    {
        difference_array[i]++;
        difference_array[i+k]--;
    }
    for(int i=1;i<n;i++)
    {
        difference_array[i]+=difference_array[i-1];
    }
    difference_array.pop_back();
    return difference_array;
}

int solve()
{
    int n,m,k,w;
    cin>>n>>m>>k>>w;
    vector<int>vec(w);
    for(int i=0;i<vec.size();i++)
    {
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end(),greater<int>{});
    int ans=0;
    vector<int>contribution(n*m,0),row=getContribution(n,k),col=getContribution(m,k);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            contribution[i*m+j]=row[i]*col[j];
        }
    }
    sort(contribution.begin(),contribution.end(),greater<int>{});
    for(int i=0;i<w;i++)
    {
        ans+=vec[i]*contribution[i];
    }
    return ans;
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}