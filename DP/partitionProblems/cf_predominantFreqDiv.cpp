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

        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        bool poss = false;
        int countGreater_1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 1)
            {
                countGreater_1++;
            }

            if (countGreater_1 <= (i + 1) / 2)
            {
                int countGreater_2 = 0;
                for (int j = i + 1; j < n - 1; j++)
                {
                    if (arr[j] > 2)
                    {
                        countGreater_2++;
                    }

                    if (countGreater_2 <= (j - i) / 2)
                    {
                        poss = true;
                        break;
                    }
                }
            }

            if (poss)
            {
                break;
            }
        }

        if (poss)
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