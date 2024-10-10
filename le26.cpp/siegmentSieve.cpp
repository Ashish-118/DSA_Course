#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class siegmentedSieve
{
public:
  int siegmented_Sieve(int n)
  {
    vector<long long> isprime;
    long long squareRoot=sqrt(n);
    vector<bool> primeSegment(squareRoot + 1, true);
    vector<bool> prime_num(n , true);

    int countPrime = 0;
    primeSegment[0] = primeSegment[1] = false;
    prime_num[0] = prime_num[1] = false;

    for (long long i = 2; i <= n; i++)
    {
      if (primeSegment[i])
      {
        isprime.push_back(i);

        for (long long  j = 2 * i; j < n; j = j + i)
        {
          primeSegment[j] = 0;
        }
      }
    }

    // for (int i = 0; i < isprime.size(); i++)
    // {
    //   if (prime_num[i])
    //   {
    //     countPrime++;
    //     for (int j = 2 * (isprime[i]); i < n; j = j + isprime[i])
    //     {
    //       prime_num[j] = 0;
    //     }
    //   }
    // }

    for (long long x : isprime)
    {
      for (long long j = 2 * (x); j < n; j = j + x)
      {
        prime_num[j] = 0;
      }
    }
    for (bool x : prime_num)
    {
      if (x)
      {
        countPrime++;
      }
    }
    
    // for(int i=0; i<n; i++)
    // {
    //     if(prime_num[i]){
    //         cout<<i<<" ";
    //         countPrime++;
    //     }
    // }

    return countPrime;
  }
};

int main()
{
  siegmentedSieve obj1;
  cout << obj1.siegmented_Sieve(5000000) << endl;

  return 0;
}