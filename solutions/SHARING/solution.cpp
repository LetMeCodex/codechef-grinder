#include <bits/stdc++.h> // Includes all standard libraries, as requested.

using namespace std; // Uses the standard namespace, as requested.

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio.
    // As requested by the problem statement.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare two integer variables A and B to store the number of cookies
    // Alice and Bob have, respectively.
    // Constraints: 1 <= B < A <= 10. 'int' is perfectly sufficient.
    int A, B;

    // Read the two integers A and B from standard input.
    // As per the input format, these are on a single line.
    cin >> A >> B;

    // The goal is for Alice and Bob to have an equal number of cookies.
    // Let X be the number of cookies Alice gives to Bob.
    // After Alice gives X cookies:
    // Alice will have (A - X) cookies.
    // Bob will have (B + X) cookies.

    // For them to have an equal number of cookies, their counts must be the same:
    // A - X = B + X

    // Now, we solve this equation for X:
    // A - B = X + X
    // A - B = 2 * X
    // X = (A - B) / 2

    // For X to be a valid number of cookies Alice gives to Bob, it must satisfy two conditions:
    // 1. X must be a non-negative integer.
    //    Since A > B (given in problem statement), (A - B) will always be a positive integer.
    //    Thus, X will always be positive.
    // 2. X must be an integer (no fractional cookies).
    //    This means (A - B) must be an even number. If (A - B) is odd, then (A - B) / 2
    //    will not be an integer, and it's impossible to share equally with whole cookies.

    // Calculate the difference in cookies.
    int difference = A - B;

    // Check if the difference is an even number.
    if (difference % 2 == 0) {
        // If the difference is even, it's possible to share equally.
        // Alice needs to give Bob half of the difference.
        cout << difference / 2 << "\n";
    } else {
        // If the difference is odd, it's impossible to share equally.
        // Output -1 as per problem requirements.
        cout << -1 << "\n";
    }

    return 0; // Indicate successful execution.
}