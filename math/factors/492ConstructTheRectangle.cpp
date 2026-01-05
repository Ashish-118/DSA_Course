class Solution
{
public:
    vector<int> constructRectangle(int area)
    {

        int l = 0, w = 0;
        int diff = INT_MAX;

        for (int i = 1; i * i <= area; i++)
        {
            if (area % i == 0)
            {
                int secondDivisor = area / i;
                if (abs(i - secondDivisor) < diff)
                {
                    diff = abs(i - secondDivisor);
                    l = max(i, secondDivisor);
                    w = min(i, secondDivisor);
                }
            }
        }

        return {l, w};
    }
};