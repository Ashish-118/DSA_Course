class Solution
{
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;

        for (int i = 0; i < arr.size(); i++)
        {
            for (auto &x : prev)
            {
                curr.insert(arr[i] | x);
                result.insert(arr[i] | x);
            }
            curr.insert(arr[i]);
            result.insert(arr[i]);
            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};