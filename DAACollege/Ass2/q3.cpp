#include <bits/stdc++.h>
using namespace std;

void maxSubarraySum(vector<int> &A)
{
    int n = A.size();
    int maxSum = INT_MIN, currentSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; i++)
    {
        if (currentSum < 0)
        {
            currentSum = A[i];
            tempStart = i;
        }
        else
        {
            currentSum += A[i];
        }

        if (currentSum > maxSum)
        {
            maxSum = currentSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Subarray with largest sum: ";
    for (int i = start; i <= end; i++)
    {
        cout << A[i] << " ";
    }
    cout << "\nLargest sum: " << maxSum << endl;
}

int main()
{
    vector<int> A = {1, -2, 5, 7, -3, 9, -11, 5, 3, -4, 2};
    maxSubarraySum(A);
    return 0;
}
