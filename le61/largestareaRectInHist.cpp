class Solution
{
    vector<int> nextsmaller(vector<int> arr, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for (int i = n - 1; i >= 0; i--)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevsmaller(vector<int> arr, int n)
    {
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for (int i = 0; i < n; i++)
        {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }

            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> next(n);
        next = nextsmaller(heights, n);
        vector<int> prev(n);
        prev = prevsmaller(heights, n);
        int max_area = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];
            if (next[i] == -1)
            {
                next[i] = n;
            }
            int w = next[i] - prev[i] - 1;
            int area = l * w;
            max_area = max(max_area, area);
        }

        return max_area;
    }
};