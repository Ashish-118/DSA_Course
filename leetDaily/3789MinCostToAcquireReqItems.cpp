class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2)
    {

        if (cost1 + cost2 <= costBoth)
        {
            long long ans1 = 1LL * need1 * cost1 + 1LL * need2 * cost2;

            return ans1;
        }
        else
        {
            int mini = min(need1, need2);

            long long newAns = 1LL * max(need1, need2) * costBoth;

            if ((need1 - mini) != 0 && cost1 <= costBoth)
            {

                newAns = newAns - 1LL * (need1 - mini) * costBoth +
                         1LL * (need1 - mini) * cost1;
            }
            else if ((need2 - mini) != 0 && cost2 <= costBoth)
            {

                newAns = newAns - 1LL * (need2 - mini) * costBoth +
                         1LL * (need2 - mini) * cost2;
            }

            return newAns;
        }

        return 0;
    }
};