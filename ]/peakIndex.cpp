#include <iostream>
using namespace std;

int PeakIndex(int *arr, int s, int e)
{

    int mid = s + (e - s) / 2;
    if (s == e)
    {
        return s;
    }

    if (arr[mid] < arr[mid + 1])
    {
        return PeakIndex(arr, mid + 1, e);
    }
    else
    {
        return PeakIndex(arr, s, mid);
    }
}

int main()
{
int arr[]={-1,3,5,2,0,-3};
cout<<"Peak element is at the index "<<PeakIndex(arr,0,5)<<endl;
    return 0;
}