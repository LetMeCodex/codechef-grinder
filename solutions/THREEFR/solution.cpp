#include <bits/stdc++.h> // Includes all standard libraries

// Use the standard namespace to avoid writing std:: repeatedly
using namespace std;

// Function to solve a single test case
void solve() {
    int X, Y, Z;
    // Read the three absolute differences
    cin >> X >> Y >> Z;

    // The core condition for the statements to be true is that the sum of the
    // actual differences (x, y, z) must be zero: x + y + z = 0.
    // We are given X = |x|, Y = |y|, Z = |z|. We need to determine if there
    // exist choices for the signs of x, y, z such that their sum is zero.
    //
    // Since X, Y, Z are positive (1 <= X, Y, Z <= 1000), the only way for
    // x + y + z = 0 is if some values are positive and some are negative.
    // This leads to three possible scenarios:
    // 1. Two values are positive, one is negative. E.g., x=X, y=Y, z=-Z.
    //    This implies X + Y - Z = 0, which simplifies to X + Y = Z.
    // 2. One value is positive, two are negative. E.g., x=X, y=-Y, z=-Z.
    //    This implies X - Y - Z = 0, which simplifies to X = Y + Z.
    //
    // Considering all permutations for which value is positive/negative,
    // the conditions boil down to checking if any one of X, Y, Z is equal
    // to the sum of the other two.
    if (X + Y == Z || X + Z == Y || Y + Z == X) {
        cout << "yes\n";
    } else {
        cout << "no\n";
    }
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve();
    }

    return 0; // Indicate successful execution
}