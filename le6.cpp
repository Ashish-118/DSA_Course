#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter Any number " << endl;
    cin >> num;
    int answers = 0;
    int i = 0;
    while (num != 0)
    {
        int bit = (num % 2) & 1;
        cout<<bit<<endl;
        answers = ((pow(10, i)) * bit) + answers;

        // num = num / 2;
        num = num >> 1;
        i++;
    }
    cout << "Binary number is " << answers << endl;




    // binary to decimal converter
    // int ans = 0;
    // for (int i = 0; num != 0; i++)
    // {
    //     int digit = num & 1;
    //     if (digit)
    //     {
    //        ans=pow(2,i)+ans;
    //     }
        
    //     num = num / 10;
    // }

    // cout<<"The Decimal number is "<<ans<<endl;

    return 0;
}