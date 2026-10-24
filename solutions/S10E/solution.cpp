#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace, as requested
using namespace std;

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of days
    vector<int> P(N); // Create a vector to store prices
    for (int i = 0; i < N; ++i) {
        cin >> P[i]; // Read prices for each day
    }

    int good_days_count = 0; // Initialize counter for good days

    // Iterate through each day from 0 to N-1
    for (int i = 0; i < N; ++i) {
        bool is_good = true; // Assume current day's price is good initially

        // Check prices from day i-1 down to max(0, i-5)
        // The inner loop iterates for j = 1, 2, 3, 4, 5, representing 1 to 5 days back
        for (int j = 1; j <= 5; ++j) {
            // Calculate the index of the previous day to compare with
            int prev_day_idx = i - j;

            if (prev_day_idx >= 0) { // Check if the previous day exists (index is valid)
                // If current price is not strictly smaller than a previous price, it's not good
                if (P[i] >= P[prev_day_idx]) {
                    is_good = false; // Mark as not good
                    break;           // No need to check further previous days for current 'i'
                }
            } else {
                // If prev_day_idx < 0, it means we've gone past the beginning of the array.
                // The problem states to ignore non-existent previous days.
                // Since 'j' is increasing, all subsequent 'i-j' will also be negative.
                // So, there are no more valid previous days to check in this direction.
                break;
            }
        }

        // If after all checks, the price is still considered good, increment the counter
        if (is_good) {
            good_days_count++;
        }
    }

    // Print the total count of good days for this test case
    cout << good_days_count << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output, as requested
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0; // Indicate successful execution
}