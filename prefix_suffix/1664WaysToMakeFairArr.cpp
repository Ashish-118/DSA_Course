class Solution
{
public:
    int waysToMakeFair(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> suffixEvenSum(n, 0);
        vector<int> suffixOddSum(n, 0);
        int oddSum = 0, evenSum = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            suffixEvenSum[i] = evenSum;
            suffixOddSum[i] = oddSum;

            if (i & 1)
            {
                oddSum += nums[i];
            }
            else
            {
                evenSum += nums[i];
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            int suffixEven = suffixEvenSum[i];
            int suffixOdd = suffixOddSum[i];
            int currEven = 0, currOdd = 0;
            if (i & 1)
            {
                currEven = evenSum - suffixEven + suffixOdd;
                currOdd = oddSum - nums[i] - suffixOdd + suffixEven;
            }
            else
            {
                currEven = evenSum - nums[i] - suffixEven + suffixOdd;
                currOdd = oddSum - suffixOdd + suffixEven;
            }

            if (currEven == currOdd)
                count++;
        }

        return count;
    }
};