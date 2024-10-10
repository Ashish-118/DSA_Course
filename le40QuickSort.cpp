#include <iostream>
using namespace std;

int partition(int *arr, int s, int e)
{
    int count = 0;
    int pivot = arr[s];
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[s], arr[count + s]);

    // left and right part ko sambalthe hein

    int start = s, end = e;
    // god's  gave method

    while (start != end)
    {
        if (arr[start] > pivot && arr[end] <= pivot)
        {
            swap(arr[start++], arr[end--]);
        }
        else
        {
            if (arr[start] <= pivot && start != pivotIndex)
            {
                start++;
            }
            if (arr[end] > pivot)
            {
                end--;
            }
        }
    }

    //  babbar method

    // while (start < pivotIndex && end > pivotIndex)
    // {
    //     while (arr[start] < pivot)
    //     {
    //         start++;
    //     }
    //     while (arr[end] > pivot)
    //     {
    //         end--;
    //     }

    //     if (start < pivotIndex && pivotIndex>end)
    //     {
    //         swap(arr[start++], arr[end--]);
    //     }
    // }

    return pivotIndex;
}
void QuickSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // left pat sort karo
    QuickSort(arr, s, p - 1);

    // right part sort karo
    QuickSort(arr, p + 1, e);
}

int main()
{
    // int arr[] = {2, 4, 1,2, 6, 9,-1,2,7};
    // int n = 9;
    int arr[] = {4, 2, 5, 1, 3};
    int n = 5;
    QuickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}