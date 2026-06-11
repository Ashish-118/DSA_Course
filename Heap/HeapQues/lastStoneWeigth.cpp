class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int, vector<int>> pq;

        for (auto stone : stones)
            pq.push(stone);

        while (!pq.empty())
        {
            int n1 = pq.top();
            pq.pop();
            int n2 = 0;
            if (!pq.empty())
            {
                n2 = pq.top();
                pq.pop();
            }
            else
            {
                return n1;
            }

            pq.push(n1 - n2);
        }

        return 0;
    }
};