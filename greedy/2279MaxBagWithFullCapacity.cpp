class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        priority_queue<int, vector<int>, greater<int>> mini;

        for (int i = 0; i < capacity.size(); i++)
        {
            mini.push(capacity[i] - rocks[i]);
        }
        int count = 0;

        while (!mini.empty())
        {
            int top = mini.top();
            mini.pop();

            if (top > additionalRocks)
                break;

            additionalRocks -= top;
            count++;
        }

        return count;
    }
};