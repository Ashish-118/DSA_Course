class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        int right = height.size() - 1;
        int leftMax = height[left];
        int rightMax = height[right];
        int water = 0;

        while (left < right)
        {
            if (leftMax < rightMax)
            {
                left++;
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
            }
            else
            {
                right--;
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
            }
        }

        return water;
    }
};

// another way

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int maxi = *max_element(begin(height), end(height));
        int n = height.size();
        long long totalArea = maxi * n;

        int prev = height[0];
        int curr = -1;
        totalArea -= height[0];

        for (int i = 1; i < n; i++)
        {
            curr = height[i];
            totalArea -= height[i];

            if (prev < curr)
            {
                totalArea -= (1LL * i * (curr - prev));
                prev = curr;
            }
        }

        curr = -1;
        prev = height[n - 1];

        for (int i = n - 2; i >= 0; i--)
        {
            curr = height[i];

            if (prev < curr)
            {
                totalArea -= (1LL * (n - 1 - i) * (curr - prev));
                prev = curr;
            }
        }

        return totalArea;
    }
};