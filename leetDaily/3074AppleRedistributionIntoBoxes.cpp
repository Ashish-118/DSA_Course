class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int total = accumulate(begin(apple), end(apple), 0);

        sort(begin(capacity), end(capacity));

        int count = 0;
        for (int i = capacity.size() - 1; i >= 0 && total > 0; i--)
        {
            count++;
            total -= capacity[i];
        }

        return count;
    }
};