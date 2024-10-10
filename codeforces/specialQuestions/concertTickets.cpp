#include <bits/stdc++.h>
#define int long long
using namespace std;

//multiset in C++ automatically stores elements in sorted order. The elements are always sorted in non-decreasing order based on their values, and this is handled internally by the data structure, which is typically implemented as a balanced binary search tree

//  erase,insertion,deletion all's TC is log(n)

int32_t main()
{
    int n, m;
    cin >> n >> m;
    
    // Use multiset to store the elements of v1
    multiset<int> v1;
    vector<int> v2(m);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v1.insert(x);
    }
    
    for (int i = 0; i < m; i++) {
        cin >> v2[i];
    }
    
    for (int i = 0; i < m; i++)
    {
        auto it = v1.upper_bound(v2[i]);  // Find the first element greater than v2[i]
        if (it == v1.begin()) {
            cout << -1 << endl;  // No valid element
        }
        else {
            --it;  // Move iterator to the largest element <= v2[i]
            cout << *it << endl;
            v1.erase(it);  // Erase the element from the multiset
        }
    }

    return 0;
}
