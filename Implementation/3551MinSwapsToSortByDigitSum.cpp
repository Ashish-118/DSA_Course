class Solution
{
public:
    using pp = pair<int, int>;
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<pp> v;

        auto digitSum = [&](int a)
        {
            int sum = 0;
            while (a > 0)
            {
                int d = a % 10;
                sum += d;

                a /= 10;
            }

            return sum;
        };

        for (auto x : nums)
        {
            v.push_back({digitSum(x), x});
        }

        vector<pp> temp = v;
        sort(begin(temp), end(temp));
        map<pp, set<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[temp[i]].insert(i);
        }

        int count = 0;

        vector<bool> checked(n, false);

        for (int i = 0; i < n; i++)
        {
            if (checked[i])
                continue;
            int orgIdx = *mp[v[i]].begin();
            mp[v[i]].erase(orgIdx);

            if (orgIdx == i)
            {
                checked[i] = true;
                continue;
            }

            count++;
            checked[orgIdx] = true;
            swap(v[i], v[orgIdx]);
            i--;
        }

        return count;
    }
};