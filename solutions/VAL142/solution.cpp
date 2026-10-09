#include <bits/stdc++.h> // Includes most standard libraries, as requested
using namespace std;     // Uses the standard namespace, as requested

int main() {
    // Optimize C++ standard streams for faster input/output.
    // This is a common practice in competitive programming.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Variable to store the number of test cases
    cin >> T; // Read the number of test cases

    // Loop through each test case
    while (T--) {
        int X; // Variable to store Chef's budget for the current test case
        cin >> X; // Read the budget X

        // To satisfy the conditions with the minimum possible total cost,
        // Chef should choose the smallest possible positive integer for the first gift,
        // which is 1.
        // For subsequent gifts, to minimize their values while satisfying
        // "at least twice the value of previous gift", Chef should choose
        // exactly twice the value of the previous gift.
        //
        // Let the gift values be g1, g2, g3, g4, g5, g6, g7.
        // g1 = 1 (smallest positive integer)
        // g2 = 2 * g1 = 2
        // g3 = 2 * g2 = 4
        // g4 = 2 * g3 = 8
        // g5 = 2 * g4 = 16
        // g6 = 2 * g5 = 32
        // g7 = 2 * g6 = 64
        //
        // The total minimum cost for these 7 gifts would be:
        // 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127.
        //
        // If Chef's budget X is less than 127, it's impossible to buy 7 gifts
        // satisfying the conditions, because even the absolute minimum cost
        // exceeds the budget.
        // If Chef's budget X is 127 or more, he can always buy the gifts
        // with values [1, 2, 4, 8, 16, 32, 64], which cost exactly 127.
        // Since 127 <= X, this plan is valid.
        // The remaining budget (X - 127) can be used to increase the value
        // of the last gift (or any other gift) if desired, but it's not
        // necessary to find such a specific plan, only to determine if one exists.

        if (X >= 127) {
            cout << "YES\n"; // If budget is sufficient, print YES
        } else {
            cout << "NO\n"; // Otherwise, print NO
        }
    }

    return 0; // Indicate successful execution
}