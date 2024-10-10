#include <iostream>
using namespace std;

int factorial(int n){
if (n==0 || n==1)
{
    return 1;
}

return n*factorial((n-1));

}


int nCr(int N, int R){

return factorial(N)/(factorial(R)*factorial(N-R));

}

int main()
{
    // char ch = '1';
    // int num = 1;

    // cout << endl;
    // switch (ch)
    // {
    // case 1:
    //     cout << "first" << endl;
    //     cout << "First again" << endl;
    //     break;

    // case '1':
    //     switch (num)
    //     {
    //     case 1:
    //         cout << "Value of num is " << num << endl;
    //         break;
    //     }
    //     break;

    // default:
    //     cout << "It is default case" << endl;
    // }
    // cout << endl;






    //  Calculator with switches

    // int a, b;
    // cout << "Enter the value A and B" << endl;
    // cin >> a >> b;

    // char symbol;
    // cout << "Enter the Operator :" << endl;
    // cin >> symbol;

    // switch (symbol)
    // {
    // case '+':
    //     cout << "Answers is " << a + b << endl;
    //     break;
    // case '-':
    //     cout << "Answers is " << a - b << endl;
    //     break;
    // case '*':
    //     cout << "Answers is " << a * b << endl;
    //     break;
    // case '/': 
    //     cout << "Answers is " << a / b << endl;
    //     break;

    // default:
    //     cout << "Symbol is not recognised " << endl;
    //     break;
    // }




//     cout<<"Enter the Amount "<<endl;
//     int amt,h_notes,f_notes,t_notes,o_notes,copy;
//     cin>>amt;
//     copy=amt;

// for (int i = 0; i < 4; i++)
// {
//     switch (i)
//     {
//     case 0:
//       h_notes=amt/100;
//       amt=amt-h_notes*100;
//         break;
//     case 1:
//       f_notes=amt/50;
//       amt=amt-f_notes*50;
      
//         break;
//     case 2:
//       t_notes=amt/20;
//       amt=amt-t_notes*20;
      
//         break;
//     case 3:
//       o_notes=amt/1;
//       amt=amt-o_notes*1;
      
//         break;
    
//     default:
//         break;
//     }
// }

//     cout<<endl<<"For "<<copy<<" Rupees we need "<<h_notes<<" Hundred rupee  notes, "<<f_notes<<" fifty rupee  notes, "<<t_notes<<" twenty rupee  notes and "
//     <<o_notes<<" one rupee notes "<<endl;


// cout<<(4&1);// gives 0 for even 
// cout<<(5&1);// gives 1 for odd



/// using funciton calculate nCr
int n,r;
cout<<"Enter the value of n and r "<<endl;
cin>>n>>r;
 
cout<<"The Answer is "<<nCr(n,r)<<endl;

    return 0; 
}