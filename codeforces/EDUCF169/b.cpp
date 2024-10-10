#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a1, a2;
        int b1, b2;
        cin >> a1 >> a2;
        cin >> b1 >> b2;

        if (b1 > a2 || b2<a1)
        {
            cout << 1 << endl;
        }
        else if ((a2 == b1 && a2 < b2) || (b2 == a1 && b2 < a2))
        {
            cout << 2 << endl;
        }

        else if (a1 == b1 && a2 == b2)
        {
            cout << (a2 - a1) << endl;
        }

        else if (((a2 > b1 && a2 < b2) || (b2 > a1 && b2 < a2)) && a1 != b1 && b2 != a2)
        {
     
            int a = max(a1, b1);
            int b = min(a2, b2);
            cout << 2 + abs(a - b) << endl;
        }
        else 

        {
            int b = min(a2, b2);
            int a = max(a1, b1);
            cout << 1 + abs(a - b) << endl;
        }
    }

    return 0;
}
