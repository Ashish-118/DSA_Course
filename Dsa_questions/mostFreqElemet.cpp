class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k)
    {
        int maxFreq = 1;
        int frequentNum = 0;
        int len = nums.size();
        sort(nums.begin(), nums.end(), std::greater<int>());
        vector<int> diff;
        for (int i = 0; i < (len - 1); i++)
        {
            diff.push_back((nums[i] - nums[i + 1]));
        }
        for (int i = 0; i < diff.size(); i++)
        {
            int x = k;
            int freq = 1;
            int sum = 0;
            cout << diff[i] << endl;

            for (int j = i; j < diff.size(); j++)
            {
                sum = sum + diff[j];

                if (sum <= x)
                {
                    x = x - sum;
                    freq++;
                    if (freq > maxFreq)
                    {
                        maxFreq = freq;
                        frequentNum = nums[i];
                    }
                }
                else
                {

                    break;
                }
            }
        }
        return maxFreq;
    }
};