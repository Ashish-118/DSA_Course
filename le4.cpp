#include <iostream>
using namespace std;

int main()
{
  int n;
  cout << "Enter the value of n " << endl;
  cin >> n;
  // for (int i = 1; i <=n; i++)
  // {
  // for (int j = 0; j<n; j++)
  // {
  //     cout<<n-j<<" ";
  //     // cout<<j<<" ";
  // }
  // cout<<endl;

  // }

  // for (int i = 0; i < n; i++)
  // {
  //    for (int j = 1; j <=n; j++)
  //    {
  //     cout<<j+(n*i)<<" ";
  //    }
  //    cout<<endl;
  // }

  // for (int i = 1; i <=n; i++)
  // {
  //     for (int j = 0; j < i; j++)
  //     {
  //         cout<<i<<" ";
  //     }
  //     cout<<endl;
  // }

  // int count=1;
  //     for (int i = 1; i <= n; i++)
  //     {
  //         for (int j = 0; j < i; j++)
  //         {
  //             cout<<count<<' ';
  //             count++;
  //         }
  //         cout << endl;
  //     }

  // for (int i = 1; i <= n; i++)
  // {

  //    for (int j = 0; j < i; j++)
  //    {
  //     // cout<<j+i<<' ';
  //     cout<<char(64+j+i)<<' ';
  //    }
  //    cout<<endl;

  // }

  // for (int i = 1; i <=n; i++)
  // {
  //     for (int j = 0; j < i; j++)
  //     {
  //          cout<<i-j;
  //     }
  //     cout<<endl;
  // }

  // if (1<=n && n<=26)
  // {

  // for (int i = 0; i < n; i++)
  // {
  //    for (int j = 0; j < n; j++)
  //    {
  //      cout<<char(65+i)<<" ";
  //    }
  //    cout<<endl;
  // }
  // }
  // else{
  //     exit(0);
  // }

  // if (1<=n && n<=26)
  // {

  // for (int i = 0; i < n; i++)
  // {
  //    for (int j = 0; j < n; j++)
  //    {
  //      cout<<char(65+j)<<" ";
  //    }
  //    cout<<endl;
  // }
  // }
  // else{
  //     exit(0);
  // }

  // for (int i = 1; i <=n; i++)
  // {
  //   for (int j = 0; j < n; j++)
  //   {
  //     cout<<char(65+(j+n*(i-1)))<<" ";
  //   }
  //   cout<<endl;
  // }

  // for (int i = 1; i <= n; i++)
  // {
  //     for (int j = 0; j < n; j++)
  //     {
  //     cout<<char(65+((i-1)+j))<<" ";

  //     }
  //     cout<<endl;
  // }

  // for (int i = 1; i <= n; i++)
  // {
  // for (int j = 0; j < i; j++)
  // {
  //     cout<<char(64+i)<<" ";
  // }
  // cout<<endl;
  // }

  // int count=1;
  //     for (int i = 1; i <= n; i++)
  //     {
  //         for (int j = 0; j < i; j++)
  //         {
  //             cout<<char(64+count)<<' ';
  //             count++;
  //         }
  //         cout << endl;
  //     }

  // for (int i = 1; i <=n; i++)
  // {
  //   for (int j =i; j >0; j--)
  //   {
  //     cout<<char(65+n-j)<<' ';
  //   }
  //   cout<<endl;
  // }

  // for (int i = 0; i <n; i++)
  // {
  //   for (int j = 1; j <n-i; j++)
  //   {

  // cout<<' ';
  //   }
  //   for (int j = 0; j < 1+i; j++)
  //   {
  //     cout<<"*";
  //   }

  //   cout<<endl;
  // }

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 0; j < i; j++)
  //   {
  //     cout << " ";
  //   }

  //   for (int j = 1; j <=n - i; j++)
  //   {

  //     cout << '*';
  //   }

  //   cout << endl;
  // }

  // int count = 1;
  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= n - i; j++)
  //   {

  //     cout << ' ';
  //   }
  //   for (int j = 0; j < i; j++)
  //   {
  //     cout << count;
  //     count++;
  //   }
  //   cout << endl;
  // }

  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= n - i; j++)
  //   {

  //     cout << ' ';
  //   }

  //   int d = 0;
  //   for (int j = 0; j < (2 * i - 1); j++)
  //   {
  //     if (j >= (i - 1))
  //     {
  //       cout << i - d;
  //       d++;
  //     }

  //     else
  //     {
  //       cout << j + 1;
  //     }
  //   }
  //   cout << endl;
  // }



  // DABANG pattern

  // for (int i = 0; i < n; i++)
  // {
  //   for (int j = 1; j <= n - i; j++)
  //   {
  //     cout << j;
  //   }

  //   for (int a = 0; a < 2 * (i + 1) - 2; a++)
  //   {
  //     cout << '*';
  //   }

  //   for (int b = n - i; b > 0; b--)
  //   {
  //     cout << b;
  //   }

  //   cout << endl;
  // }



// revision

// for (int i = 0; i <n; i++)
// {
//   for (int j = i; j >=0; j--)
//   {
//     cout<<char(64+n-j);
//   }
//   cout<<endl;
// }


// for (int i = 0; i < n; i++)
// {
//   for (int j = 0; j < i; j++)
//   {
//     cout<<" ";
//   }
//   for (int c = 0; c < n-i; c++)
//   {
//    cout<<"*";
//   }
  
//   cout<<endl;
// }


// for (int i = 1; i <= n; i++)
// {
//   for (int j = 0; j < n-i; j++)
//   {
//     cout<<" ";
//   }
//   for (int c = 0; c <i; c++)
//   {
//     cout<<c+1;
//   }
//   for (int d = i-1; d>0; d--)
//   {
//     cout<<d;
//   }
//   cout<<endl;
  
  
// }




for (int i = 0; i < n; i++)
{
  for (int j = 1; j <= n-i; j++)
  {
   cout<<j;
  }
  for (int c = 0; c < 2*i; c++)
  {
   cout<<"*";
  }
  for (int d = 0; d < n-i; d++)
  {
    cout<<n-d-i;
  }
  
  cout<<endl;
}



  return 0;
}