#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void changeR_L(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
        {
            s[i] = 'L';
        }
        else if (s[i] == 'L')
        {
            s[i] = 'R';
        }
    }
    // cout<<"called_RL. "<<s<<endl;
}

void changeU_D(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'U')
        {
            s[i] = 'D';
        }
        else if (s[i] == 'D')
        {
            s[i] = 'U';
        }
    }

    // cout<<"called_UD. "<<s<<endl;
}

void controller(int &count, string s, vector<int> info, int index, int x, int y, int w, int h, int k, bool check = true)
{

    if ((x == 0 && y == 0) && index != 0 && check)
    {
        count++;
    }
    if (index == s.length())
    {
        index = 0;
        k--;
    }
    if (k == 0)
    {

        return;
    }

    // cout<<" index "<<index<<" k "<<k<<" count "<<count<<" x "<<x<<" y "<<y<<endl;

    int char_val = s[index] - 'A';
    vector<int>::iterator it;
    it = find(info.begin(), info.end(), char_val);
    int index_of_char = distance(info.begin(), it);

    if ((char_val == 17 || char_val == 11)) // R / L
    {
        if (0 <= (x + info[index_of_char + 1]) && (x + info[index_of_char + 1]) <= w)
        {
            controller(count, s, info, index + 1, x + info[index_of_char + 1], y, w, h, k, true);
        }
        else
        {
            changeR_L(s);
            controller(count, s, info, index, x, y, w, h, k, false);
        }
    }
    else
    {
        if (0 <= (y + info[index_of_char + 1]) && (y + info[index_of_char + 1]) <= h)
        {
            controller(count, s, info, index + 1, x + info[index_of_char + 1], y, w, h, k, true);
        }
        else
        {
            changeU_D(s);
            controller(count, s, info, index, x, y, w, h, k, false);
        }
    }
}
int main()
{

    vector<int> info = {17, 1, 11, -1, 20, 1, 3, -1};
    int t;
    cin >> t;
    if (1 <= t && t <= 10000)
    {
        for (int i = 0; i < t; i++)
        {

            int n, k, w, h;
            cin >> n >> k >> w >> h;
            if ((1 <= n && n <= 100000) && (1 <= h && h <= 100000) && (1 <= w && w <= 100000) && (1 <= k && k <= n))
            {
                string s;
                cin >> s;
                int count = 0;
                controller(count, s, info, 0, 0, 0, w, h, k);
                cout << count << endl;
            }
        }
    }

    return 0;
}