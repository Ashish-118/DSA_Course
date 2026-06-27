class Solution
{
public:
    int maximumLength(vector<int> &nums)
    {
        sort(begin(nums), end(nums));
        map<int, int> mp;
        map<int, bool> uniqueElements;
        for (auto x : nums)
        {
            mp[x]++;
            if (uniqueElements.count(x) == 0)
            {
                uniqueElements[x] = false;
            }
        }

        int result = 1;
        result = max(result, mp[1] & 1 ? mp[1] : mp[1] - 1);

        for (auto u : uniqueElements)
        {
            if (!u.second && u.first != 1)
            {
                int ans = 0;
                int temp = u.first;
                uniqueElements[temp] = true;

                while (temp * 1LL * temp <= 1e9 && uniqueElements.count(temp * temp) && mp[temp] >= 2)
                {

                    ans += 2;
                    temp = temp * temp;
                    uniqueElements[temp] = true;
                }

                ans += 1;

                result = max(result, ans);
            }
        }

        return result;
    }
};