#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cout` from flushing before `cin` reads input.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // Declare an integer variable 't' to store the number of test cases.
    cin >> t; // Read the number of test cases from standard input.

    // Loop 't' times, once for each test case.
    // The `while (t--)` idiom is common for iterating 't' times,
    // decrementing 't' in each iteration until it becomes 0.
    while (t--) {
        int n; // Declare an integer variable 'n' to store the input number for the current test case.
        cin >> n; // Read the integer 'n' from standard input.

        // Check the condition specified in the problem statement:
        // If 'n' is less than 10.
        if (n < 10) {
            // If the condition is true, print the specified message.
            // `"\n"` is used for a newline character, as required for each output.
            cout << "Thanks for helping Chef!\n";
        } else {
            // If the condition is false (i.e., 'n' is 10 or greater), print "-1".
            cout << "-1\n";
        }
    }

    return 0; // Indicate successful program execution.
}