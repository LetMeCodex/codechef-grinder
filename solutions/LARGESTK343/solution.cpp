#include <bits/stdc++.h> // Includes most standard libraries
using namespace std; // Use standard namespace

void solve() {
    // X: count of 0s
    // Y: count of 1s
    // K: minimum 1s between any two 0s
    // Using long long for X, Y, and K to handle values up to 10^9,
    // ensuring no overflow, although int might suffice for these specific constraints.
    long long X, Y; 
    cin >> X >> Y;

    // The problem states X >= 2.
    // If there are X zeros, they create X-1 "internal" segments (gaps)
    // between consecutive zeros.
    // For example:
    // If X=2, string is 0 [ones] 0. There is 1 gap. (X-1 = 1)
    // If X=3, string is 0 [ones] 0 [ones] 0. There are 2 gaps. (X-1 = 2)
    //
    // The condition "atleast K 1s between any two occurrences of 0s"
    // applies to these X-1 internal gaps.
    //
    // To satisfy this condition, each of these X-1 gaps must contain
    // at least K ones.
    // Therefore, the total number of ones required for these minimums is (X-1) * K.
    //
    // The total number of ones available is Y.
    // So, we must have: Y >= (X-1) * K
    //
    // To find the largest integer K, we rearrange the inequality:
    // K <= Y / (X-1)
    //
    // Since K must be an integer, the largest possible K is the floor of Y / (X-1).
    // In C++, integer division automatically performs floor for positive numbers.
    //
    // X-1 will always be at least 1 (since X >= 2), so division by zero is not a concern.

    long long K = Y / (X - 1);
    
    cout << K << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}