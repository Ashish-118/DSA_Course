class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int num1 = 0, num2 = 0;

        for (auto x : nums)
        {
            if (x > num1)
            {
                num2 = num1;
                num1 = x;
            }
            else if (x > num2)
            {
                num2 = x;
            }
        }

        return (num1 - 1) * (num2 - 1);
    }
};