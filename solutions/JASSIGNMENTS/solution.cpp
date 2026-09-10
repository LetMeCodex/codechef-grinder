#include <bits/stdc++.h> // Includes all standard libraries

using namespace std; // Allows using standard library elements without the std:: prefix

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T to store the number of test cases.
    cin >> T; // Read the number of test cases from standard input.

    // Loop T times, once for each test case.
    while (T--) {
        int X; // Declare an integer variable X to store the starting time.
        cin >> X; // Read the starting time X for the current test case.

        // Calculate the time Janmansh will finish all 3 assignments.
        // Each assignment takes 1 hour, so 3 assignments take 3 hours.
        int finish_time = X + 3;

        // Check if the finish time is on or before 10 PM.
        if (finish_time <= 10) {
            // If he finishes by 10 PM, he can complete them on time.
            cout << "Yes\n"; // Output "Yes" followed by a newline.
        } else {
            // If he finishes after 10 PM, he cannot complete them on time.
            cout << "No\n"; // Output "No" followed by a newline.
        }
    }

    return 0; // Indicate successful program execution.
}