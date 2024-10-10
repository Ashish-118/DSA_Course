#include <iostream>
using namespace std;

// void alternate(int data[], int size){
// //     int start=0;
// //     int end=1;
// // for (int i = 0; i < size/2; i++)
// // {
// //    swap(data[start], data[end]);
// //    start=start+2;
// //    end=end+2;
// // }

// for (int i = 0; i < size; i+=2)
// {
//    if(i+1<size){
//     swap(data[i],data[i+1]);
//    }
// }

// }

void display(int data[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << data[i] << " ";
  }
}

int findUnique(int* arr, int size){
// for (int i = 0; i < size; i++)
// {
    // int check=0;
    // for (int j = 0; j < size; j++)
    // {
    //     if (*(arr+i)==*(arr+j))
    //     {
    //         check++;
    //     }

    // }

    // if (check==1)
    // {
    //     return *(arr+i);

    // }

// }
    int ans=0;
    for (int i = 0; i < size; i++)
    { 
       ans=ans^arr[i];
       cout<<ans<<endl;
    }
    return ans;


}

// void occurUnique(int data[], int size){
// int occurences[100]={0};
// int item[100]={0};
// int ans=0;
// for (int i = 0; i < size; i++)
// {
// int count=0;
//     for (int j = 0; j < size; j++)
//     {
//         if (data[i]==data[j])
//         {
//             count++;

//         }

//     }
//     occurences[i]=count;
// }
// // cout<<(sizeof(occurences)/sizeof(int))<<endl;
// display(occurences,(sizeof(occurences)/sizeof(int)));
// for (int i = 0; i < (sizeof(occurences)/sizeof(int)); i++)
// {
//     ans=ans^occurences[i];
//     if (i!=0)
//     {
//         if (ans==0)
//         {
//            cout<<"False"<<endl;
//            break;
//         }

//     }

// }

// }

// int findDuplicate(int data[], int size){
// int ans=0;
// int value;
// for (int i = 0; i < size; i++)
// {
//   ans=ans^data[i];
//   if (i!=0)
//   {
//     if (ans==0)
//     {
//      value=data[i];
//      break;
//     }

//   }

// }
// return value;
// }

// int findDuplicate(int data[], int size)
// { 
//     int ans = 0;
//     for (int i = 0; i < size; i++)
//     {
//         ans = ans ^ data[i];
//          cout << "xor of ans and data i " << ans << endl;
//     }

//     // return ans;
//     cout << ans << endl
//          << endl;
//     for (int i = 1; i < size; i++)
//     {
//         cout << ans << endl;
//         ans = ans ^ i;
//         cout << "xor of ans and data i " << ans << endl;
//     }
//     // return ans;
// }

void Findintersection(int data1[], int s1, int data2[], int s2)
{
  int same[100];
  int sameindex = 0;

  // for (int i = 0; i < s1; i++)
  // {
  //     for (int j = 0; j < s2; j++)
  //     {
  //         if (data1[i]>=data2[j])
  //         {

  //         if (data1[i] == data2[j])
  //         {
  //             same[sameindex] = data2[j];
  //             data2[j] = INT_MIN;
  //             sameindex++;
  //             break;
  //         }
  //         }

  //         else
  //         {
  //             break;
  //         }

  //     }
  // }

  int i = 0;
  int j = 0;
  while (i < s1 && j < s2)
  {
    if (data1[i] == data2[j])
    {
      same[sameindex] = data1[i];
      sameindex++;
      i++;
      j++;
    }
    else if (data1[i] < data2[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  display(same, sameindex);
}

void separate01(int data[], int size)
{
  int i = 0;
  int j = size - 1;

  while (i < j)
  {
    if (data[i] == 1 && data[j] == 0)
    {
      swap(data[i], data[j]);
    i++;
    j--;
    }

    else if (data[i]==data[j])
    {
      j--;
    }
    else{
      i++;
      j--;
    }
    
  }

  display(data, size);
}

int main()
{

  // int arr[]={1,-3,65,23,2,3,7};
  // int size=7;

  // alternate(arr,size);
  // display(arr,size);

  // int arr[]={2,4,5,4,9,5,2};
  int size = 5;
  // cout<<findUnique(arr,size)<<endl;

  // cout<<(4^1)<<endl;

  int arr[] = {1, 2, 3, 4, 3};
  // occurUnique(arr,size);

  cout<<findDuplicate(arr,size)<<endl;

  // find Intersection of two arrays
  // int arr[10]={22,3,4,23,1,6};
  // cout<<(arr>>1);

  // int data1[]={1,3,6,6,11};
  // int data2[]={3,6,10,23};
  int data1[] = {-13, -11, -2, -1, 0, 6, 11};
  int data2[] = {-12, -11, -2, 0, 6, 6, 10, 23};
  // int data2[]={4,8,9,10};
  int s1 = 7;
  int s2 = 8;
  // Findintersection(data1,s1,data2,s2);

  // separate 0 and 1
  // int a1[] = {1,1,0,0,1,0,1,0};
  int a1[] = {1,1,0,1,1,0,1,0};
  int s3 = 8;
  // separate01(a1, s3);
  return 0;
}