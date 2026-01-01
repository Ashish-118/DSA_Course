class Solution
{
public:
    long long minMoves(vector<int> &balance)
    {
        int n = balance.size();

        int culpritIndex = -1;
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += balance[i];
            if (balance[i] < 0)
            {
                culpritIndex = i;
            }
        }

        if (culpritIndex == -1)
            return 0;

        if (sum < 0)
            return -1;

        long long moves = 0;
        int dist = 1;

        while (balance[culpritIndex] < 0)
        {
            int right = (culpritIndex + dist) % n;
            int left = (culpritIndex - dist + n) % n;

            long long available = balance[left] + balance[right];
            if (left == right)
                available -= balance[right];

            long long needed = -balance[culpritIndex];
            long long taken = min(needed, available);

            moves += taken * dist;
            balance[culpritIndex] += taken;

            dist++;
        }

        return moves;
    }
};
