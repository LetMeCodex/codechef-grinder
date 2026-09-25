#include <bits/stdc++.h> // Includes most standard libraries like iostream

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int A, B, C;
    // Read Chef's scores for the three sections
    cin >> A >> B >> C;

    // Condition 1: Total score of Chef is >= 100
    // Calculate the sum of scores
    int total_score = A + B + C;
    bool total_score_condition_met = (total_score >= 100);

    // Condition 2: Score of each section >= 10
    bool section_scores_condition_met = (A >= 10 && B >= 10 && C >= 10);

    // Chef passes if BOTH conditions are satisfied
    if (total_score_condition_met && section_scores_condition_met) {
        cout << "PASS\n"; // Output PASS if both conditions are true
    } else {
        cout << "FAIL\n"; // Output FAIL otherwise
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop T times, calling the solve function for each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful program execution
}