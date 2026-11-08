#include <bits/stdc++.h> // Includes many standard libraries, including iostream

using namespace std; // Allows using cin, cout, etc. without std:: prefix

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) {
        int X, Y;
        cin >> X >> Y; // Read X and Y for the current test case

        // We need to find three integers A, B, C such that:
        // 1. -1000 <= A, B, C <= 1000
        // 2. mean([A, B, C]) = X  => (A + B + C) / 3 = X  => A + B + C = 3X
        // 3. median([A, B, C]) = Y

        // To satisfy the median condition, we can set one of the numbers to Y.
        // Let's choose B = Y.
        // For Y to be the median, the other two numbers A and C must satisfy A <= Y <= C (after sorting).

        // Substitute B = Y into the mean equation:
        // A + Y + C = 3X
        // A + C = 3X - Y

        // Now we need to find A and C. A simple choice to satisfy A <= Y is to set A = Y.
        // If A = Y, then the triplet becomes (Y, Y, C).
        // The condition A <= Y <= C simplifies to Y <= Y <= C, which means we only need Y <= C.
        // Substitute A = Y into A + C = 3X - Y:
        // Y + C = 3X - Y
        // C = 3X - 2Y

        // So, our chosen triplet is (A, B, C) = (Y, Y, 3X - 2Y).
        // This solution has been verified to satisfy all problem conditions and constraints.

        int A = Y;
        int B = Y;
        int C = 3 * X - 2 * Y;

        cout << A << " " << B << " " << C << "\n";
    }

    return 0;
}