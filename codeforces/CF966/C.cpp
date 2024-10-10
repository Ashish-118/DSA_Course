#include <bits/stdc++.h>
using namespace std;

bool check(string s, vector<int> &arr)
{
    int sLen = s.size();
    int len = arr.size();
    if (len != sLen)
    {
        return false;
    }
    map<int, char> intToChar;
    map<char, int> charToInt;
    for (int i = 0; i < len; i++)
    {
        if (intToChar.find(arr[i]) != intToChar.end() && intToChar[arr[i]] != s[i])
        {
            return false;
        }
        if (charToInt.find(s[i]) != charToInt.end() && charToInt[s[i]] != arr[i])
        {
            return false;
        }
        intToChar[arr[i]] = s[i];
        charToInt[s[i]] = arr[i];
    }
    return true;
}

int main()
{
    int noOfInputsLoops, n, m;
    string s;

    cin >> noOfInputsLoops;
    while (noOfInputsLoops--)
    {
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> m;
        while (m--)
        {
            cin >> s;
            bool output = check(s, arr);
            if (output)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}
