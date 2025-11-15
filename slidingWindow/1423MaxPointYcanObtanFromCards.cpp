class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int sum = 0;
        int maxi = 0;
        int len = cardPoints.size();
        for (int i = 0; i < k; i++)
        {
            sum += cardPoints[i];
            maxi = sum;
        }
        int l = k - 1;
        int r = len - 1;
        while (k--)
        {
            int n = sum - cardPoints[l] + cardPoints[r];

            maxi = max(maxi, n);
            sum = n;

            l--;
            r--;
        }

        return maxi;
    }
};