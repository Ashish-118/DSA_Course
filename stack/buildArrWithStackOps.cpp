class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ans;
        int index = 0;
        for (int i = 1; i <= n; i++)
        {
            if (target[index] == i)
            {
                ans.push_back("Push");
                index++;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if (index >= target.size())
                break;
        }

        return ans;
    }
};