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
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }


        if (n==2 && abs(vec[0]-vec[1])>1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
