#include <bits/stdc++.h> // Includes most standard libraries
using namespace std;

void solve() {
    int L;
    cin >> L; // Read the total number of years
    string S;
    cin >> S; // Read the string representing good/bad years

    int good_years_count = 0; // Counter for good years in the current prefix
    bool can_go_to_heaven = false; // Flag to indicate if Chef can go to heaven

    // Iterate through all possible L' values, from 1 to L.
    // 'i' is the 0-based index, so (i + 1) represents the current L'.
    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years_count++; // Increment if the current year is good
        }

        // Check the condition: 2 * (good years) >= (total years lived)
        // Here, total years lived is (i + 1)
        if (2 * good_years_count >= (i + 1)) {
            can_go_to_heaven = true; // Condition met, Chef can go to heaven
            break; // No need to check further L' values
        }
    }

    // Output the result based on the flag
    if (can_go_to_heaven) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and disables synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}