#include <bits/stdc++.h> // Includes all standard libraries

// Use standard namespace to avoid prefixing standard library elements with std::
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams,
    // which can be slow due to synchronization.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation,
    // further speeding up I/O.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of test cases
    cin >> T; // Read the number of test cases from standard input

    // Loop through each test case
    while (T--) {
        int N; // Declare variable for the number of submissions in the current test case
        cin >> N; // Read the number of submissions for the current test case

        int late_submissions_count = 0; // Initialize a counter for submissions judged late

        // Loop N times to read details for each submission
        for (int i = 0; i < N; ++i) {
            int S, J; // Declare variables for submission time (S) and judging time (J)
            cin >> S >> J; // Read submission time and judging time for the current submission

            // Calculate the delay for the current submission.
            // The problem asks to determine how many submissions received their verdicts
            // after a delay of more than 5 minutes.
            // This translates to the condition: (Judging Time - Submission Time) > 5.
            if (J - S > 5) {
                late_submissions_count++; // Increment the counter if the delay meets the condition
            }
        }

        // After processing all submissions for the current test case,
        // print the total count of late submissions.
        // Use "\n" instead of endl for potentially faster output, as endl also flushes the buffer.
        cout << late_submissions_count << "\n";
    }

    return 0; // Indicate successful program execution
}