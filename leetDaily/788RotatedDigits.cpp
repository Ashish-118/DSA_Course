class Solution
{
public:
    int rotatedDigits(int n)
    {
        unordered_map<char, char> mp;

        mp['0'] = '0';
        mp['1'] = '1';
        mp['2'] = '5';
        mp['5'] = '2';
        mp['6'] = '9';
        mp['8'] = '8';
        mp['9'] = '6';

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            string str = to_string(i);
            string newStr = "";

            bool check = true;

            for (auto x : str)
            {
                if (mp.count(x) == 0)
                {
                    check = false;
                    break;
                }
                newStr += mp[x];
            }

            if (check && newStr != str)
            {

                ans++;
            }
        }

        return ans;
    }
};