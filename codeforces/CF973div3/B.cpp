#include <bits/stdc++.h>
#define int long long
using namespace std;

// Function to check if the total number of leaves in year n is even or odd
string isEvenLeaves(int n, int k) {
    // The number of leaves on the tree in year n is the sum of the leaves from years n-k+1 to n
    // This is equivalent to summing the integers from n-k+1 to n

    int start = n - k + 1;  // Starting year for leaf sum
    int end = n;            // Ending year for leaf sum

    // Sum of an arithmetic series: Sum = (n * (n + 1)) / 2 for 1 to n
    // Therefore, sum from start to end is: Sum(end) - Sum(start-1)
    int totalLeaves = (end * (end + 1)) / 2 - (start * (start - 1)) / 2;


    if (totalLeaves % 2 == 0) {
        return "YES";  
    } else {
        return "NO";   
    }
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        
        cout << isEvenLeaves(n, k) << endl;
    }
    return 0;
}
