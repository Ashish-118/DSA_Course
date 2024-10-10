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
        string s = "";
        if (n & 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < (n) / 2; i++)
            {
                s = s + char(65 + i) + char(65 + i);
            }
            cout << s << endl;
        }
    }

    return 0;
}