// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// void swap(int& a, int& b){
//     int temp=a;
//     a=b;
//     b=temp;
// }
int maximum(int arr[], int e,int s){
    int maxi=INT_MIN;
    for(int i=s; i<e; i++){
        if(arr[i]>maxi){
           maxi=arr[i]; 
        }
    }
    return maxi;
}

int minimum(int arr[], int e, int s){
    int mini=INT_MAX;
    for(int i=s; i<e; i++){
        if(arr[i]<mini){
           mini=arr[i]; 
        }
    }
    return mini;
}
void rearrange(int* arr,int size){
    int s=0,e=size;
    int temp[size];
   for(int i=0; i<size; i++){
       if(i%2==0){
       temp[i]=maximum(arr,e,s);
       e=e-1;
       }
       else{
           temp[i]=minimum(arr,e,s);
           s=s+1;
       }    
    
   }
   
   for(int i=0; i<7; i++){
    cout<<temp[i]<<" "<<endl;
}
}
int main() {
  
// int a,b;
// cin>>a>>b;
// swap(a,b);
// cout<<"The value of a is "<<a<<" and the value of b is "<<b;
int arr[]={2,3,4,5,6,7,8};
rearrange(arr,7);

    return 0;
}