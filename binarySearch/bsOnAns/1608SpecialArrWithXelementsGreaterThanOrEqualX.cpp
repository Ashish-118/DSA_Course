class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        int elements = n;
        map<int, int> mp;
        for (auto x : nums)
            mp[x]++;

        int x = 1;
        for (; x <= n; x++)
        {

            for (auto item : mp)
            {
                if (item.first < x)
                {
                    elements -= item.second;
                    mp.erase(item.first);
                }
                else
                    break;
            }

            if (elements == x)
                return x;
        }

        return -1;
    }
};

///

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();

        sort(begin(nums), end(nums));

        auto poss = [&](int x)
        {
            int count = lower_bound(begin(nums), end(nums), x) - begin(nums);
            return n - count;
        };

        int s = 0, e = n;

        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int ret = poss(mid);
            if (ret == mid)
            {
                return mid;
            }
            else if (ret > mid)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return -1;
    }
};

////

// O(n)

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(*max_element(begin(nums), end(nums)) + 1, 0);

        for (auto val : nums)
            arr[val]++;

        int pointer = 0;
        int Elements = n;

        for (int x = 1; x <= n; x++)
        {

            while (pointer < arr.size() && (arr[pointer] == 0 || pointer < x))
            {
                Elements -= arr[pointer];
                pointer++;
            }

            if (Elements == x)
                return x;
        }

        return -1;
    }
};