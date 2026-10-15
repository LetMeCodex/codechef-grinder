#include <bits/stdc++.h> // Includes iostream, cmath, etc.

// Using the standard namespace as requested by the problem statement.
using namespace std;

// Function to check if a number is imperfect
// A positive integer M is imperfect if it's divisible by either 2 or 5, but not both.
bool is_imperfect(int num) {
    // Imperfect numbers must be positive.
    if (num <= 0) {
        return false;
    }

    bool div_by_2 = (num % 2 == 0);
    bool div_by_5 = (num % 5 == 0);

    // An imperfect number satisfies (div_by_2 OR div_by_5) AND NOT (div_by_2 AND div_by_5).
    // This is equivalent to (div_by_2 XOR div_by_5).
    return div_by_2 != div_by_5;
}

void solve() {
    int N;
    cin >> N; // Read N using cin

    // Case 0: N itself is an imperfect number.
    if (is_imperfect(N)) {
        cout << 0 << "\n"; // Output 0
    } else {
        // Case 1: Check if N-1 or N+1 is an imperfect number.
        // The is_imperfect function correctly handles N-1 being 0 (e.g., for N=1).
        bool found_at_diff_1 = false;
        if (is_imperfect(N - 1)) {
            found_at_diff_1 = true;
        }
        if (is_imperfect(N + 1)) {
            found_at_diff_1 = true;
        }

        if (found_at_diff_1) {
            cout << 1 << "\n"; // Output 1
        } else {
            // Case 2: If N, N-1, N+1 are not imperfect, the minimum difference must be 2.
            // As analyzed, this scenario only occurs when N is a multiple of 10.
            // For such N, N-2 and N+2 are always imperfect.
            cout << 2 << "\n"; // Output 2
        }
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases
    cin >> T;
    while (T--) {
        solve(); // Solve each test case
    }

    return 0;
}