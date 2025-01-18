#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string n;
        cin >> n;
        int c = 0;
        int first_3 = -1;
        while (!n.empty() && n != "0")
        {

            for (int i = 0; i < n.size(); i++)
            {
                if (c == 2)
                {
                    c = 0;

                    n.erase(first_3, 2);
                }
                if (n[i] == '3')
                {
                    c++;
                    first_3 = first_3 == -1 ? i : first_3;
                }
                else
                {
                    c = 0;
                    first_3 = -1;
                }
            }

            if (!n.empty() && stoi(n) >= 33)
            {
                int num = stoi(n);
                num = num - 33;
                n = to_string(num);
            }
            else
            {
                break;
            }
        }
        if (n == "0" || n.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}