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

    int char_val = s[index] - 'A';
    vector<int>::iterator it;
    it = find(info.begin(), info.end(), char_val);
    int index_of_char = distance(info.begin(), it);

    if ((char_val == 17 || char_val == 11)) // R / L
    {
        if (0 <= (x + info[index_of_char + 1]) && (x + info[index_of_char + 1]) <= w)
        {
            index++;
            x = x + info[index_of_char + 1];
            check = true;
        }
        else
        {
            changeR_L(s);
            check = false;
        }
    }
    else
    {
        if (0 <= (y + info[index_of_char + 1]) && (y + info[index_of_char + 1]) <= h)
        {
            index++;
            y = y + info[index_of_char + 1];
            check = true;
        }
        else
        {
            changeU_D(s);
            check = false;
        }
    }
    controller(count, s, info, index, x, y, w, h, k, check);
}
int main()
{
    vector<int> info = {17, 1, 11, -1, 20, 1, 3, -1};
    int t;
    cin >> t;

    while (t--)
    {
        int n, w, h;
        int64_t k;
        cin >> n >> k >> w >> h;
        string s;
        cin >> s;
        int count = 0;
        controller(count, s, info, 0, 0, 0, w, h, k);
        cout << count << endl;
    }

    return 0;
}