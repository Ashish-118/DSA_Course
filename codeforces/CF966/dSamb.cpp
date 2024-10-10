#include<bits/stdc++.h>
#define int long long
using namespace std;

int solve()
{
    int n;
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++)
    {
        cin>>vec[i];
    }
    string s;
    cin>>s;
    vector<int>difference_array(n+1,0);
    for(int left=0,right=n-1;left<right;)
    {
        while(left<right&&s[left]!='L')
        {
            left++;
        }
        while(right>left&&s[right]!='R')
        {
            right--;
        }
        if(left<right)
        {
            difference_array[left++]++;
            difference_array[right--+1]--;
        }
        else
        {
            break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        difference_array[i]+=difference_array[i-1];
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=vec[i]*difference_array[i];
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