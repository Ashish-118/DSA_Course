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
        int a,b;
        cin >> a >> b;
        if (a%2==0 && b%2==0)
        {
            cout << "YES"<<endl;
        }

        else if(b&1 && (a>=2 && a%2==0)){
            cout<<"YES"<<endl;
        }
 
        else{
            cout<<"NO"<<endl;
        }
        

    }
    return 0;
}