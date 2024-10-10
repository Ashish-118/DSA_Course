#include <iostream>
using namespace std;

int main()
{
    int n, copy;
    cout << "Enter the number n" << endl;
    cin >> n;
    copy = n;

    // int a = 0;
    // int b = 1; 
    // cout<<a<<" "<<b;
    // for (int i = 0; i < n; i++)
    // {
    //     int num = a + b;
    //     cout << num << " ";
    //     a = b;
    //     b = num;
    // }

    // int sum=0;
    // int product=1;
    //      for (; n!=0;)
    //      {
    //   int rem=n%10;
    //   product=product*rem;
    //   sum=sum+rem;
    //   n=n/10;
    //      }
    // cout<<"final "<<product-sum;





    // int count=0;
    // for (int i=1; n!=0; i++ )
    // {
    //     int rem=n%2;
    //     n=n/2;
    //     if (rem )
    //     {
    //         count++;
    //     }

    //     if (n==1)
    //     {
    //         count++;
    //         break;
    //     }

    // }
    // cout<<"Total of 1's in the binary digits of number "<<copy<<" is "<<count;



    int count = 0;
    // for (; n != 0;)
    // {
    //     int rem = n % 10;
    //     if (rem==1)
    //     {
    //         count++;
    //     }

    //     n = n / 10;
    // }
    // cout <<"the no of 1's in the given binary number is "<< count << endl;


    // Alternate solution to the previous one

    // cout << (n & 1);  very important command Thing to note
    for (; n != 0;)
    {
        cout<<(n&1)<<endl;
        cout<<n<<endl;
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    cout << "the no of 1's in the given binary number is " << count << endl;

    return 0;
}