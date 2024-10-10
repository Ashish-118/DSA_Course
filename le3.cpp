#include <iostream>
using namespace std;

int main()
{
   //  int a,b;
   //  cin>>a>>b;
   //  cout<<"value"<<a<<b;

   //  a=cin.get();
   //  cout<<"value of a "<<a;

   // HomeWrok---------------------------------

   // char ch;
   // cout<<"Enter  Any Character ";
   // cin>>ch;

   // int num=ch;
   // if (48<=num && num<=57)
   // {
   //     cout<<"Numeric"<<endl;
   // }

   // else if (65<=num && num<=90)
   // {
   //     cout<<"uppercase"<<endl;
   // }
   // else if (97<=num && num<=122)
   // {
   //     cout<<"lowercase"<<endl;
   // }

   // else{
   //     cout<<"Unknown character"<<endl;
   // }

   // --------------------------------------------

   // -----------------------------------------------
   // int n;
   // cout<<"Enter the value of n ";
   // cin>>n;

   // for (int i = 2; i <=n; i++)
   // {

   //     if (i==n)
   //     {
   //        cout<<"prime no"<<endl;
   //     }
   //     else{

   //     if (n%i==0)
   //     {
   //         cout<<"not a prime number "<<endl;
   //         break;
   //     }
   //     }

   // }
   // -----------------------------------------------
   int row;
   cout << "Enter the no of row you want" << endl;
   cin >> row;
   for (int i = 1; i <= row; i++)
   {
      for (int j = 0; j < row; j++)
      {
         cout << i << " ";
      }
      cout << endl;
   }

   return 0;
}