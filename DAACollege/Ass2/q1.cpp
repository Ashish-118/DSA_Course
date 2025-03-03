#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; j++)
    {
        if (arr[j] >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);
    return i + 1;
}
int quickSelect(vector<int> &arr, int left, int right, int k)
{
    if (left <= right)
    {
        int pivotIndex = partition(arr, left, right);
        if (pivotIndex == k - 1)
        {
            return arr[pivotIndex];
        }
        else if (pivotIndex > k - 1)
        {
            return quickSelect(arr, left, pivotIndex - 1, k);
        }
        else
        {
            return quickSelect(arr, pivotIndex + 1, right, k);
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {12, 3, 5, 7, 19, 26};
    int k = 3;
    int n = arr.size();
    int kthLargest = quickSelect(arr, 0, n - 1, k);
    cout << "The " << k << "rd largest element is: " << kthLargest << endl;
    return 0;
}
