class Solution
{
public:
    vector<int> nsel(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    vector<int> nser(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int col = matrix[0].size();
        int row = matrix.size();
        vector<int> cumulativeHeight(col, 0);
        int maxArea = INT_MIN;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j] == '1')
                    cumulativeHeight[j]++;
                else
                    cumulativeHeight[j] = 0;
            }

            vector<int> nextSmallestFromLeft = nsel(cumulativeHeight);
            vector<int> nextSmallestFromRight = nser(cumulativeHeight);

            for (int j = 0; j < col; j++)
            {
                int l = nextSmallestFromLeft[j];
                int r = (nextSmallestFromRight[j] != -1 ? nextSmallestFromRight[j] : col);

                maxArea = max(maxArea, (abs((l + 1) - (r - 1)) + 1) * cumulativeHeight[j]);
            }
        }

        return maxArea;
    }
};