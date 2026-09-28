#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace as requested
using namespace std;

// Function to calculate the maximum streak for a given sequence of N scores.
// It reads N integers from standard input.
int calculateMaxStreak(int N) {
    int current_streak = 0; // Stores the length of the current active streak
    int max_streak = 0;     // Stores the maximum streak found so far

    for (int i = 0; i < N; ++i) {
        int problems_solved;
        cin >> problems_solved; // Read the number of problems solved on the current day

        if (problems_solved > 0) {
            // If at least one problem is solved, the streak continues/increases
            current_streak++;
        } else {
            // If 0 problems are solved, the streak is broken.
            // First, update max_streak if the just-ended current_streak was longer.
            max_streak = max(max_streak, current_streak);
            // Then, reset current_streak to 0 as a new streak must start.
            current_streak = 0;
        }
    }
    // After the loop, there might be an ongoing streak that extends to the last day.
    // This streak would not have been compared with max_streak yet because it didn't end with a '0'.
    // So, perform one final comparison to ensure this last streak is considered.
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

// Function to solve a single test case
void solve() {
    int N;
    cin >> N; // Read the number of days

    // Calculate Om's maximum streak by calling calculateMaxStreak.
    // This call will read the N integers for Om's scores.
    int om_max_streak = calculateMaxStreak(N);

    // Calculate Addy's maximum streak.
    // This call will read the N integers for Addy's scores, immediately after Om's scores.
    int addy_max_streak = calculateMaxStreak(N);

    // Compare their maximum streaks and print the result as specified.
    if (om_max_streak > addy_max_streak) {
        cout << "OM\n";
    } else if (addy_max_streak > om_max_streak) {
        cout << "ADDY\n";
    } else {
        cout << "DRAW\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // std::ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // std::cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}