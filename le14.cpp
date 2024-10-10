#include <iostream>
using namespace std;

int pivot(int data[], int size)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (data[mid] >= data[0])
        {

            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}

int searchInRotatedArray(int data[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (data[mid] >= data[0])
        {

            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }

    if (data[s] <= key && key <= data[size - 1])
    {
        int start = s, end = size - 1;
        int m = start + (end - start) / 2;
        while (start <= end)
        {
            if (data[m] == key)
            {
                return m;
            }
            // go to right wala part
            if (key > data[m])
            {
                start = m + 1;
            }
            else
            {
                // key < arr Imid]
                end = m - 1;
            }
            m = start + (end - start) / 2;
        }
        return -1;
    }
    else
    {
        int start = 0, end = s - 1;
        int m = start + (end - start) / 2;
        while (start <= end)
        {
            if (data[m] == key)
            {
                return m;
            }
            // go to right wala part
            if (key > data[m])
            {
                start = m + 1;
            }
            else
            {
                // key < arr Imid]
                end = m - 1;
            }
            m = start + (end - start) / 2;
        }
        return -1;
    }
}

long long int sqrt(int value)
{
    long long int s = 0, e = value - 1;
    long long int mid = s + (e - s) / 2;
    long long int ans = -1;
    while (s <= e)
    {
        if ((mid * mid) == value)
        {
            return mid;
        }
        else if ((mid * mid) > value)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            ans = mid;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

double more_precision(int n, int precision, int tempSolution)
{
    double factor = 1;
    double ans = tempSolution;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}
int main()
{

    int size = 6;
    int arr[] = {7, 6, 9, 1, 2, 3};
    // cout << pivot(arr, size) << endl;

    int key = 27;

    // cout<<"the searched element is in the index "<<searchInRotatedArray(arr,size,key)<<endl;
    // cout << "the square root is " << sqrt(1000000) << endl;

    int n;
    cout << "Enter the number " << endl;
    cin >> n;
    int temp=sqrt(n);
cout<<"The precised value of the square of the given number is "<<more_precision(n,3,temp)<<endl;
    return 0;
}