class Solution
{
public:
    unordered_set<string> result;

    void solve(int H, int M, int turnedOn, vector<int> &Hour,
               vector<int> &Minute)
    {
        if (turnedOn == 0)
        {
            string temp = "";
            temp += to_string(H);
            temp += ':';
            if (M < 10)
                temp += ("0" + to_string(M));
            else
                temp += to_string(M);

            if (result.find(temp) == result.end())
            {
                result.insert(temp);
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (!Hour[i])
            {
                if ((H + (1 << i)) > 11)
                    continue;
                Hour[i] = 1;
                solve(H + (1 << i), M, turnedOn - 1, Hour, Minute);
                Hour[i] = 0;
            }
        }

        for (int i = 0; i < 6; i++)
        {
            if (!Minute[i])
            {
                if ((M + (1 << i)) > 59)
                    continue;

                Minute[i] = 1;
                solve(H, M + (1 << i), turnedOn - 1, Hour, Minute);
                Minute[i] = 0;
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<int> hour(4, 0);
        vector<int> minute(6, 0);

        solve(0, 0, turnedOn, hour, minute);

        vector<string> ans;
        for (auto x : result)
        {
            ans.push_back(x);
        }
        return ans;
    }
};