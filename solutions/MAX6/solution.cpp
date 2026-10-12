#include <bits/stdc++.h> // Required header for competitive programming

// Use the standard namespace for convenience
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This unties cin from cout and prevents synchronization with C's stdio.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the total number of runs scored.
    // The problem statement indicates a single test case: "The first and only line of input contains X".
    int X;
    cin >> X;

    // To maximize the number of sixers, we assume that all other balls (non-sixers)
    // score the minimum possible runs (0 runs).
    // Let S be the number of sixers.
    // Each sixer contributes 6 runs.
    // The total runs from S sixers is 6 * S.
    // This value cannot exceed the total runs X.
    // So, 6 * S <= X.
    // To maximize S, we take the largest integer S that satisfies this:
    // S = floor(X / 6).
    //
    // We also need to ensure that the remaining runs (X - 6 * S) can be scored
    // from the remaining balls (100 - S), with each of those balls scoring
    // between 0 and 4 runs.
    //
    // The minimum runs from (100 - S) balls is 0.
    // The maximum runs from (100 - S) balls is 4 * (100 - S).
    // So, 0 <= X - 6 * S <= 4 * (100 - S).
    //
    // The left inequality (X - 6 * S >= 0) is satisfied because S = floor(X / 6).
    // The right inequality (X - 6 * S <= 4 * (100 - S)) simplifies to S >= (X - 400) / 2.
    //
    // Given the constraints 100 <= X <= 200:
    // - The maximum value for floor(X / 6) is floor(200 / 6) = 33.
    // - The minimum value for ceil((X - 400) / 2) is ceil((100 - 400) / 2) = ceil(-150) = -150.
    //
    // Since floor(X / 6) (which is at least 16 for X=100) is always greater than or equal
    // to ceil((X - 400) / 2) (which is always negative for the given X range),
    // the condition S >= (X - 400) / 2 is always met by S = floor(X / 6).
    //
    // Therefore, the maximum number of sixers is simply X / 6 (using integer division).
    cout << X / 6 << "\n";

    return 0;
}