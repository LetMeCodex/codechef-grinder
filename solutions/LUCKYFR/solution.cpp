#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Use standard namespace for convenience

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int N;
        cin >> N; // Read the integer for the current test case

        int count = 0; // Initialize a counter for occurrences of the digit '4'

        // Loop to extract digits from N and count '4's.
        // The loop continues as long as N has digits remaining (N > 0).
        // This also correctly handles the case where N is 0:
        // If N is 0, the loop condition (N > 0) is false, so the loop is skipped.
        // 'count' remains 0, which is the correct answer for N=0.
        while (N > 0) {
            int digit = N % 10; // Get the last digit of N
            if (digit == 4) {   // Check if the extracted digit is '4'
                count++;        // If it is, increment the counter
            }
            N /= 10;            // Remove the last digit from N using integer division
        }

        // Output the total count of '4's for the current number, followed by a newline.
        cout << count << "\n";
    }

    return 0; // Indicate successful program execution
}