#include <iostream>
using namespace std;

int main()
{

    cout << "Enter the number " << endl;
    int num, copy;
    cin >> num;
    copy = num;

    //     int ans = 0;
    //     bool val=true;
    //     for (int i = 0; num != 0; i++)
    //     {
    //         int digit = num % 10;
    //         if ((ans>INT_MAX/10) || (ans<INT_MIN/10))
    //         {
    //             cout<<0<<endl;
    //             val=false;
    //             break;
    //         }

    //         ans = (10 * ans) + digit;
    //         num = num / 10;
    //     }

    // if (val)
    // {
    //       cout<<ans<<endl;

    // }
    //--------------------------
    // if (num==0)
    // {
    //     cout<<1<<endl;
    // }
    // else{

    //     int binary = 0;
    //     int answers = 0;
    //     for (int i = 0; num != 0; i++)
    //     {
    //         int bit = (num % 2) & 1;

    //         if (bit)
    //         {
    //             bit = 0;
    //         }
    //         else
    //         {
    //             bit = 1;
    //             answers = (pow(2, i)) + answers;
    //         }

    //         binary = (pow(10, i) * bit) + binary;

    //         num = num >> 1;
    //     }

    //     cout<<"The complement of the number "<<copy<<" is "<<binary<<" which is "<<answers<<endl;
    // }

    //  Alternate solution and the Best solution is below:
    //  1.
    // if (num == 0)
    // {
    //     cout << 1 << endl;
    // }
    // else
    // {

    //     int mask = 0;

    //     for (; num != 0;)
    //     {
    //         mask = (mask << 1) | 1;

    //         num = num >> 1;
    //     }

    //     cout << "Complement is " << ((~copy) & mask) << endl;
    // }

    // 2.
    if (num == 0)
    {
        cout << 1 << endl;
    }
    int x = 1;
    while (x <= num)
    {
        num = num ^ x;
        cout<<num<<endl;
        x = x << 1;
        cout<<x<<endl;
    }
    cout << "Complement is " << num << endl;

    // bool val=true;
    // for (; num!=0; )
    // {
    //     if (num==1)
    //     {
    //         val=true;
    //         break;
    //     }
    //     if (num%2!=0)
    //     {
    //         val=false;
    //         break;
    //     }

    //     num=num/2;
    // }

    // if (val)
    // {
    //     cout<<val;
    // }
    // else{
    //     cout<<val;
    // }

    // Alternate and the best solution of the above problem
    //  int val=0;
    //  int ans=1;
    //  for (int i = 0; i <= 30; i++)
    //  {
    //      if (ans==num)
    //      {
    //          val=1;
    //          break;
    //      }
    //      else
    //      {
    //          val=0;
    //      }
    //      ans=ans*2;

    // }
    // cout<<val;

    // Revision of this lecture
    return 0;
}