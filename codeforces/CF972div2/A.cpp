#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string str="";
        string to_add="aeiou";
        int cal=n/5;
        int c=n-5*cal;
        for (int i=0; i<cal; i++)
        {
           str=str+to_add;
        }

        for (int i=0; i<c; i++)
        {
            str=str+to_add[i];
        }
        
        cout<<str<<endl;
        


        
    }
    return 0;
}