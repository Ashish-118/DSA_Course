class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        int size = m + n;
        int idx1 = size / 2;
        int idx2 = size / 2 - 1;

        int element1 = -1;
        int element2 = -1;

        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                if (k == idx1)
                    element1 = nums1[i];
                else if (k == idx2)
                    element2 = nums1[i];

                i++;
            }
            else
            {
                if (k == idx1)
                    element1 = nums2[j];
                else if (k == idx2)
                    element2 = nums2[j];

                j++;
            }
            k++;
        }

        while (i < m)
        {

            if (k == idx1)
                element1 = nums1[i];
            else if (k == idx2)
                element2 = nums1[i];

            i++;
            k++;
        }

        while (j < n)
        {
            if (k == idx1)
                element1 = nums2[j];
            else if (k == idx2)
                element2 = nums2[j];

            j++;
            k++;
        }

        if (size & 1)
            return element1;
        else
            return (element1 + element2) / 2.0;
    }
}; // time complexity O(m + n), space complexity O(1)

// using binary search

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;
        while (low <= high)
        {

            int Px = low + (high - low) / 2; // the no of elements from nums1 in the left partition
            int Py = (m + n + 1) / 2 - Px;   // the no of elements from nums2 in the left partition

            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];
            int x3 = (Px == m) ? INT_MAX : nums1[Px];

            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];

            if (x1 <= x4 && x2 <= x3)
            {
                if ((m + n) % 2 == 0)
                    return (max(x1, x2) + min(x3, x4)) / 2.0;

                return max(x1, x2);
            }
            else if (x1 > x4)
            {
                high = Px - 1;
            }
            else
            {
                low = Px + 1;
            }
        }

        return -1;
    }
};