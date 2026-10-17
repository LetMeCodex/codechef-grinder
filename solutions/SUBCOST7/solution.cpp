#include <bits/stdc++.h> // Includes common libraries like iostream, algorithm, etc.

using namespace std; // Allows direct use of standard library elements like cin, cout, min

void solve() {
    int N, X, Y;
    // Read the number of months (N), cost for first 3 months (X), and cost for following months (Y)
    cin >> N >> X >> Y;

    long long total_cost = 0; // Use long long to prevent potential overflow, though int would suffice for given constraints.

    // Calculate the number of months that fall under the 'X' rate (first 3 months)
    int months_at_X_rate = min(N, 3);
    // Add the cost for these months to the total
    total_cost += (long long)months_at_X_rate * X;

    // Calculate the number of remaining months that fall under the 'Y' rate
    int months_at_Y_rate = N - months_at_X_rate;
    // Add the cost for these months to the total
    total_cost += (long long)months_at_Y_rate * Y;

    // Output the calculated total cost followed by a newline
    cout << total_cost << "\n";
}

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    // Read the number of test cases
    cin >> T;
    // Loop through each test case
    while (T--) {
        solve(); // Call the solve function for each test case
    }

    return 0; // Indicate successful execution
}