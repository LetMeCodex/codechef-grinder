#include <bits/stdc++.h> // Includes most standard libraries

using namespace std; // Use the standard namespace

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T; // Read the number of test cases

    while (T--) { // Loop T times, decrementing T in each iteration
        int N;
        cin >> N; // Read the number of glasses sold for the current test case

        // Calculate the profit based on the derived formula:
        // Total income per glass = 50 coins.
        // Total expenses percentage = 20% (sugarcane) + 20% (salt/mint) + 30% (rent) = 70% of total income.
        // Profit percentage = 100% (total income) - 70% (total expenses) = 30% of total income.
        // Profit per glass = 30% of 50 coins = 0.30 * 50 = 15 coins.
        // Total profit for N glasses = 15 * N.
        int profit = 15 * N;

        cout << profit << "\n"; // Output the calculated profit followed by a newline
    }

    return 0; // Indicate successful execution
}