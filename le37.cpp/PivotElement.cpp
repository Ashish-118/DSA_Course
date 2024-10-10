#include<iostream>
using namespace std;

// this is the code to find the pivot element in the rotated array like 7,9,1,2,3   //  here the pivot is the least i.e = 1
int pivot(int *arr,int s, int e){
int mid=s+(e-s)/2;
if (s==(e-1))
{
    return e;
}
if (arr[mid]>=arr[0])
{
    return pivot(arr,mid,e);
}
else{
    return pivot(arr,s,mid);
}
}

int main(){
// int arr[]={9,1,2,3,4,6,7,8};
int arr[]={8,10,17,1,3};
cout<<"Pivot element is at the index "<<pivot(arr,0,4)<<endl;
return 0;
}