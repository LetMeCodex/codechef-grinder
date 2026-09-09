#include <bits/stdc++.h> // Includes most standard libraries, as requested

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the value of T from standard input

    // Loop T times, once for each test case
    while (T--) {
        int N; // Declare an integer variable N for the number of chocolates
        cin >> N; // Read the value of N for the current test case

        // Check if N is an even number.
        // An even number is perfectly divisible by 2, leaving a remainder of 0.
        // If N is even, they can divide chocolates equally.
        if (N % 2 == 0) {
            cout << "Yes\n"; // Output "Yes" followed by a newline
        } else {
            // If N is odd, it's not perfectly divisible by 2.
            // They cannot divide chocolates equally without breaking them.
            cout << "No\n"; // Output "No" followed by a newline
        }
    }

    return 0; // Indicate successful program execution
}