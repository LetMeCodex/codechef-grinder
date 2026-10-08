#include <iostream> // Required for standard input/output operations (cin, cout)

// It's common in competitive programming to include <bits/stdc++.h>
// and use 'using namespace std;', but for clarity and minimal includes,
// iostream is sufficient here.
using namespace std;

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z; // Read initial price X, price increase Y, and earnings Z

    // The condition for Chef to buy the GPU in 'm' months is:
    // Chef's total coins after 'm' months >= GPU price after 'm' months
    // m * Z >= X + m * Y

    // Rearranging the inequality:
    // m * Z - m * Y >= X
    // m * (Z - Y) >= X

    // Case 1: Chef earns more than the price increases (Z > Y)
    // In this scenario, (Z - Y) is a positive value.
    // We can divide by (Z - Y) to find the minimum 'm':
    // m >= X / (Z - Y)
    // Since 'm' must be an integer, we need the smallest integer 'm' that satisfies this.
    // This is equivalent to ceil(X / (Z - Y)).
    // For positive integers A and B, ceil(A/B) can be calculated as (A + B - 1) / B using integer division.
    if (Z > Y) {
        int diff = Z - Y; // The net gain in buying power per month
        // Calculate ceil(X / diff)
        int months = (X + diff - 1) / diff;
        cout << months << "\n";
    }
    // Case 2: Chef earns less than or equal to the price increase (Z <= Y)
    // If Z = Y, the inequality becomes m * 0 >= X, or 0 >= X. Since X >= 1, this is never true.
    // If Z < Y, then (Z - Y) is negative. The inequality becomes m * (negative_value) >= X.
    // Dividing by a negative value reverses the inequality: m <= X / (negative_value).
    // Since X is positive and (Z - Y) is negative, X / (Z - Y) is a negative value.
    // So, m must be less than or equal to a negative value.
    // However, 'm' must be at least 1 (number of months). This is a contradiction.
    // In both subcases (Z = Y or Z < Y), Chef will never be able to buy the GPU.
    else { // Z <= Y
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin from cout and disables synchronization with C's stdio library,
    // leading to faster input/output operations.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases
    while (T--) { // Loop T times, decrementing T each iteration
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}