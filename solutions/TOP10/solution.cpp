#include <bits/stdc++.h> // Includes all standard libraries

// Using the standard namespace to avoid typing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can speed up I/O operations significantly.
    // cin.tie(NULL) prevents cout from flushing before cin reads input,
    // further optimizing I/O, especially in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable 'T' to store the number of test cases.
    cin >> T; // Read the value of 'T' from standard input.

    // Loop 'T' times, once for each test case.
    // The 'T--' decrements T after each iteration, and the loop continues as long as T is greater than 0.
    while (T--) {
        int X; // Declare an integer variable 'X' to store Chef's rank for the current test case.
        cin >> X; // Read the value of 'X' from standard input.

        // Check if Chef's rank 'X' is less than or equal to 10.
        // If the rank is 10 or less, Chef made it to the top 10.
        if (X <= 10) {
            cout << "YES\n"; // Output "YES" followed by a newline character.
        } else {
            // If Chef's rank is greater than 10, Chef did not make it to the top 10.
            cout << "NO\n"; // Output "NO" followed by a newline character.
        }
    }

    return 0; // Indicate that the program executed successfully.
}