#include <bits/stdc++.h> // Includes all standard libraries for competitive programming

// Use the standard namespace to avoid repeatedly typing std::
using namespace std;

// Function to solve a single test case
void solve() {
    // Declare variables for Dragon's scores in DSA, TOC, and DM
    int D_dsa, D_toc, D_dm;
    // Read Dragon's scores from input
    cin >> D_dsa >> D_toc >> D_dm;

    // Declare variables for Sloth's scores in DSA, TOC, and DM
    int S_dsa, S_toc, S_dm;
    // Read Sloth's scores from input
    cin >> S_dsa >> S_toc >> S_dm;

    // Calculate the total score for Dragon
    int D_total = D_dsa + D_toc + D_dm;
    // Calculate the total score for Sloth
    int S_total = S_dsa + S_toc + S_dm;

    // Apply the ranking rules hierarchically

    // Rule 1: Compare total scores
    if (D_total > S_total) {
        // If Dragon has a higher total score, Dragon gets a better rank
        cout << "DRAGON\n";
    } else if (S_total > D_total) {
        // If Sloth has a higher total score, Sloth gets a better rank
        cout << "SLOTH\n";
    } else {
        // If total scores are tied, proceed to Rule 2: Compare DSA scores
        if (D_dsa > S_dsa) {
            // If Dragon has a higher DSA score, Dragon gets a better rank
            cout << "DRAGON\n";
        } else if (S_dsa > D_dsa) {
            // If Sloth has a higher DSA score, Sloth gets a better rank
            cout << "SLOTH\n";
        } else {
            // If DSA scores are also tied, proceed to Rule 3: Compare TOC scores
            if (D_toc > S_toc) {
                // If Dragon has a higher TOC score, Dragon gets a better rank
                cout << "DRAGON\n";
            } else if (S_toc > D_toc) {
                // If Sloth has a higher TOC score, Sloth gets a better rank
                cout << "SLOTH\n";
            } else {
                // If all criteria (total, DSA, TOC) are tied, it's an overall tie
                cout << "TIE\n";
            }
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    // `ios_base::sync_with_stdio(false)` unties C++ streams from C standard streams.
    // `cin.tie(NULL)` prevents `cin` from flushing `cout` before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases from input

    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for the current test case
    }

    return 0; // Indicate successful program execution
}