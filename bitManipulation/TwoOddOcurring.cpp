class Solution
{
public:
    vector<int> twoOddNum(vector<int> &arr)
    {
        // code here

        int xor1 = 0;
        for (auto &x : arr)
            xor1 ^= x;

        int leftShift = 0;
        for (int i = 0; i <= 31; i++)
        {
            if (xor1 & (1 << i))
            {
                leftShift = i;
                break;
            }
        }

        int group1 = 0;
        int group0 = 0;

        for (auto &x : arr)
        {
            if (x & (1 << leftShift))
                group1 ^= x;
            else
                group0 ^= x;
        }

        int maxi = max(group1, group0);
        int mini = min(group1, group0);
        return {maxi, mini};
    }
};