#include <bits/stdc++.h>

using namespace std;

int check(int x, int to_use)
{
    if ((x / to_use) == 0)
    {
        return 0;
    }
    if ((x / to_use) == 10)
    {
        string s="";
        int copy=x;
        for(int i=10; i<=to_use; i=i*10){
            int remainder=copy%10;
            s=s+to_string(remainder);
            copy=copy/10;
        }

        if(s.back()=='0'){
            return 0;
        }
        else{
           return x % to_use;
        }

    }

  return  check(x, to_use * 10);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    vector<string> ans;
    vector<int> user;

    for (int j = 0; j < T; j++)
    {

        int n;

        cin >> n;
        user.push_back(n);

    }

    for (auto x : user)
    {
    

        if (check(x, 10) >= 2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
