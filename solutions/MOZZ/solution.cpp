#include <bits/stdc++.h> // Includes most standard libraries as requested by the problem

// Use the standard namespace as requested
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X, Y, R;
        cin >> X >> Y >> R; // Read the values for X, Y, and R

        // Step 1: Calculate the number of extra sticks Chef ate.
        // R is guaranteed to be a multiple of 30.
        int extra_sticks = R / 30;

        // Step 2: Calculate the total number of sticks Chef ate.
        // This includes the initial X sticks plus the extra sticks.
        int total_sticks_eaten = X + extra_sticks;

        // Step 3: Calculate the maximum number of plates Chef could have ordered.
        // We need to find the smallest integer number of plates that can provide
        // at least 'total_sticks_eaten' sticks. This is a ceiling division.
        // For positive integers A and B, ceil(A/B) can be calculated as (A + B - 1) / B.
        int plates_ordered = (total_sticks_eaten + Y - 1) / Y;

        // Output the result for the current test case, followed by a newline.
        cout << plates_ordered << "\n";
    }

    return 0; // Indicate successful execution
}