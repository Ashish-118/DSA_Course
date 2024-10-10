#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;

        if (k & 1) // odd
        {
            if (x == 0 && y == 0)
            {
                for (int i = 1; i < k; i = i + 2)
                {
                    if (i == 1)
                    {
                        cout << 0 << " " << 0 << endl;
                    }
                    
                    
                        cout << i << " " << i << endl;
                        cout << -i << " " << -i << endl;
                    
                }
            }
            else
            {

                for (int i = 1; i <= k; i = i + 2)
                {
                    if (i == k)
                    {

                        cout << (x * i) << " " << (y * i) << endl;
                        break;
                    }
                    else
                    {
                        cout << (x * i) << " " << (y * i) << endl;
                        cout << (x * (-i)) << " " << (y * (-i)) << endl;
                    }
                }
            }
        }
        else
        {

            if (x == 0 && y == 0)
            {
                for (int i = 1; i < k; i = i + 2)
                {
                    cout << i << " " << i << endl;
                    cout << -i << " " << -i << endl;
                }
            }
            else
            {
                for (int i = 0; i <= k; i = i + 2)
                {
                    if (i == 0 || i == k)
                    {
                        cout << (x * i) << " " << (y * i) << endl;
                    }
                    else
                    {

                        cout << (x * i) << " " << (y * i) << endl;
                        cout << (x * (-i)) << " " << (y * (-i)) << endl;
                    }
                }
            }
        }
    }

    return 0;
}