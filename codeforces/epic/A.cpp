#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> Alice;
        vector<int> bob;
        int user;
        for (int i = 0; i < n; i++)
        {
            cin >> user;
            Alice.push_back(user);
        }
        for (int i = 0; i < n; i++)
        {
            cin >> user;
            bob.push_back(user);
        }

        if (Alice[0]==bob[0])
        {
         cout<<"Bob"<<endl;
        }
        else{
            cout<<"Alice"<<endl;
        }
        
        
    }

    return 0;
}