#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace for convenience
using namespace std;

void solve() {
    long long A, B; // A and B can be up to 10^9, long long is safe.
    cin >> A >> B;

    int remA = A % 3; // Remainder of A when divided by 3
    int remB = B % 3; // Remainder of B when divided by 3

    if (remA == 0 || remB == 0) {
        // If A or B is already divisible by 3, 0 operations are needed.
        cout << 0 << "\n";
    } else if (remA == remB) {
        // If A % 3 == B % 3 (and neither is 0, so both are 1 or both are 2),
        // then |A - B| will be divisible by 3.
        // For example, if A=4, B=1, then A%3=1, B%3=1. |A-B|=3.
        // We can change A to |A-B| (A becomes 3), or B to |A-B| (B becomes 3).
        // In 1 operation, one number becomes divisible by 3.
        cout << 1 << "\n";
    } else {
        // This case implies (remA, remB) is (1,2) or (2,1) (or their symmetric versions).
        // Neither is 0, and they are not equal.
        // As derived in the thought process, it takes 2 operations to make one number divisible by 3.
        // In one operation, we can reach a state where remA == remB (e.g., (1,1) or (2,2)).
        // From that state, one more operation makes a number divisible by 3.
        // Total 2 operations.
        cout << 2 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Number of test cases
    cin >> t;
    while (t--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}