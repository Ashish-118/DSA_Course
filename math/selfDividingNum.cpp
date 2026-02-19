class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;

        for (int i = left; i <= right; i++)
        {
            int x = i;
            bool check = true;

            while (x != 0)
            {
                int last = x % 10;

                if (last == 0 || i % last != 0)
                {

                    check = false;
                    break;
                }
                x = x / 10;
            }

            if (check)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};