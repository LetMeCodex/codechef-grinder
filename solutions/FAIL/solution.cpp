#include <bits/stdc++.h> // Includes most standard libraries like iostream, vector, etc.

// Using namespace std; as requested
using namespace std;

void solve() {
    int N;
    cin >> N; // Read the number of tests

    long long current_sum = 0; // Initialize sum of scores. Using long long as a safe practice.
    bool scholarship_lost = false; // Flag to track if scholarship is lost

    // Iterate through each test
    for (int i = 0; i < N; ++i) {
        int score;
        cin >> score; // Read the score for the current test

        // Only perform checks if the scholarship hasn't been lost yet.
        // We must still read all remaining scores for the current test case
        // to ensure correct input parsing for subsequent test cases.
        if (!scholarship_lost) {
            current_sum += score; // Add current score to the total sum

            // The number of tests taken so far is (i + 1).
            // Check if the average (current_sum / (i + 1)) is less than 40.
            // This is equivalent to current_sum < 40 * (i + 1) to avoid floating-point arithmetic.
            // Using 40LL ensures the multiplication is performed using long long,
            // preventing potential overflow if (i + 1) were very large (though not an issue here).
            if (current_sum < 40LL * (i + 1)) {
                scholarship_lost = true; // Scholarship lost
            }
        }
    }

    // Output the result based on the flag
    if (scholarship_lost) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    // Enable fast I/O as requested for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop through each test case
        solve(); // Solve the current test case
    }

    return 0;
}