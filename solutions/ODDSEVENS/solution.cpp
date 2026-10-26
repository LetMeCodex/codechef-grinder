#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of testcases.
    cin >> t; // Read the number of testcases from standard input.

    // Loop 't' times, once for each testcase.
    while (t--) {
        int a, b; // Declare two integer variables 'a' and 'b' for Alice's and Bob's numbers.
        cin >> a >> b; // Read Alice's and Bob's numbers from standard input.

        int sum = a + b; // Calculate the sum of the numbers played by Alice and Bob.

        // Determine the winner based on the parity of the sum.
        // If the sum is odd (sum % 2 == 1), Alice wins.
        // Otherwise (if sum % 2 == 0), the sum is even, and Bob wins.
        if (sum % 2 == 1) {
            cout << "Alice\n"; // Output "Alice" followed by a newline if Alice wins.
        } else {
            cout << "Bob\n"; // Output "Bob" followed by a newline if Bob wins.
        }
    }

    return 0; // Indicate successful program execution.
}