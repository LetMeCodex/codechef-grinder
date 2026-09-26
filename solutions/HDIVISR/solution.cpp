#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare an integer variable N to store the input.
    // N will fit within an 'int' as its maximum value is 1000.
    int N;

    // Read the integer N from standard input.
    cin >> N;

    // Iterate from 10 down to 1.
    // We start from 10 because we are looking for the *largest* divisor
    // in the range [1, 10]. The first one we find will be the answer.
    for (int i = 10; i >= 1; --i) {
        // Check if 'i' divides 'N' evenly.
        // The modulo operator (%) returns the remainder of the division.
        // If the remainder is 0, then 'i' is a divisor of 'N'.
        if (N % i == 0) {
            // If 'i' divides 'N', it is the largest such divisor found so far
            // (and since we iterate downwards, it's the overall largest).
            // Print 'i' followed by a newline character.
            cout << i << "\n";

            // Terminate the program after finding and printing the answer.
            // This is efficient as we don't need to check smaller numbers.
            return 0;
        }
    }

    // This part of the code should theoretically never be reached because
    // the loop is guaranteed to find at least '1' as a divisor for any N >= 1.
    // However, a 'return 0;' at the end of main is standard practice for successful execution.
    return 0;
}