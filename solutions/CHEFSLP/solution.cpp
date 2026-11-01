#include <bits/stdc++.h> // Includes common headers like iostream and algorithm

// Using the standard namespace to avoid writing std:: repeatedly
using namespace std;

int main() {
    // Optimize C++ standard streams for faster input/output.
    // ios_base::sync_with_stdio(false) unties C++ streams from C standard streams.
    // cin.tie(NULL) prevents cin from flushing cout before each input operation.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Declare an integer variable T for the number of test cases
    cin >> T; // Read the number of test cases

    // Loop T times, once for each test case
    while (T--) {
        int N, L, X; // Declare integer variables for N, L, and X
        cin >> N >> L >> X; // Read N, L, and X for the current test case

        // Calculate the number of right slippers.
        // Total slippers (N) - Left slippers (L) = Right slippers.
        int num_right_slippers = N - L;

        // The maximum number of pairs that can be formed is limited by the
        // minimum of available left slippers and available right slippers.
        int max_pairs = min(L, num_right_slippers);

        // Calculate the total amount of rupees Chef can get.
        // This is the maximum number of pairs multiplied by the price per pair (X).
        // The maximum possible value (500 * 1000 = 500,000) fits within an 'int'.
        int total_rupees = max_pairs * X;

        // Output the result for the current test case, followed by a newline.
        cout << total_rupees << "\n";
    }

    return 0; // Indicate successful program execution
}