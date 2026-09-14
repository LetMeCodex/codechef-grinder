#include <bits/stdc++.h> // Include all standard libraries

using namespace std; // Use standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    // T-- decrements T after each iteration, and the loop continues as long as T is non-zero.
    while (T--) {
        int X; // Declare an integer variable X to store the hours Chef slept.
        cin >> X; // Read the number of hours Chef slept for the current test case.

        // A person is sleep deprived if they slept strictly less than 7 hours.
        // Check if X is less than 7.
        if (X < 7) {
            // If X is strictly less than 7, Chef is sleep deprived.
            // Output "YES" followed by a newline character.
            cout << "YES\n";
        } else {
            // If X is 7 or more, Chef is not sleep deprived.
            // Output "NO" followed by a newline character.
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution.
}