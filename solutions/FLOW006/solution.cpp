#include <bits/stdc++.h>

using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard streams and prevents flushing
    // of cout before cin, leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int N; // Declare an integer N to store the input number for the current test case.
        cin >> N; // Read the number N from standard input.

        int sum_of_digits = 0; // Initialize a variable to store the sum of digits.

        // Loop while N is greater than 0 to process each digit.
        // For N=0, the sum of digits is 0. The problem constraints state 1 <= N,
        // so N will always be positive initially.
        while (N > 0) {
            // Get the last digit of N using the modulo operator (N % 10).
            // Add this digit to sum_of_digits.
            sum_of_digits += N % 10;

            // Remove the last digit from N using integer division (N / 10).
            // This effectively shifts the number one place to the right.
            N /= 10;
        }

        // Print the calculated sum of digits for the current test case,
        // followed by a newline character as required.
        cout << sum_of_digits << "\n";
    }

    return 0; // Indicate successful execution of the program.
}