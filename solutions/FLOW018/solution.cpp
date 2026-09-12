#include <bits/stdc++.h> // Includes common headers like iostream, vector, algorithm, etc.

using namespace std; // Allows using standard library components without std:: prefix

int main() {
    // Optimize C++ standard streams for competitive programming.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // potentially speeding up I/O operations.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The 't--' decrements 't' after each iteration until it becomes 0.
    while (t--) {
        int n; // Declare an integer variable 'n' to store the input number for which factorial is to be calculated.
        cin >> n; // Read the number 'n' for the current test case.

        // Declare a long long variable 'factorial' and initialize it to 1.
        // long long is used because factorial values can grow very large quickly.
        // For N=20, 20! is 2,432,902,008,176,640,000, which exceeds the capacity of a 32-bit integer
        // (max ~2*10^9) but fits within a 64-bit long long (max ~9*10^18).
        // Initializing to 1 correctly handles 0! = 1 and serves as the base for multiplication.
        long long factorial = 1;

        // Calculate the factorial of 'n'.
        // The loop iterates from 1 up to 'n' (inclusive).
        // In each iteration, 'factorial' is multiplied by the current loop variable 'i'.
        // Example: if n=3, factorial will be:
        // i=1: factorial = 1 * 1 = 1
        // i=2: factorial = 1 * 2 = 2
        // i=3: factorial = 2 * 3 = 6
        for (int i = 1; i <= n; ++i) {
            factorial *= i;
        }

        // Print the calculated factorial value to standard output,
        // followed by a newline character to ensure each output is on a new line
        // as per the problem's output format requirement.
        cout << factorial << "\n";
    }

    return 0; // Indicate that the program executed successfully.
}