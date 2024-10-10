#include <iostream>
using namespace std;

// bool isSorted(int *arr, int size){

// if (size==0 || size==1)
// {
//     return true;
// }
// if (arr[0]>arr[1])
// {
//   return false;
// }
// else{
//     bool remaining_part=isSorted(arr+1,size-1);
//     return remaining_part;
// }

// bool linearSearchByRecurr(int *arr, int size, int k){
// if(size==0){
//     return false;
// }
// if (arr[0]==k)
// {
//     return true;
// }
// else{
//     return linearSearchByRecurr(arr+1,size-1,k);
// }

// }

bool binarySearch(int *arr, int s, int e, int k)
{
    
    int mid = s + (e-s) / 2;
   
    if (s > e)
    {
        return false;
    }
    if (arr[mid] == k)
    {
        return true;
    }
    else if (arr[mid] < k){
        return binarySearch(arr, mid + 1, e, k);
    }
    else
    {
        return binarySearch(arr, s, mid - 1, k);
    }
}
int main()
{
    ////////////////////Q1
    // int arr[5] = {1,2,4,9,9};
    // int size = 5;

    // if (isSorted(arr,size))
    // {
    //     cout<<"Sorted"<<endl;
    // }
    // else
    // {
    //     cout<<"not Sorted"<<endl;
    // }

    ////////////////////Q2
    // int arr[5] = {8,5,4,2,9};
    // int size = 5;
    // int k=2;

    // if (linearSearchByRecurr(arr,size,k))
    // {
    //     cout<<"found"<<endl;
    // }
    // else
    // {
    //     cout<<"not found"<<endl;
    // }

    ////////////////////Q3
    int arr[5] = {3, 5, 12, 16, 19};
    int start = 0, end = 4;
    int k = 16;

    if (binarySearch(arr, start, end, k))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }

    return 0;
}