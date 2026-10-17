#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid prefixing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int N, K;
    // Read N (minutes of work needed) and K (pigeon interval)
    cin >> N >> K;

    int total_minutes = 0; // Initialize total elapsed time
    int work_done = 0;     // Initialize actual work completed

    // Continue looping until Chef completes N minutes of work
    while (work_done < N) {
        total_minutes++; // Increment the total elapsed time by one minute

        // Check if the current minute is a pigeon minute.
        // If total_minutes is a multiple of K, Chef cannot work.
        // Otherwise, Chef can work.
        if (total_minutes % K != 0) {
            work_done++; // Chef works, so increment the work done counter
        }
        // If total_minutes % K == 0, Chef is delayed, work_done does not change.
    }

    // Output the total minutes needed to complete N minutes of work
    cout << total_minutes << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful execution
}