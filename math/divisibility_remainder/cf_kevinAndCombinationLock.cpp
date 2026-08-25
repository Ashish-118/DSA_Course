#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int x;
    cin >> x;

    string ans = "NO";
    queue<string> q;

    string num = to_string(x);
    q.push(num);

    while (!q.empty())
    {
        string front = q.front();
        q.pop();

        if (stoi(front) % 33 == 0)
        {
            ans = "YES";
            break;
        }
        else if (stoi(front) < 33)
        {
            break;
        }

        vector<int> v;
        int put = -1;
        int count = 0;

        for (int i = 0; i < front.length(); i++)
        {
            if (front[i] == '3')
            {
                count++;
            }
            else
            {
                count = 0;
                put = -1;
            }

            if (count == 2)
            {
                put = i - 1;
                v.push_back(put);
            }
        }

        for (auto it : v)
        {
            string temp = front;
            int idx = it;
            temp[idx] = '-';
            temp[idx + 1] = '-';
            int pos = temp.find("--");
            if (pos != string::npos)
            {
                temp.erase(pos, 2);
            }

            q.push(temp);
        }
    }

    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}