#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        unordered_set<char> st;
        vector<string> s(n);
        for (int &x : v)
        {
            cin >> x;
            st.insert(x[0]);
        }

        vector<string> a(n);
        bool poss=true;
        for (int &x : a)
        {
            cin >> x;
        }

        for (int i=0; i<m; i++)
        {

            for (auto &c : a[i])
            {
                if (st.find(c) == st.end())
                {
                    poss = false;
                    break;
                }
            }

            if (!poss)
            {
                break;
            }
        }

        if(poss){
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}