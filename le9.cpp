#include<iostream>
using namespace std;

// void arraydisplay(int data[],int size){
// for (int i = 0; i<size; i++)
// {
// cout<<data[i]<<endl;
// }
// }



int Max(int data[], int size){
int maxi=data[0];

for (int i = 0; i < size; i++)
{

    // if (max<data[i])
    // {
    //     max=data[i];
    // }

    // or
     maxi=max(maxi, data[i]);
    
}
return maxi;
}

int Min(int data[], int size){
int mini=data[0];

for (int i = 0; i < size; i++)
{
    // if (min>data[i])
    // {
    //     min=data[i];
    // }i
    mini=min(mini,data[i]);
}
return mini;
}


void reverse(int data[], int size){
// for (int i = 0; i < size/2; i++)
// {
//     int copy=data[i];
//     data[i]=data[size-1-i];
//     data[size-1-i]=copy;
//     // cout<<data[i]<<endl;
//     }

//     for (int i = 0; i < size; i++)
//     {
//     cout<<data[i]<<endl;
        
//     }
    

    //better version

    int start=0;
    int end=size-1;

    while (start<=end)
    {
        swap(data[start], data[end]);
        start++;
        end--;
    }
    
    for (int i = 0; i < size; i++)
    {
    cout<<data[i]<<endl;
        
    }


}




int main(){

int arr[]={2,4,32,5,6};

// int size=(sizeof(arr)/sizeof(int));
// cout<<(sizeof(arr)/sizeof(int));  // use it for the size of the array
 
// arraydisplay(arr,size);



// int size;
// cout<<"size: "<<endl;
// cin>>size;
// int store[100];

// for (int i = 0; i < size; i++)
// {
//     cin>>store[i];
// }


// cout<<"Maximum value is "<<Max(store,size)<<" and the minimum value is "<<Min(store,size)<<endl;


reverse(arr, 5);

 return 0;
}