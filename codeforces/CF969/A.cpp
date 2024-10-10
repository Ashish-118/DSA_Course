#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        if (l < r)
        {
            vector<int> v(r - l + 1);

            for (int i = l; i <= r; i++)
            {
                v.push_back(i);
            }
            int count = 0;
            int i = 0;
            while (i <= (v.size() - 1 - 2))
            {

                if (v[i] & 1)
                {
                    count++;
                    i += 4;
                }
                else
                {
                    i++;
                }
            }

            cout << count << endl;
        }
        else if(l>r)
        {
            vector<int> v(l - r + 1);

            for (int i = r; i <= l; i++)
            {
                v.push_back(i);
            }
            int count = 0;
            int i = 0;
            while (i <= (v.size() - 1 - 2))
            {

                if (v[i] & 1)
                {
                    count++;
                    i += 4;
                }
                else
                {
                    i++;
                }
            }

            cout << count << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

    return 0;
}