#include <iostream>
#include <vector>
using namespace std;



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> user;
        int u;
        for (int i = 0; i < n; i++)
        {

            cin >> u;
            user.push_back(u);
        }

        bool check = true;

        vector<bool> seats(n, false);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                seats[user[i] - 1] = true;
            }
            else
            {
                if ((user[i] - 1) == 0)
                {
                    if (seats[user[i] - 1 + 1] == 1)
                    {
                        seats[user[i] - 1] = true;
                    }
                    else
                    {
                        break;
                    }
                }

                else if ((user[i] ) == n)
                {
                    if (seats[user[i] - 1 - 1] == 1)
                    {
                        seats[user[i] - 1] = true;
                    }
                    else
                    {
                        break;
                    }
                }
                else{
                    if (seats[user[i] - 1 - 1] == 1 || seats[user[i] - 1 + 1] == 1)
                    {
                        seats[user[i] - 1] = true;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        for (auto x : seats)
        {
            if (x == 0)
            {
                check = false;
                break;
            }
        }
        if (check)
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