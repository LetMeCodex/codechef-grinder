#include <bits/stdc++.h> // Includes most standard libraries, as requested by problem statement
using namespace std;       // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare variable for the number of testcases
    cin >> T; // Read the number of testcases

    // Loop through each testcase
    while (T--) {
        // Declare variables for minimum required scores and Chef's actual scores
        int A_min, B_min, C_min, T_min; // Minimum scores for subjects and total
        int A, B, C;                   // Chef's scores in subjects

        // Read the seven integers for the current testcase
        cin >> A_min >> B_min >> C_min >> T_min >> A >> B >> C;

        // Check all four conditions simultaneously using logical AND (&&) operator.
        // Chef passes only if ALL conditions are true.
        if (A >= A_min &&        // Condition 1: Score in subject A meets minimum
            B >= B_min &&        // Condition 2: Score in subject B meets minimum
            C >= C_min &&        // Condition 3: Score in subject C meets minimum
            (A + B + C >= T_min) // Condition 4: Total score meets minimum
        ) {
            // If all conditions are met, Chef passes
            cout << "YES\n";
        } else {
            // Otherwise, Chef does not pass
            cout << "NO\n";
        }
    }

    return 0; // Indicate successful program execution
}