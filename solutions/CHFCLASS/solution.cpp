#include <bits/stdc++.h> // Include all standard libraries

// Use the standard namespace
using namespace std;

int main() {
    // Enable fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int N;
        cin >> N; // Read the number of days in the month

        // Calculate the number of Saturdays.
        // A week has 7 days, starting Monday. Saturday is the 6th day.
        // The formula (N + 1) / 7 correctly calculates the number of Saturdays.
        //
        // Let N = 7q + r, where q = N/7 (integer division) and r = N%7.
        //
        // If r < 6 (i.e., r is 0, 1, 2, 3, 4, 5):
        //   The N days contain 'q' full weeks, each with one Saturday.
        //   The remaining 'r' days (starting from Monday) do not include a Saturday.
        //   So, the total Saturdays should be 'q'.
        //   Formula: (N + 1) / 7 = (7q + r + 1) / 7 = q + (r + 1) / 7.
        //   Since 1 <= r + 1 <= 6, (r + 1) / 7 evaluates to 0 in integer division.
        //   Result: q + 0 = q. This is correct.
        //
        // If r = 6:
        //   The N days contain 'q' full weeks, plus 6 additional days (Monday to Saturday).
        //   This means there are 'q' Saturdays from the full weeks, and one more Saturday from the remaining 6 days.
        //   So, the total Saturdays should be 'q + 1'.
        //   Formula: (N + 1) / 7 = (7q + 6 + 1) / 7 = (7q + 7) / 7 = q + 1.
        //   Result: q + 1. This is correct.
        
        int Saturdays = (N + 1) / 7;
        
        cout << Saturdays << "\n"; // Output the result for the current test case
    }

    return 0;
}