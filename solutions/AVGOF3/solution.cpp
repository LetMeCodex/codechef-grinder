#include <bits/stdc++.h> // Includes all standard libraries, as requested.

// Using the standard namespace for convenience, as requested.
using namespace std;

// Function to solve a single test case.
void solve() {
    int X; // Chef's favourite number.
    cin >> X; // Read X from input.

    // We need to find three distinct integers A1, A2, A3 such that:
    // 1. (A1 + A2 + A3) / 3 = X  =>  A1 + A2 + A3 = 3 * X
    // 2. 1 <= A1, A2, A3 <= 1000
    // 3. A1, A2, A3 are distinct.

    // A simple and effective strategy is to pick numbers symmetrically
    // around the target average X.
    // Let's choose A1 = X - 1, A2 = X, A3 = X + 1.

    // Verification of conditions:
    // 1. Sum: (X - 1) + X + (X + 1) = 3X. The mean is (3X) / 3 = X. (Satisfied)
    // 2. Distinctness: X - 1, X, and X + 1 are consecutive integers,
    //    thus they are always distinct. (Satisfied)
    // 3. Range (1 <= A_i <= 1000):
    //    The problem constraints state 2 <= X <= 100.
    //    - Smallest possible X is 2:
    //      A1 = 2 - 1 = 1
    //      A2 = 2
    //      A3 = 2 + 1 = 3
    //      All values (1, 2, 3) are within [1, 1000].
    //    - Largest possible X is 100:
    //      A1 = 100 - 1 = 99
    //      A2 = 100
    //      A3 = 100 + 1 = 101
    //      All values (99, 100, 101) are within [1, 1000].
    //    Since X is always between 2 and 100, the generated A_i values
    //    will always be between 1 and 101, which perfectly fits the [1, 1000] range. (Satisfied)

    // Since all conditions are met, this construction is valid.
    // Output the three integers separated by spaces, followed by a newline.
    cout << X - 1 << " " << X << " " << X + 1 << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Number of test cases.
    cin >> T; // Read the number of test cases.

    // Loop through each test case.
    while (T--) {
        solve(); // Call the solve function for each test case.
    }

    return 0; // Indicate successful execution.
}