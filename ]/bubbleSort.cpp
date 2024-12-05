#include <iostream>
using namespace std;

//NOTE-> s=length of array
void BubbleSort(int arr[], int i, int lengthOfarray, bool swapped)
{
    if (lengthOfarray == 1)
    {
        return ;
    }
    if (i == lengthOfarray-1)
    {
        if (swapped)
        {
            return BubbleSort(arr, 0, lengthOfarray - 1, false);
        }
        else
        {
            return ;
        }
    }
    else
    {
        if (arr[i] > arr[i + 1])
        {
            swapped = true;
            swap(arr[i], arr[i + 1]);
        }
    }
    return BubbleSort(arr, i + 1, lengthOfarray, swapped);
}

// or

void BubbleSort(int *arr, int n)
{
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            swap(arr[i], arr[i + 1]);
        }
    }
    BubbleSort(arr, n - 1);
}

int main()
{
    // method 1
    int arr[] = {4, 8, 3, 1, -1, 7};
       BubbleSort(arr,0,6,false);

    // int arr[] = {1,8,9,11,12};
    // BubbleSort(arr,0,5,false);

    // method 2
    // BubbleSort(arr, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}