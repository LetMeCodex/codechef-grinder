#include <bits/stdc++.h> // Includes most standard libraries

// Using the standard namespace to avoid prefixing std::
using namespace std;

int main() {
    // Optimize C++ standard streams for competitive programming.
    // This unties cin/cout from the C standard I/O library and
    // prevents cin from flushing cout before each input operation,
    // leading to faster input/output.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int C, X, Y; // Declare integer variables for C, X, and Y
        cin >> C >> X >> Y; // Read C, X, and Y for the current test case

        // Calculate the number of chocolates Chef needs to buy.
        // Chef needs C chocolates in total, and already has X.
        // So, Chef needs to buy C - X more chocolates.
        int chocolates_to_buy = C - X;

        // Calculate the total cost.
        // Each chocolate costs Y rupees.
        // So, the total cost is (chocolates_to_buy * Y).
        int total_cost = chocolates_to_buy * Y;

        // Output the minimum money Chef needs to spend, followed by a newline.
        cout << total_cost << "\n";
    }

    return 0; // Indicate successful program execution
}