#include <bits/stdc++.h> // Includes most standard libraries

// Use standard namespace for convenience
using namespace std;

// Function to solve a single test case
void solve() {
    int X; // Duration of the contest in minutes
    cin >> X;

    // Convert contest duration from minutes to seconds
    int total_seconds = X * 60;

    // The participant cannot make any submission in the last 5 seconds.
    // This means submissions must be made at a time 't' such that t < (total_seconds - 5).
    // Let effective_end_time be the first second when submissions are NOT allowed.
    int effective_end_time = total_seconds - 5;

    // A participant can make 1 submission every 30 seconds.
    // To maximize submissions, the participant should make the first submission at time 0,
    // and subsequent submissions exactly 30 seconds apart.
    // The sequence of submission times would be: 0, 30, 60, ..., (k-1)*30.
    // The last submission, at time (k-1)*30, must satisfy:
    // (k-1)*30 < effective_end_time
    //
    // This inequality is equivalent to:
    // (k-1)*30 <= effective_end_time - 1 (since all values are integers)
    //
    // Divide by 30 (using integer division, which truncates towards zero for positive numbers):
    // k-1 <= (effective_end_time - 1) / 30
    //
    // Add 1 to both sides to find the maximum possible value for k:
    // k = (effective_end_time - 1) / 30 + 1
    int max_submissions = (effective_end_time - 1) / 30 + 1;

    // Output the result for the current test case, followed by a newline
    cout << max_submissions << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}