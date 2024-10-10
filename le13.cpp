#include <iostream>
using namespace std;

int first_occ(int data[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (data[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }

        else if (key > data[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int last_occ(int data[], int size, int key)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (data[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }

        else if (key > data[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int peakElement(int data[], int size)
{
    int s = 0, e = size - 1;
    int mid = s + (e - s) / 2;

    while (s <e)
    {
        if (data[mid] < data[mid + 1])
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

int main()
{
    // int even [5] = {1,2,3,3,5};
    // int f=first_occ(even, 5, 3);
    // int l=last_occ(even, 5, 3);
    // cout << " First Occurrence of 3 is at Index " << f<<endl;
    //  cout << " Last Occurrence of 3 is at Index " <<l <<endl;
    //  cout<<"No of occurences of3 is "<<(l-f)+1<<endl;

    int mountain[] = {3, 4, 6, 5, 2, 1};
    int size = 6;
    cout << peakElement(mountain, size);
    return 0;
}