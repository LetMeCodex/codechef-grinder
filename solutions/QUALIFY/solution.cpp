#include <bits/stdc++.h> // Includes all standard libraries, as requested

// Use the standard namespace to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    int X, A, B;
    // Read the minimum required points (X),
    // number of easy problems solved (A),
    // and number of hard problems solved (B) for the current test case.
    cin >> X >> A >> B;

    // Calculate Chef's total score.
    // Easy problems are worth 1 point each (A * 1).
    // Hard problems are worth 2 points each (B * 2).
    int total_score = (A * 1) + (B * 2);

    // Check if Chef's total score is sufficient to qualify.
    // Chef qualifies if the total score is greater than or equal to X.
    if (total_score >= X) {
        // If Chef qualifies, print "Qualify" followed by a newline.
        cout << "Qualify\n";
    } else {
        // Otherwise, Chef does not qualify, so print "NotQualify" followed by a newline.
        cout << "NotQualify\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard I/O.
    // cin.tie(NULL) prevents cout from being flushed before each cin operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases.
    cin >> T;
    // Loop T times, calling the solve() function for each test case.
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution.
}