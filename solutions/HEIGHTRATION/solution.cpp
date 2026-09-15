#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Height of Rationals
 * The height of a fraction a/b is defined as max(a, b).
 * Given constraints: 1 <= a, b <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b;
    // The problem description implies a single line of input for a and b.
    // If there were multiple test cases, we would wrap this in a while(t--) loop.
    if (cin >> a >> b) {
        cout << max(a, b) << "\n";
    }

    return 0;
}