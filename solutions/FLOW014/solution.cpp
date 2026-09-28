#include <bits/stdc++.h> // Required header for competitive programming
using namespace std; // Required namespace for competitive programming

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin/cout from the C standard streams and disables synchronization.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the total number of testcases

    while (T--) { // Loop T times, once for each testcase
        int hardness;
        double carbon_content; // Carbon content can be a decimal value (e.g., 0.6, 0.7)
        int tensile_strength;

        // Read the three properties for the current steel sample
        cin >> hardness >> carbon_content >> tensile_strength;

        int grade; // Variable to store the calculated grade

        // Evaluate each of the three conditions
        bool cond1 = (hardness > 50);
        bool cond2 = (carbon_content < 0.7);
        bool cond3 = (tensile_strength > 5600);

        // Determine the grade based on the specified hierarchy of conditions
        if (cond1 && cond2 && cond3) {
            grade = 10; // Grade 10: All three conditions met
        } else if (cond1 && cond2) {
            grade = 9; // Grade 9: Conditions 1 and 2 met (and condition 3 is NOT met, otherwise it would be Grade 10)
        } else if (cond2 && cond3) {
            grade = 8; // Grade 8: Conditions 2 and 3 met (and condition 1 is NOT met)
        } else if (cond1 && cond3) {
            grade = 7; // Grade 7: Conditions 1 and 3 met (and condition 2 is NOT met)
        } else if (cond1 || cond2 || cond3) {
            grade = 6; // Grade 6: Only one condition is met.
                        // (If two or three conditions were met, they would have been caught by previous if/else if blocks)
        } else {
            grade = 5; // Grade 5: None of the three conditions are met
        }

        // Print the calculated grade for the current testcase, followed by a newline
        cout << grade << "\n";
    }

    return 0; // Indicate successful program execution
}