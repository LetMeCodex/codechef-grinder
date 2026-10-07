#include <bits/stdc++.h> // Required include for competitive programming

// Required using namespace std;
using namespace std;

int main() {
    // Required fast I/O setup for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Declare three integer variables:
    // A: the cost of the socks
    // X: the amount of money Chef has saved up
    // Y: the additional money Chef received from his parents
    int A, X, Y;

    // Read the three space-separated integers from the first and only line of input.
    // The problem statement explicitly describes a single line of input for A, X, and Y,
    // implying a single test case. Therefore, a loop for multiple test cases is not used
    // as it is not "requested by the problem statement" itself.
    cin >> A >> X >> Y;

    // Calculate the total amount of money Chef has after receiving money from his parents.
    // The constraints (1 <= A, X, Y <= 100) ensure that X + Y will not exceed 200,
    // which easily fits within an 'int' data type, so no overflow issues.
    int total_money_chef_has = X + Y;

    // Compare Chef's total money with the cost of the socks.
    // If Chef's total money is greater than or equal to the cost of the socks,
    // he can afford them.
    if (total_money_chef_has >= A) {
        // Output "YES" followed by a newline character.
        // The problem states that output can be in any case, but "YES" is standard.
        cout << "YES\n";
    } else {
        // Otherwise, Chef cannot afford the socks.
        // Output "NO" followed by a newline character.
        // The problem states that output can be in any case, but "NO" is standard.
        cout << "NO\n";
    }

    // Return 0 to indicate successful execution.
    return 0;
}