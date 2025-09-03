class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // code here
        vector<int> ans;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (a[i] < b[j])
            {
                ans.push_back(a[i]);
                i++;

                while (i < n && a[i - 1] == a[i])
                {
                    i++;
                }
            }

            else if (a[i] == b[j])
            {
                ans.push_back(b[j]);
                i++;
                j++;

                while (i < n && a[i - 1] == a[i])
                {
                    i++;
                }

                while (j < m && b[j - 1] == b[j])
                {
                    j++;
                }
            }
            else
            {
                ans.push_back(b[j]);
                j++;
                while (j < m && b[j - 1] == b[j])
                {
                    j++;
                }
            }
        }

        while (i < n)
        {
            ans.push_back(a[i]);
            i++;

            while (i < n && a[i - 1] == a[i])
            {
                i++;
            }
        }

        while (j < m)
        {
            ans.push_back(b[j]);
            j++;
            while (j < m && b[j - 1] == b[j])
            {
                j++;
            }
        }

        return ans;
    }
};