class Solution
{
public:
    int requiredStudents(vector<int> &arr, int maxPages)
    {
        int students = 1, currentSum = 0;
        for (int pages : arr)
        {
            if (pages > maxPages)
                return INT_MAX; // Single book exceeds limit, impossible
            if (currentSum + pages > maxPages)
            {
                students++;
                currentSum = pages;
            }
            else
            {
                currentSum += pages;
            }
        }
        return students;
    }

    int findPages(vector<int> &arr, int k)
    {
        if (arr.size() < k)
            return -1;
        int left = *max_element(arr.begin(), arr.end());
        int right = accumulate(arr.begin(), arr.end(), 0);
        int answer = -1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int students = requiredStudents(arr, mid);
            if (students <= k)
            {
                answer = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return answer;
    }
};
