#include <bits/stdc++.h>
using namespace std;

// Binary Search Templates

// 1. Find exact element (returns index or -1)
int binarySearchExact(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// 2. Binary Search on Answer (Monotonic Function)
// Example: Find maximum x such that check(x) is true
bool check(long long mid) {
    // Implement condition check here
    return true; 
}

long long binarySearchAnswer(long long low, long long high) {
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) {
            ans = mid;    // Record answer
            low = mid + 1; // Try for a larger value
        } else {
            high = mid - 1; // Try smaller value
        }
    }
    return ans;
}

// 3. Binary Search for Minimum value (e.g. minimum capacity)
long long binarySearchAnswerMin(long long low, long long high) {
    long long ans = -1;
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid)) { // If mid is valid, try to find a smaller valid value
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

void solve() {
    vector<int> arr = {1, 2, 4, 4, 5, 6, 8, 9};
    
    // Using standard library functions
    auto lb = lower_bound(arr.begin(), arr.end(), 4); // First element >= 4
    auto ub = upper_bound(arr.begin(), arr.end(), 4); // First element > 4
    
    cout << "Lower bound of 4 is at index: " << distance(arr.begin(), lb) << "\n";
    cout << "Upper bound of 4 is at index: " << distance(arr.begin(), ub) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
    return 0;
}
